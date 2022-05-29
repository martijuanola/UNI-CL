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


/* ---------- FUNCTIONS & PARAMETERS & DECLARATIONS ---------- */


antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  subroutine subr(ctx->ID()->getText());
  codeCounters.reset();

  // RETURN VARIABLE
  if(ctx->type()) subr.add_param("_result");

  // PARAMS
  if(ctx->func_params()){
    std::vector<std::string> lparams = visit(ctx->func_params());
    for (auto & oneparam : lparams) {
      subr.add_param(oneparam);
    }
  }

  // VAR DECLARATIONS
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & onevar : lvars) {
    subr.add_var(onevar);
  }

  // STATEMENTS
  instructionList && code = visit(ctx->statements());

  // RETURN INSTRUCTION (only if void)
  if(not ctx->type()) code = code || instruction(instruction::RETURN());

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

//ARRAY DECLARATION??

//TYPE??

//BASIC TYPE??


/* ---------- STATEMENT ---------- */


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
  instructionList code;
  
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  
  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  instructionList &     code2 = codAtsE2.code;
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  
  code = code1 || code2;
  
  //Cas d'assignació d'arrays
  if(Types.isArrayTy(t1) and Types.isArrayTy(t2)) {
	  // TEMPS
	  std::string tempI = "%"+codeCounters.newTEMP();	//Variable del bucle
	  std::string tempL = "%"+codeCounters.newTEMP();	//Mida Arrays
	  std::string tempV = "%"+codeCounters.newTEMP();	//Auxiliar per valor
	  std::string tempINCR = "%"+codeCounters.newTEMP();//Increment(+1)
	  std::string tempCOMP = "%"+codeCounters.newTEMP();//Resultat comparació
	  
	  // LABELS
	  std::string label = codeCounters.newLabelWHILE();
	  std::string labelWhile = "while"+label;
	  std::string labelEndWhile = "endwhile"+label;
	  
    // CODE TO COPY EACH ELEMENT OF THE ARRAYS
	  code = code
		|| instruction::ILOAD(tempI,"0")
		|| instruction::ILOAD(tempL,std::to_string(Types.getArraySize(t1)))
		|| instruction::ILOAD(tempINCR,"1")
		
		|| instruction::LABEL(labelWhile)
		|| instruction::LT(tempCOMP,tempI,tempL)
		|| instruction::FJUMP(tempCOMP, labelEndWhile)
		
		|| instruction::LOADX(tempV,addr2,tempI)
		|| instruction::XLOAD(addr1,tempI,tempV)
		|| instruction::ADD(tempI,tempI,tempINCR)
		
		|| instruction::UJUMP(labelWhile)
		|| instruction::LABEL(labelEndWhile);
  }
  else {
	  std::string temp = "%"+codeCounters.newTEMP();
	  if(Types.isFloatTy(t1) and Types.isIntegerTy(t2)) {
		  code = code || instruction::FLOAT(temp,addr2);
	  }
	  else temp = addr2; // if the float change is not
	  
	  if(offs1 != "") code = code || instruction::XLOAD(addr1, offs1, temp);
	  else code = code || instruction::LOAD(addr1, temp);
  }  
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;

  // BOOLEAN EXPRESSION
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    codeEXPR = codAtsE.code;
  
  // IF STATEMENT AND LABEL
  instructionList &&   codeSTMS1 = visit(ctx->statements(0));
  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;
  
  if(ctx->statements().size() > 1) {
	  // ELSE STATEMENT AND LABEL
	  instructionList &&   codeSTMS2 = visit(ctx->statements(1));
	  std::string labelElse = "else"+label;
	  code = codeEXPR
		|| instruction::FJUMP(addr1, labelElse)
		|| codeSTMS1
		|| instruction::UJUMP(labelEndIf)
		|| instruction::LABEL(labelElse)
		|| codeSTMS2
		|| instruction::LABEL(labelEndIf);
  }
  else {// NO ELSE CLAUSE
	  code = codeEXPR
		|| instruction::FJUMP(addr1, labelEndIf)
		|| codeSTMS1
		|| instruction::LABEL(labelEndIf);
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  
  // BOOLEAN EXPRESSION
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    codeExpr = codAtsE.code;

  // WHILE STATEMENTS AND LABELS
  instructionList &&   codeStatements = visit(ctx->statements());
  std::string label = codeCounters.newLabelWHILE();
  std::string labelBeginWhile = "beginwhile"+label;
  std::string labelEndWhile = "endwhile"+label;

  code = 
       instruction::LABEL(labelBeginWhile)
    || codeExpr
    || instruction::FJUMP(addr1, labelEndWhile)
    || codeStatements
    || instruction::UJUMP(labelBeginWhile)
    || instruction::LABEL(labelEndWhile);

  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  instructionList & code = codAts.code;
  
  // PUSH SPACE FOR RETURN VALUE IF NON-VOID FUNCTION (even if result is not used)
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());
  if(not Types.isVoidFunction(t)) code = code || instruction::PUSH();
  
  // PUSH ALL PARAMETERS
  unsigned int i = 0; // PARAMETER INDEX
  for( auto expr : ctx->expr()) {
    // PARAMETER i
    CodeAttribs && codAts2 = visit(expr);
    code = code || codAts2.code;
    std::string addr = codAts2.addr;

    TypesMgr::TypeId p = Types.getParameterType(t, i);
    TypesMgr::TypeId e = getTypeDecor(expr);
    // INT TO FLOAT CASE
    if(Types.isFloatTy(p) and not Types.isFloatTy(e)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp,addr);
      addr = temp;
    } // ARRAY AS PARAMETER(THE ADRESS IS NEEDED)
    else if(Types.isArrayTy(p) and not Symbols.isParameterClass(ctx->expr(i)->getText())){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp,addr);
      addr = temp;
    }

    code = code || instruction::PUSH(addr);
    ++i;
  }
  
  // CALL FUNCTION
  std::string name = ctx->ident()->getText();
  code = code || instruction::CALL(name); 

  // POP ALL PARAMETERS
  for( long unsigned int i = 0; i<ctx->expr().size(); ++i){
    code = code || instruction::POP();
  }
  
  // POP RETURN VALUE SPACE
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
  code = code || instruction::RETURN();
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  // LEFT EXPRESSION TO SAFE VALUE
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

