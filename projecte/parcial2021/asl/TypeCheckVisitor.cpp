//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
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

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
                                   SymTable       & Symbols,
                                   TreeDecoration & Decorations,
                                   SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  // Symbols.print();
  
  //recalculate return type for returnvisitor
  if (ctx->type() != NULL) setCurrentFunctionTy(getTypeDecor(ctx->type()));
  else setCurrentFunctionTy(Types.createVoidTy());
  
  
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

// hauria d'anar func params?????

//els 3 de sota estaven comentats
antlrcpp::Any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
	DEBUG_ENTER();
	antlrcpp::Any r = visitChildren(ctx);
	DEBUG_EXIT();
	return r;
}

antlrcpp::Any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
	DEBUG_ENTER();
	antlrcpp::Any r = visitChildren(ctx);
	DEBUG_EXIT();
	return r;
}

antlrcpp::Any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
   DEBUG_ENTER();
   antlrcpp::Any r = visitChildren(ctx);
   DEBUG_EXIT();
   return r;
}
//fins aquí

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
} 

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  
  //REMOVE AFTER DEBUGING
  /*std::cout << "(";
  Types.dump(t1,std::cout);
  std::cout << " , ";
  Types.dump(t2,std::cout);
  std::cout << ")" << std::endl;*/
  
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) Errors.booleanRequired(ctx);    
  visit(ctx->statements(0));
  if(ctx->statements(1)) visit(ctx->statements(1));
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  
  int nparams;
  int nargs;
  bool error = false; // si t1 no és funció o si nparams != nargs
  
  if(not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
    Errors.isNotCallable(ctx->ident());
    error = true;
  }
  
  if(Types.isFunctionTy(t1)){
	  nparams = Types.getNumOfParameters(t1);
	  nargs = ctx->expr().size();
	  if(nparams != nargs) {
		  Errors.numberOfParameters(ctx->ident());
		  error = true;
	  }
  }

  //Comprovar els tipus de paràmetres
  int count = 0;
  for (auto expr : ctx->expr()) { 
	visit(expr);
	
	//Si hi ha algun error no es fa type check de paràmetres
	if(not error and not Types.isErrorTy(t1)) {
		TypesMgr::TypeId tp = Types.getParameterType(t1,count);
		TypesMgr::TypeId te = getTypeDecor(expr);
		
		if(not Types.isErrorTy(tp) and not Types.isErrorTy(te) and not Types.equalTypes(tp,te)) { 
			if(not (Types.isFloatTy(tp) and Types.isIntegerTy(te))) {
			Errors.incompatibleParameter(expr, count+1, ctx->ident());
			}
		}
	}
	
	count++;
  }
  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t1 = getCurrentFunctionTy();
  
  if(ctx->expr()) {//returns something
	  visit(ctx->expr());
	  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
	  
	  if(not Types.isErrorTy(t1) and not Types.isErrorTy(t2) and not Types.equalTypes(t1,t2)) {
	    //cas especial amb return de int com a float(es permet)
	    if(not (Types.isFloatTy(t1) and Types.isIntegerTy(t2)))
	    Errors.incompatibleReturn(ctx->RETURN());
	}
  }
  else {//void
	  if(not Types.isErrorTy(t1) and not Types.isVoidTy(t1))
		Errors.incompatibleReturn(ctx->RETURN());
  }
  DEBUG_EXIT();
  return 0;	
}

antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}


antlrcpp::Any TypeCheckVisitor::visitPack(AslParser::PackContext *ctx) {
	DEBUG_ENTER();
	
	antlrcpp::Any r = visitChildren(ctx);
	
	TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
	if(not Types.isErrorTy(t1) and (not Types.isArrayTy(t1))) {
		Errors.packUnpackWithNonArray(ctx);
	}
	
	if(Types.isArrayTy(t1)) {
		int nExpr = ctx->expr().size();
		int arraySize = Types.getArraySize(t1);
		if(nExpr != arraySize) {
			Errors.packUnpackNumberOfItemsMismatch(ctx);
		}
		
		TypesMgr::TypeId t2 = Types.getArrayElemType(t1);
		int count = 0;
		for(auto expr : ctx->expr()) {
			TypesMgr::TypeId t3 = getTypeDecor(expr);
			if(not Types.isErrorTy(t2) and not Types.isErrorTy(t3) and not Types.equalTypes(t2,t3)) { 
				if(not (Types.isFloatTy(t2) and Types.isIntegerTy(t3))) {
				Errors.packUnpackIncompatibleTypes(ctx, count+1);
				}
			}	
			count++;
		}
	}
	
	DEBUG_EXIT();
	return r;
}

