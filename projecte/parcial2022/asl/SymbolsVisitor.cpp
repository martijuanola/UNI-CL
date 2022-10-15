//////////////////////////////////////////////////////////////////////
//
//    SymbolsVisitor - Walk the parser tree to register symbols
//                     for the Asl programming language
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

#include "SymbolsVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>
#include <vector>

#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
SymbolsVisitor::SymbolsVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations,
                               SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Methods to visit each kind of node:
//
antlrcpp::Any SymbolsVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = Symbols.pushNewScope(SymTable::GLOBAL_SCOPE_NAME);
  putScopeDecor(ctx, sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  //Symbols.print(); //REMOVE AFTER DEBUGING
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  
  std::string funcName = ctx->ID()->getText();
  SymTable::ScopeId sc = Symbols.pushNewScope(funcName);
  putScopeDecor(ctx, sc);
  if(ctx->func_params()) visit(ctx->func_params());
  visit(ctx->declarations());
		//Symbols.print();
		//std::cout << std::endl;
  Symbols.popScope();
  
  std::string ident = ctx->ID()->getText();
  if (Symbols.findInCurrentScope(ident)) {
    Errors.declaredIdent(ctx->ID());
  }
  else {
    std::vector<TypesMgr::TypeId> lParamsTy; // PARAMETER types
    if (ctx->func_params() != NULL) {
		for (auto i : ctx->func_params()->type()) {
		   lParamsTy.push_back(getTypeDecor(i));
		}
    }
    
    TypesMgr::TypeId tRet; // RETURN type
    if (ctx->type() != NULL) {
      visit(ctx->type());
      tRet = getTypeDecor(ctx->type());
    }
    else tRet = Types.createVoidTy();

    TypesMgr::TypeId tFunc = Types.createFunctionTy(lParamsTy, tRet);
    Symbols.addFunction(ident, tFunc);
  }
 
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitFunc_params(AslParser::Func_paramsContext *ctx) {
   DEBUG_ENTER();
	int count = 0;
	for(auto i : ctx->ID()){
		std::string id = i->getText();
		visit(ctx->type(count));
		TypesMgr::TypeId t = getTypeDecor(ctx->type(count));
		Symbols.addParameter(id,t);
		count++;
	}
	DEBUG_EXIT();
	return 0;
}

antlrcpp::Any SymbolsVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->type());
  TypesMgr::TypeId t = getTypeDecor(ctx->type());
  for(auto i : ctx->ID()){
	  std::string ident = i->getText();
	  if (Symbols.findInCurrentScope(ident)) Errors.declaredIdent(i);
	  //if (Symbols.findInStack(ident)) Errors.declaredIdent(i); //VIGILAR AIXÒ!
	  else Symbols.addLocalVar(ident, t);
  } 
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitArray_decl(AslParser::Array_declContext *ctx) {
  DEBUG_ENTER();
  unsigned int size = std::stoi(ctx->INTVAL()->getText());
  visit(ctx->basic_type());
  TypesMgr::TypeId elemType = getTypeDecor(ctx->basic_type());
  TypesMgr::TypeId t = Types.createArrayTy(size,elemType);
  putTypeDecor(ctx, t);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitStruct_decl(AslParser::Struct_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId newStruct = Types.createEmptyStructTy();
  int i = 0;
  for(auto field : ctx->field()) {
	  visit(field);
	  visit(ctx->basic_type(i));
	  TypesMgr::TypeId fieldType = getTypeDecor(ctx->basic_type(i));
	  if(not Types.existStructField(newStruct, field->getText())) {
		  Types.addStructField(newStruct, field->getText(), fieldType);
	  }
	  else {
		Errors.structRedeclaresFieldName(ctx);
	  }
	  i++;
  }
  putTypeDecor(ctx, newStruct);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
  if(ctx->basic_type()) {
	  visit(ctx->basic_type());
	  putTypeDecor(ctx, getTypeDecor(ctx->basic_type()));
  }
  else if(ctx->array_decl()){
	  visit(ctx->array_decl());
	  putTypeDecor(ctx, getTypeDecor(ctx->array_decl()));
  }
  else if(ctx->struct_decl()) {
	  visit(ctx->struct_decl());
	  putTypeDecor(ctx, getTypeDecor(ctx->struct_decl()));
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any SymbolsVisitor::visitBasic_type(AslParser::Basic_typeContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  if (ctx->INT()) t = Types.createIntegerTy();
  else if (ctx->FLOAT()) t = Types.createFloatTy();
  else if (ctx->BOOL()) t = Types.createBooleanTy();
  else if (ctx->CHAR()) t = Types.createCharacterTy();
  putTypeDecor(ctx, t);
  DEBUG_EXIT();
  return 0;
}

 antlrcpp::Any SymbolsVisitor::visitStatements(AslParser::StatementsContext *ctx) {
   DEBUG_ENTER();
   antlrcpp::Any r = visitChildren(ctx);
   DEBUG_EXIT();
   return r;
 }

 antlrcpp::Any SymbolsVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
   DEBUG_ENTER();
   antlrcpp::Any r = visitChildren(ctx);
   DEBUG_EXIT();
   return r;
 }
 
 antlrcpp::Any SymbolsVisitor::visitMapeig(AslParser::MapeigContext *ctx) {
   DEBUG_ENTER();
   antlrcpp::Any r = visitChildren(ctx);
   DEBUG_EXIT();
   return r;
 }

antlrcpp::Any SymbolsVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
 DEBUG_ENTER();
 antlrcpp::Any r = visitChildren(ctx);
 DEBUG_EXIT();
 return r;
}

antlrcpp::Any SymbolsVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
 DEBUG_ENTER();
 antlrcpp::Any r = visitChildren(ctx);
 DEBUG_EXIT();
 return r;
}
	  // a partir d'aqui estava comentat
antlrcpp::Any SymbolsVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitStructIdent(AslParser::StructIdentContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

antlrcpp::Any SymbolsVisitor::visitField(AslParser::FieldContext *ctx) {
  DEBUG_ENTER();
  antlrcpp::Any r = visitChildren(ctx);
  DEBUG_EXIT();
  return r;
}

//fins aqui

// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId SymbolsVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId SymbolsVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope and Type
void SymbolsVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void SymbolsVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