antlrcpp::Any CodeGenVisitor::visitMap(AslParser::MapContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  
  CodeAttribs     && codAt1 = visit(ctx->ident(0));
  std::string     &   addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident(0));
  TypesMgr::TypeId ta1 = Types.getArrayElemType(t1);
  
  CodeAttribs     && codAt2 = visit(ctx->ident(1));
  std::string     &   addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  TypesMgr::TypeId t2 = getTypeDecor(ctx->ident(1));
  TypesMgr::TypeId ta2 = Types.getArrayElemType(t2);
  
  CodeAttribs     && codAt3 = visit(ctx->ident(2));
  instructionList &   code3 = codAt1.code;
  TypesMgr::TypeId t3 = getTypeDecor(ctx->ident(2));
  TypesMgr::TypeId tp = Types.getParameterType(t3,0);
  TypesMgr::TypeId tr = Types.getFuncReturnType(t3);
  
  std::string funcName = ctx->ident(2)->getText();
  std::string length = std::to_string(Types.getArraySize(t1));
  
  std::string tempIncr = "%"+codeCounters.newTEMP();
  std::string tempI = "%"+codeCounters.newTEMP();
  std::string tempC = "%"+codeCounters.newTEMP();
  std::string tempL = "%"+codeCounters.newTEMP();
  std::string tempIN = "%"+codeCounters.newTEMP();
  std::string tempOUT = "%"+codeCounters.newTEMP();
  
  std::string tempAux1 = "%"+codeCounters.newTEMP();
  std::string tempAux2 = "%"+codeCounters.newTEMP();
  
  std::string label = codeCounters.newLabelWHILE();
  std::string labelBeginMap = "beginMap"+label;
  std::string labelEndMap = "endMap"+label;
  
  
  code = code1 || code2 || code3
    || instruction::ILOAD(tempIncr,"1")
    || instruction::ILOAD(tempI,"0")
    || instruction::ILOAD(tempL,length)
    
    || instruction::LABEL(labelBeginMap)
    || instruction::LT(tempC,tempI,tempL)
    || instruction::FJUMP(tempC,labelEndMap)
    
    || instruction::PUSH()
    || instruction::LOADX(tempIN,addr1,tempI);
    
  if(Types.isIntegerTy(ta1) and Types.isFloatTy(tp)) {
    code = code || instruction::FLOAT(tempAux1,tempIN);
  }
  else tempAux1 = tempIN;
    
  code = code
    || instruction::PUSH(tempAux1)
    || instruction::CALL(funcName)
    || instruction::POP()
    || instruction::POP(tempOUT);
    
  if(Types.isIntegerTy(tr) and Types.isFloatTy(ta2)) {
    code = code || instruction::FLOAT(tempAux2,tempOUT);
  }
  else tempAux2 = tempOUT;
  
  code = code
    || instruction::XLOAD(addr2,tempI,tempAux2)
    
    || instruction::ADD(tempI,tempI,tempIncr)
    || instruction::UJUMP(labelBeginMap)
    || instruction::LABEL(labelEndMap)
    ;
  
  DEBUG_EXIT();
  return code;
}


