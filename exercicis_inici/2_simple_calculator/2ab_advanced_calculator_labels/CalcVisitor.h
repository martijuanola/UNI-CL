
// Generated from Calc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalcParser.
 */
class  CalcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalcParser.
   */
    virtual antlrcpp::Any visitProg(CalcParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitPrintExpr(CalcParser::PrintExprContext *context) = 0;

    virtual antlrcpp::Any visitAssign(CalcParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitBlank(CalcParser::BlankContext *context) = 0;

    virtual antlrcpp::Any visitDiv(CalcParser::DivContext *context) = 0;

    virtual antlrcpp::Any visitSub(CalcParser::SubContext *context) = 0;

    virtual antlrcpp::Any visitMin(CalcParser::MinContext *context) = 0;

    virtual antlrcpp::Any visitProd(CalcParser::ProdContext *context) = 0;

    virtual antlrcpp::Any visitFact(CalcParser::FactContext *context) = 0;

    virtual antlrcpp::Any visitMax(CalcParser::MaxContext *context) = 0;

    virtual antlrcpp::Any visitId(CalcParser::IdContext *context) = 0;

    virtual antlrcpp::Any visitSubuni(CalcParser::SubuniContext *context) = 0;

    virtual antlrcpp::Any visitInt(CalcParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitPlus(CalcParser::PlusContext *context) = 0;

    virtual antlrcpp::Any visitSumlist(CalcParser::SumlistContext *context) = 0;

    virtual antlrcpp::Any visitList_of_expr(CalcParser::List_of_exprContext *context) = 0;


};

