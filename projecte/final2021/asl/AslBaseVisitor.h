
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AslVisitor.h"


/**
 * This class provides an empty implementation of AslVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AslBaseVisitor : public AslVisitor {
public:

  virtual antlrcpp::Any visitProgram(AslParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(AslParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_params(AslParser::Func_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarations(AslParser::DeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_decl(AslParser::Variable_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_decl(AslParser::Array_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(AslParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasic_type(AslParser::Basic_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(AslParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignStmt(AslParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(AslParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(AslParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcCall(AslParser::ProcCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(AslParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadStmt(AslParser::ReadStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteExpr(AslParser::WriteExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteString(AslParser::WriteStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMap(AslParser::MapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeft_expr(AslParser::Left_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean(AslParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprIdent(AslParser::ExprIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic(AslParser::ArithmeticContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational(AslParser::RelationalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary(AslParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCall(AslParser::FuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPower(AslParser::PowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesis(AslParser::ParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(AslParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdent(AslParser::IdentContext *ctx) override {
    return visitChildren(ctx);
  }


};