/* ---------- LEFT EXPRESSION ---------- */


//s'ha de retornar code + addres(array) + offset(nombre de posicions)
antlrcpp::Any CodeGenVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {   // not implemented
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident()); 
  instructionList &   code = codAts.code;
  
  // ARRAYS
  if(ctx->expr()){
    CodeAttribs && codAts2 = visit(ctx->expr());
    code = code || codAts2.code;
    codAts.offs = codAts2.addr;
  }
  
  DEBUG_EXIT();
  return codAts;
}


/* ---------- EXPRESSION ---------- */


antlrcpp::Any CodeGenVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx) {   
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->expr());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitPower(AslParser::PowerContext *ctx) {   
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  
  
  instructionList code = code1 || code2;
  
  std::string tempIncr = "%"+codeCounters.newTEMP();
  std::string tempI = "%"+codeCounters.newTEMP();
  std::string tempV = "%"+codeCounters.newTEMP();
  std::string tempC = "%"+codeCounters.newTEMP();
  
  std::string tempFinal = "%"+codeCounters.newTEMP();
  
  std::string label = codeCounters.newLabelWHILE();
  std::string labelBeginPower = "beginPower"+label;
  std::string labelEndPower = "endPower"+label;

  if(Types.isIntegerTy(t1)) {
    code = code
      || instruction::ILOAD(tempIncr,"1")
      || instruction::ILOAD(tempI,"0")
      || instruction::ILOAD(tempV,"1")
      
      || instruction::LABEL(labelBeginPower)
      || instruction::LT(tempC,tempI,addr2)
      || instruction::FJUMP(tempC,labelEndPower)
      
      || instruction::MUL(tempV,tempV,addr1)
      || instruction::ADD(tempI,tempI,tempIncr)
      || instruction::UJUMP(labelBeginPower)
      || instruction::LABEL(labelEndPower)
      || instruction::FLOAT(tempFinal,tempV)
      ;
  }
  else {
    code = code
      || instruction::ILOAD(tempIncr,"1")
      || instruction::ILOAD(tempI,"0")
      || instruction::FLOAD(tempV,"1.0")
      
      || instruction::LABEL(labelBeginPower)
      || instruction::LT(tempC,tempI,addr2)
      || instruction::FJUMP(tempC,labelEndPower)
      
      || instruction::FMUL(tempV,tempV,addr1)
      || instruction::ADD(tempI,tempI,tempIncr)
      || instruction::UJUMP(labelBeginPower)
      || instruction::LABEL(labelEndPower)
      ;
      tempFinal = tempV;
  }
  
  CodeAttribs codAts(tempFinal, "", code);
  
  DEBUG_EXIT();
  return codAts;
}