antlrcpp::Any TypeCheckVisitor::visitUnpack(AslParser::UnpackContext *ctx) {
	DEBUG_ENTER();
	
	antlrcpp::Any r = visitChildren(ctx);
	
	TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
	if(not Types.isErrorTy(t1) and (not Types.isArrayTy(t1))) {
		Errors.packUnpackWithNonArray(ctx);
	}
	
	if(Types.isArrayTy(t1)) {
		int nExpr = ctx->left_expr().size();
		int arraySize = Types.getArraySize(t1);
		if(nExpr != arraySize) {
			Errors.packUnpackNumberOfItemsMismatch(ctx);
		}
		
		TypesMgr::TypeId t2 = Types.getArrayElemType(t1);
		int count = 0;
		for(auto expr : ctx->left_expr()) {
			TypesMgr::TypeId t3 = getTypeDecor(expr);
			if(not Types.isErrorTy(t2) and not Types.isErrorTy(t3) and not Types.equalTypes(t2,t3)) { 
				if(not (Types.isFloatTy(t3) and Types.isIntegerTy(t2))) {
				Errors.packUnpackIncompatibleTypes(ctx, count+1);
				}
			}	
			count++;
		}
	}
	
	DEBUG_EXIT();
	return r;
}

antlrcpp::Any TypeCheckVisitor::visitLeftExprIdent(AslParser::LeftExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if(ctx->expr()) { //Array
	  visit(ctx->expr());
	  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
	  
	  //No és tipus array
	  if(not Types.isErrorTy(t1) and (not Types.isArrayTy(t1))) {
	    Errors.nonArrayInArrayAccess(ctx);
	  }
	  else if(not Types.isErrorTy(t1)) putTypeDecor(ctx, Types.getArrayElemType(t1));
	  //s'ha de comprovar que no sigui error que sino peta
	  
	  
	  //Expressió no és INT
	  if((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2)))
	    Errors.nonIntegerIndexInArrayAccess(ctx->expr());

	  putIsLValueDecor(ctx, true);
  }
  else {//Variable o funció
	  putTypeDecor(ctx, t1);
	  //pots ser que sigui un ident de funció, s'ha de comprovar que sigui Lvalue
	  bool b1 = getIsLValueDecor(ctx->ident());
	  putIsLValueDecor(ctx,b1);
  }
  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitLeftTuple(AslParser::LeftTupleContext *ctx) {
  DEBUG_ENTER();
  
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if(not Types.isErrorTy(t1) and (not Types.isTupleTy(t1))) {
	  Errors.nonTupleInTupleAccess(ctx);
  }
  
  if(Types.isTupleTy(t1)) {
	  int args = Types.getTupleSize(t1);
	  int pos = std::stoi(ctx->INTVAL()->getText());
	  if(pos > args-1) {
		  Errors.nonExistentFieldInTuple(ctx);
	  }
	  else {
		  TypesMgr::TypeId t2 = Types.getTupleFieldType(t1, pos);
		  putTypeDecor(ctx, t2);
		  putIsLValueDecor(ctx,true);
	  }
  }
  
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitTuple(AslParser::TupleContext *ctx) {
  DEBUG_ENTER();
  
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if(not Types.isErrorTy(t1) and (not Types.isTupleTy(t1))) {
	  Errors.nonTupleInTupleAccess(ctx);
  }
  
  if(Types.isTupleTy(t1)) {
	  int args = Types.getTupleSize(t1);
	  int pos = std::stoi(ctx->INTVAL()->getText());
	  if(pos > args-1) {
		  Errors.nonExistentFieldInTuple(ctx);
	  }
	  else {
		  TypesMgr::TypeId t2 = Types.getTupleFieldType(t1, pos);
		  putTypeDecor(ctx, t2);
	  }
  }
  putIsLValueDecor(ctx,false);
  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  
  if(ctx->NOT()) { // NOT
	  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))))
		Errors.incompatibleOperator(ctx->op);
	  TypesMgr::TypeId t = Types.createBooleanTy();
	  putTypeDecor(ctx, t);
  }
  else { // MINUS or PLUS
	  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))))
		Errors.incompatibleOperator(ctx->op);
	  if(Types.isNumericTy(t1)) putTypeDecor(ctx, t1);
	  else {
		  TypesMgr::TypeId t = Types.createIntegerTy();
		  putTypeDecor(ctx, t);
	  }
  }
  
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  
  //El modul només funciona amb INTS
  if(ctx->MOD() and (Types.isFloatTy(t1) or Types.isFloatTy(t2))) {
	  Errors.incompatibleOperator(ctx->op);
  }
  
  TypesMgr::TypeId t;
  if(Types.isFloatTy(t1) or Types.isFloatTy(t2)) t = Types.createFloatTy();
  else t = Types.createIntegerTy();
  
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
     ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);
    
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  if(ctx->INTVAL()) t = Types.createIntegerTy();
  else if(ctx->FLOATVAL()) t = Types.createFloatTy();
  else if(ctx->CHARVAL()) t = Types.createCharacterTy();
  else if(ctx->BOOLVAL()) t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFuncCall(AslParser::FuncCallContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  
  int nparams;
  int nargs;
  bool error = false; // si t1 no és funció o si nparams != nargs
  
  //Mirar si és funció
  if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
    Errors.isNotCallable(ctx->ident());
    error = true;
  }

  
  if(Types.isFunctionTy(t1)) {
	TypesMgr::TypeId tr = Types.getFuncReturnType(t1);
    if(Types.isVoidTy(tr)) Errors.isNotFunction(ctx->ident());
    else putTypeDecor(ctx, tr);
	putIsLValueDecor(ctx, false);
	
	  nparams = Types.getNumOfParameters(t1);
	  nargs = ctx->expr().size();
	  if(nparams != nargs) {
		  Errors.numberOfParameters(ctx->ident());
		  error = true;
	  }
  }

  //Comprovar els tipus de paràmetres
  int count = 0;
  for (auto expr : ctx->expr()) { 
	visit(expr);
	
	//Si no concorden nombre de parametres no es fa el type check
	if(not error and not Types.isErrorTy(t1)) {
		TypesMgr::TypeId tp = Types.getParameterType(t1,count);
		TypesMgr::TypeId te = getTypeDecor(expr);
		
		if(not Types.isErrorTy(tp) and not Types.isErrorTy(te) and not Types.equalTypes(tp,te)) { 
			if(not (Types.isFloatTy(tp) and Types.isIntegerTy(te))) {
			Errors.incompatibleParameter(expr, count+1, ctx->ident());
			}
		}
	}
	
	count++;
  }

  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if(ctx->expr()) {
	  visit(ctx->expr());
	  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
	  
	  //No és tipus array
	  if(not Types.isErrorTy(t1) and (not Types.isArrayTy(t1))) {
	    Errors.nonArrayInArrayAccess(ctx);
	  }
	  else if(not Types.isErrorTy(t1)) putTypeDecor(ctx, Types.getArrayElemType(t1));
	  //s'ha de comprovar que no sigui error que sino peta
	  
	  //Expressió no és INT
	  if((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2)))
	    Errors.nonIntegerIndexInArrayAccess(ctx->expr());

	  putIsLValueDecor(ctx, true);
  }
  else {
	  putTypeDecor(ctx, t1);
	  bool b1 = getIsLValueDecor(ctx->ident());
	  putIsLValueDecor(ctx, b1);
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, false);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
