
// Generated from Expr.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterS(ExprParser::SContext *ctx) = 0;
  virtual void exitS(ExprParser::SContext *ctx) = 0;

  virtual void enterE(ExprParser::EContext *ctx) = 0;
  virtual void exitE(ExprParser::EContext *ctx) = 0;


};