antlrcpp::Any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx) {  
  DEBUG_ENTER();
  CodeAttribs     && codAt = visit(ctx->expr());
  std::string         addr = codAt.addr;
  instructionList &   code = codAt.code;
  
  if(ctx->PLUS()) return codAt;
	  
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->MINUS()){  
		TypesMgr::TypeId t = getTypeDecor(ctx->expr());
		if (Types.isFloatTy(t))
		  code = code || instruction::FNEG(temp, addr);
		else 
		  code = code || instruction::NEG(temp, addr);
  }
  else if (ctx->NOT()) {
	  code = code || instruction::NOT(temp, addr);
  }

  CodeAttribs codAts(temp, "", code);
  
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {  
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  
  std::string temp = "%"+codeCounters.newTEMP();

  // FLOAT CASE
  if(Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    // FLOAT AND INT(int need to be converted to float)
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
      std::cout << "mod case for floats!!!'??" << std::endl;
      exit(0);
    }
    else if (ctx->PLUS())
      code = code || instruction::FADD(temp, addr1, addr2);
    else if (ctx->MINUS())
      code = code || instruction::FSUB(temp, addr1, addr2);
  } // INTs CASE
  else {
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->MOD()) {
      std::string tempDIV = "%"+codeCounters.newTEMP();
      std::string tempMULT = "%"+codeCounters.newTEMP();
      code = code
		    || instruction::DIV(tempDIV, addr1, addr2)
		    || instruction::MUL(tempMULT, tempDIV, addr2)
		    || instruction::SUB(temp, addr1, tempMULT);
    }
    else if (ctx->PLUS())
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
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));

  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  std::string temp = "%"+codeCounters.newTEMP();

  // FLOAT CASE
  if(Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    // FLOAT AND INT(int need to be converted to float)
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
    }
    else if (ctx->LT())
      code = code || instruction::FLT(temp, addr1, addr2);
    else if (ctx->GT())
      code = code || instruction::FLT(temp, addr2, addr1);
    else if (ctx->LE())
      code = code || instruction::FLE(temp, addr1, addr2);
    else if (ctx->GE())
      code = code || instruction::FLE(temp, addr2, addr1);
  }
  else {// INTs CASE
    if (ctx->EQUAL())
      code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NEQ()){
      code = code || instruction::EQ(temp, addr1, addr2);
      code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->LT())
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
  
  if(ctx->CHARVAL()) code = instruction::CHLOAD(temp, ctx->getText().substr(1,ctx->getText().size()-2));
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
  TypesMgr::TypeId t = getTypeDecor(ctx->ident());

  // PUSH SPACE FOR RETURN VALUE
  code = code || instruction::PUSH();

  // PUSH ALL PARAMETERS
  unsigned int i = 0; // PARAMETER INDEX
  for( auto expr : ctx->expr()){
    CodeAttribs && codAts2 = visit(expr);
    code = code || codAts2.code;
    std::string addr = codAts2.addr;

    TypesMgr::TypeId p = Types.getParameterType(t, i);
    TypesMgr::TypeId e = getTypeDecor(expr);
    // INT TO FLOAT CASE
    if(Types.isFloatTy(p) and not Types.isFloatTy(e)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp,addr);
      addr = temp;
    } //ARRAY AS PARAMETER(THE ADRESS IS NEEDED)
    else if(Types.isArrayTy(p) and not Symbols.isParameterClass(ctx->expr(i)->getText())){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp,addr);
      addr = temp;
    }
    code = code || instruction::PUSH(addr);
    ++i;
  }

  // CALL FUNCTION
  std::string name = ctx->ident()->getText();
  code = code || instruction::CALL(name); 

  // POP ALL PARAMETERS
  for( long unsigned int i = 0; i<ctx->expr().size(); ++i){
    code = code || instruction::POP();
  }

  // GET RETURN VALUE SPACE
  std::string temp = "%"+codeCounters.newTEMP();
  code = code || instruction::POP(temp);
  codAts.addr = temp;

  DEBUG_EXIT();
  return codAts;
}

//returns value, not adress
antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {  
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  instructionList & code = codAts.code;
  
  if(ctx->expr()){
    CodeAttribs && codAts2 = visit(ctx->expr());
    code = code || codAts2.code;
    
  	std::string temp = "%"+codeCounters.newTEMP();
  	code = code || instruction::LOADX(temp, codAts.addr, codAts2.addr);
  	codAts.addr = temp;
  }
  DEBUG_EXIT();
  return codAts;
}


/* ---------- IDENTIFIER ---------- */


//in charge of doing a LOAD if it contains an adress(for arrays as reference)
antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  instructionList & code = codAts.code;
  
  TypesMgr::TypeId t = getTypeDecor(ctx);
  if(Types.isArrayTy(t) and Symbols.isParameterClass(ctx->ID()->getText())) {
	  std::string temp = "%"+codeCounters.newTEMP();
	  code = code || instruction::LOAD(temp, codAts.addr);
	  codAts.addr = temp;
  }
  
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
