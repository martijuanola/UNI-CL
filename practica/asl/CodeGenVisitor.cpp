//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
//
//    Copyright (C) 2017-2022  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId CodeGenVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void CodeGenVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {  
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    subroutine subr = visit(ctxFunc);
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  subroutine subr(ctx->ID()->getText());
  codeCounters.reset();

  if(ctx->type()) subr.add_param("_result");

  // params
  if(ctx->func_params()){
    std::vector<std::string>  lparams = visit(ctx->func_params());
    for (auto & oneparam : lparams) {
      subr.add_param(oneparam);
    }
  }
  // vars
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & onevar : lvars) {
    subr.add_var(onevar);
  }
  instructionList && code = visit(ctx->statements());
  code = code || instruction(instruction::RETURN());
  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}

antlrcpp::Any CodeGenVisitor::visitFunc_params(AslParser::Func_paramsContext *ctx) {
  DEBUG_ENTER();
  std::vector<std::string> params;
  for (auto & id : ctx->ID()) {
    std::string aux = id->getText();
    params.push_back(aux);
  }
  DEBUG_EXIT();
  return params;
}

antlrcpp::Any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;
  for (auto & varDeclCtx : ctx->variable_decl()) {
    std::vector<var> vars = visit(varDeclCtx);
    lvars.insert(lvars.end(), vars.begin(), vars.end());
  }
  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);
  std::vector<var> vars;
  for (auto & id : ctx->ID()) {
    var onevar = var{id->getText(), size};
    vars.push_back(onevar);
  }
  DEBUG_EXIT();
  return vars;
}

antlrcpp::Any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS = visit(stCtx);
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  
  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  instructionList &     code2 = codAtsE2.code;
  
  instructionList code = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  std::string temp = "%"+codeCounters.newTEMP();
  if(Types.isFloatTy(t1) and Types.isIntegerTy(t2)) {
	code = code || instruction::FLOAT(temp,addr2);
  }
  else temp = addr2; //quan no s'ha de fer el canvi
  
  if(offs1 != "") code = code || instruction::XLOAD(addr1, offs1, temp);
  else code = code || instruction::LOAD(addr1, temp);
  
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  //s'ha d'adaptar per l'else. De moment poso statements(1) però faltarà
  //un condicional potser? amb l'altre statements(2)?
  instructionList &&   code2 = visit(ctx->statements(0));
  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;
  code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::LABEL(labelEndIf);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  //s'ha d'adaptar per l'else. De moment poso statements(1) però faltarà
  //un condicional potser? amb l'altre statements(2)?
  instructionList &&   code2 = visit(ctx->statements());
  std::string label = codeCounters.newLabelWHILE();
  std::string labelBeginWhile = "beginwhile"+label;
  std::string labelEndWhile = "endwhile"+label;
  code = instruction::LABEL(labelBeginWhile) || 
         code1 || instruction::FJUMP(addr1, labelEndWhile) ||
         code2 || instruction::UJUMP(labelBeginWhile) ||
         instruction::LABEL(labelEndWhile);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  instructionList & code = codAts.code;
  
  //Es guarda l'espai de return encara que no necessariament es fassi servir(si no és void)
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());
  if(not Types.isVoidFunction(t)) code = code || instruction::PUSH();
  
  unsigned int i = 0;
  for( auto expr : ctx->expr()){
    CodeAttribs && codAts2 = visit(expr);
    code = code || codAts2.code;
    std::string addr = codAts2.addr;

    TypesMgr::TypeId p = Types.getParameterType(t, i);
    TypesMgr::TypeId e = getTypeDecor(expr);
    if(Types.isFloatTy(p) and not Types.isFloatTy(e)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp,addr);
      addr = temp;
    }
    else if(Types.isArrayTy(p)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp,addr);
      addr = temp;
    }

    code = code || instruction::PUSH(addr);
    ++i;
  }
  
  std::string name = ctx->ident()->getText();
  code = code || instruction::CALL(name); 
  for( long unsigned int i = 0; i<ctx->expr().size(); ++i){
    code = code || instruction::POP();
  }
  
  //s'allibera l'espai del return si hi era
  if(not Types.isVoidFunction(t)) code = code || instruction::POP();
  
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  if(ctx->expr()) {
    CodeAttribs     && codAt1 = visit(ctx->expr());
    std::string         addr1 = codAt1.addr;
    instructionList &   code1 = codAt1.code;
    code = code1 || instruction::LOAD("_result", addr1);
  }
  DEBUG_EXIT();
  return code;
}


antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAts = visit(ctx->left_expr());
  std::string          addr1 = codAts.addr;
  std::string          offs1 = codAts.offs;
  instructionList &    code1 = codAts.code;
  
  TypesMgr::TypeId tid = getTypeDecor(ctx->left_expr());
  
  std::string temp = "%"+codeCounters.newTEMP();
  if(Types.isIntegerTy(tid) or Types.isBooleanTy(tid)) code1 = code1 || instruction::READI(temp);
  else if(Types.isFloatTy(tid)) code1 = code1 || instruction::READF(temp);
  else if(Types.isCharacterTy(tid)) code1 = code1 || instruction::READC(temp);
  else {
	  std::cout << "Type error in visitReadStmt" << std::endl;
	  exit(0);
  }
  
  if(offs1 != "") code1 = code1 || instruction::XLOAD(addr1, offs1, temp);
  else code1 = code1 || instruction::LOAD(addr1, temp);
  
  DEBUG_EXIT();
  return code1;
}


antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  // std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  instructionList &    code = code1;
  
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  if(Types.isFloatTy(tid1)) code = code1 || instruction::WRITEF(addr1);
  else if(Types.isCharacterTy(tid1)) code = code1 || instruction::WRITEC(addr1);
  else code = code1 || instruction::WRITEI(addr1);
  
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  code = code || instruction::WRITES(s);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {   // not implemented
  DEBUG_ENTER();
  //s'ha de retornar code + addres(array) + offset(nombre de posicions)
  CodeAttribs && codAts = visit(ctx->ident()); 
  instructionList &   code = codAts.code;
  if(ctx->expr()){//arrays
    CodeAttribs && codAts2 = visit(ctx->expr());
    code = code || codAts2.code;
    
    //mirar si és parametre per referènia
    //Suposaré que si l'ident és paràmetre vol dir que és un punter al vector original
    if(Symbols.isParameterClass(ctx->ident()->getText())) {
		//variable amb adreça de l'array
		std::string temp = "%"+codeCounters.newTEMP();
		code = code
				|| instruction::LOAD(temp, codAts.addr);
		codAts.addr = temp;
	}
    
    codAts.offs = codAts2.addr;
  }
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx) {   
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->expr());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx) {  
  DEBUG_ENTER();
  CodeAttribs     && codAt = visit(ctx->expr());
  std::string         addr = codAt.addr;
  instructionList &   code = codAt.code;
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->MINUS()){
    TypesMgr::TypeId t = getTypeDecor(ctx->expr());
    if (Types.isFloatTy(t))
      code = code || instruction::FNEG(temp, addr);
    else 
      code = code || instruction::NEG(temp, addr);
  }else if (ctx->NOT())
    code = code || instruction::NOT(temp, addr);
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {  
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  
  
  std::string temp = "%"+codeCounters.newTEMP();
  if(Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    if(not Types.isFloatTy(t1)) {
      std::string tempFloat = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempFloat, addr1);
      addr1 = tempFloat;
    }
    else if(not Types.isFloatTy(t2)) {
      std::string tempFloat = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempFloat, addr2);
      addr2 = tempFloat;
    }
    
    if (ctx->MUL())
      code = code || instruction::FMUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::FDIV(temp, addr1, addr2);
    else if (ctx->MOD()){
      std::cout << "mod case" << std::endl;
      exit(0);
    }else if (ctx->PLUS())
      code = code || instruction::FADD(temp, addr1, addr2);
    else if (ctx->MINUS())
      code = code || instruction::FSUB(temp, addr1, addr2);
  }
  else{
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->MOD()){
      std::cout << "mod case" << std::endl;
      exit(0);
    }else if (ctx->PLUS())
      code = code || instruction::ADD(temp, addr1, addr2);
    else if (ctx->MINUS())
      code = code || instruction::SUB(temp, addr1, addr2);
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {   
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if(Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    
    if(not Types.isFloatTy(t1))  {
      std::string tempf1 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempf1,addr1);
      addr1 = tempf1;
    }
    else if(not Types.isFloatTy(t2))  {
      std::string tempf2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempf2,addr2);
      addr2 = tempf2;
    }

    if (ctx->EQUAL())
      code = code || instruction::FEQ(temp, addr1, addr2);
    else if (ctx->NEQ()){
      code = code || instruction::FEQ(temp, addr1, addr2);
      code = code || instruction::NOT(temp, temp);
    }else if (ctx->LT())
      code = code || instruction::FLT(temp, addr1, addr2);
    else if (ctx->GT())
      code = code || instruction::FLT(temp, addr2, addr1);
    else if (ctx->LE())
      code = code || instruction::FLE(temp, addr1, addr2);
    else if (ctx->GE())
      code = code || instruction::FLE(temp, addr2, addr1);
  }
  else{
    if (ctx->EQUAL())
      code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NEQ()){
      code = code || instruction::EQ(temp, addr1, addr2);
      code = code || instruction::NOT(temp, temp);
    }else if (ctx->LT())
      code = code || instruction::LT(temp, addr1, addr2);
    else if (ctx->GT())
      code = code || instruction::LT(temp, addr2, addr1);
    else if (ctx->LE())
      code = code || instruction::LE(temp, addr1, addr2);
    else if (ctx->GE())
      code = code || instruction::LE(temp, addr2, addr1);
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitBoolean(AslParser::BooleanContext *ctx) {   
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->AND())
    code = code || instruction::AND(temp, addr1, addr2);
  else if(ctx->OR())
    code = code || instruction::OR(temp, addr1, addr2);
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  if(ctx->CHARVAL()) code = instruction::CHLOAD(temp, ctx->getText());
  else if(ctx->FLOATVAL()) code = instruction::FLOAD(temp, ctx->getText());
  else {
    if(ctx->getText()=="true") code = instruction::ILOAD(temp, "1");
    else if(ctx->getText()=="false") code = instruction::ILOAD(temp, "0");
    else code = instruction::ILOAD(temp, ctx->getText());
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitFuncCall(AslParser::FuncCallContext *ctx) {   
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident()); 
  instructionList & code = codAts.code;
  code = code || instruction::PUSH();
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());
  unsigned int i = 0;
  for( auto expr : ctx->expr()){
    CodeAttribs && codAts2 = visit(expr);
    code = code || codAts2.code;
    std::string addr = codAts2.addr;

    TypesMgr::TypeId p = Types.getParameterType(t, i);
    TypesMgr::TypeId e = getTypeDecor(expr);
    if(Types.isFloatTy(p) and not Types.isFloatTy(e)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp,addr);
      addr = temp;
    }
    else if(Types.isArrayTy(p)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp,addr);
      addr = temp;
    }

    code = code || instruction::PUSH(addr);
    ++i;
  }
  std::string name = ctx->ident()->getText();
  code = code || instruction::CALL(name); 
  for( long unsigned int i = 0; i<ctx->expr().size(); ++i){
    code = code || instruction::POP();
  }
  std::string temp = "%"+codeCounters.newTEMP();
  code = code || instruction::POP(temp);
  codAts.addr = temp;
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {  
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  instructionList & code = codAts.code;
  if(ctx->expr()){
	// avaluació de l'expressió
    CodeAttribs && codAts2 = visit(ctx->expr());
    code = code || codAts2.code;
    
    //mirar si és parametre per referènia
    //Suposaré que si l'ident és paràmetre vol dir que és un punter al vector original
    if(Symbols.isParameterClass(ctx->ident()->getText())) {
		//variable amb adreça de l'array
		std::string temp1 = "%"+codeCounters.newTEMP();
		std::string temp2 = "%"+codeCounters.newTEMP();
		code = code
				|| instruction::LOAD(temp1, codAts.addr)
				|| instruction::LOADX(temp2, temp1, codAts2.addr);
		codAts.addr = temp2;
	}
	else {
		//array normal
		std::string temp = "%"+codeCounters.newTEMP();
		code = code || instruction::LOADX(temp, codAts.addr, codAts2.addr);
		codAts.addr = temp;
	}
    
  }
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}


// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
                                         const std::string & offs,
                                         instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
