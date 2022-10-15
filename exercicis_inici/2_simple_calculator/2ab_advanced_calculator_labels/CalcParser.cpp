
// Generated from Calc.g4 by ANTLR 4.7.2


#include "CalcVisitor.h"

#include "CalcParser.h"


using namespace antlrcpp;
using namespace antlr4;

CalcParser::CalcParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CalcParser::~CalcParser() {
  delete _interpreter;
}

std::string CalcParser::getGrammarFileName() const {
  return "Calc.g4";
}

const std::vector<std::string>& CalcParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CalcParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

CalcParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcParser::ProgContext::EOF() {
  return getToken(CalcParser::EOF, 0);
}

std::vector<CalcParser::StatContext *> CalcParser::ProgContext::stat() {
  return getRuleContexts<CalcParser::StatContext>();
}

CalcParser::StatContext* CalcParser::ProgContext::stat(size_t i) {
  return getRuleContext<CalcParser::StatContext>(i);
}


size_t CalcParser::ProgContext::getRuleIndex() const {
  return CalcParser::RuleProg;
}

antlrcpp::Any CalcParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ProgContext* CalcParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, CalcParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(8);
      stat();
      setState(11); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CalcParser::MAX)
      | (1ULL << CalcParser::MIN)
      | (1ULL << CalcParser::SUMLIST)
      | (1ULL << CalcParser::SUB)
      | (1ULL << CalcParser::ID)
      | (1ULL << CalcParser::INT)
      | (1ULL << CalcParser::NEWLINE))) != 0));
    setState(13);
    match(CalcParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

CalcParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::StatContext::getRuleIndex() const {
  return CalcParser::RuleStat;
}

void CalcParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::BlankContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::BlankContext::BlankContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::PrintExprContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::PrintExprContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::AssignContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::ExprContext* CalcParser::AssignContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::AssignContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
CalcParser::StatContext* CalcParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, CalcParser::RuleStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(24);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::PrintExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(15);
      expr(0);
      setState(16);
      match(CalcParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(18);
      match(CalcParser::ID);
      setState(19);
      match(CalcParser::T__0);
      setState(20);
      expr(0);
      setState(21);
      match(CalcParser::NEWLINE);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::BlankContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(23);
      match(CalcParser::NEWLINE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CalcParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::ExprContext::getRuleIndex() const {
  return CalcParser::RuleExpr;
}

void CalcParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DivContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::DivContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::DivContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::DivContext::DIV() {
  return getToken(CalcParser::DIV, 0);
}

CalcParser::DivContext::DivContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::DivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::SubContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::SubContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::SubContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::SubContext::SubContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::SubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::MinContext::MIN() {
  return getToken(CalcParser::MIN, 0);
}

CalcParser::List_of_exprContext* CalcParser::MinContext::list_of_expr() {
  return getRuleContext<CalcParser::List_of_exprContext>(0);
}

CalcParser::MinContext::MinContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::MinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProdContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::ProdContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ProdContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::ProdContext::MUL() {
  return getToken(CalcParser::MUL, 0);
}

CalcParser::ProdContext::ProdContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::ProdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::FactContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::FactContext::FACT() {
  return getToken(CalcParser::FACT, 0);
}

CalcParser::FactContext::FactContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::FactContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitFact(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MaxContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::MaxContext::MAX() {
  return getToken(CalcParser::MAX, 0);
}

CalcParser::List_of_exprContext* CalcParser::MaxContext::list_of_expr() {
  return getRuleContext<CalcParser::List_of_exprContext>(0);
}

CalcParser::MaxContext::MaxContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::MaxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMax(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IdContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubuniContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::SubuniContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::ExprContext* CalcParser::SubuniContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

CalcParser::SubuniContext::SubuniContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::SubuniContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitSubuni(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IntContext::INT() {
  return getToken(CalcParser::INT, 0);
}

CalcParser::IntContext::IntContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::PlusContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::PlusContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::PlusContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

CalcParser::PlusContext::PlusContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::PlusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPlus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SumlistContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::SumlistContext::SUMLIST() {
  return getToken(CalcParser::SUMLIST, 0);
}

CalcParser::List_of_exprContext* CalcParser::SumlistContext::list_of_expr() {
  return getRuleContext<CalcParser::List_of_exprContext>(0);
}

CalcParser::SumlistContext::SumlistContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::SumlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitSumlist(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ExprContext* CalcParser::expr() {
   return expr(0);
}

CalcParser::ExprContext* CalcParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalcParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CalcParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::SUB: {
        _localctx = _tracker.createInstance<SubuniContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(27);
        match(CalcParser::SUB);
        setState(28);
        expr(11);
        break;
      }

      case CalcParser::MAX: {
        _localctx = _tracker.createInstance<MaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(29);
        match(CalcParser::MAX);
        setState(30);
        match(CalcParser::T__1);
        setState(31);
        list_of_expr();
        setState(32);
        match(CalcParser::T__2);
        break;
      }

      case CalcParser::MIN: {
        _localctx = _tracker.createInstance<MinContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(34);
        match(CalcParser::MIN);
        setState(35);
        match(CalcParser::T__1);
        setState(36);
        list_of_expr();
        setState(37);
        match(CalcParser::T__2);
        break;
      }

      case CalcParser::SUMLIST: {
        _localctx = _tracker.createInstance<SumlistContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(39);
        match(CalcParser::SUMLIST);
        setState(40);
        match(CalcParser::T__1);
        setState(41);
        list_of_expr();
        setState(42);
        match(CalcParser::T__2);
        break;
      }

      case CalcParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(44);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        _localctx = _tracker.createInstance<IdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(45);
        match(CalcParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(64);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(62);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ProdContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(48);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(49);
          match(CalcParser::MUL);
          setState(50);
          expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(51);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(52);
          match(CalcParser::DIV);
          setState(53);
          expr(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PlusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(54);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(55);
          match(CalcParser::ADD);
          setState(56);
          expr(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<SubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(57);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(58);
          match(CalcParser::SUB);
          setState(59);
          expr(4);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<FactContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(60);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(61);
          match(CalcParser::FACT);
          break;
        }

        } 
      }
      setState(66);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- List_of_exprContext ------------------------------------------------------------------

CalcParser::List_of_exprContext::List_of_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CalcParser::ExprContext *> CalcParser::List_of_exprContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::List_of_exprContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}


size_t CalcParser::List_of_exprContext::getRuleIndex() const {
  return CalcParser::RuleList_of_expr;
}

antlrcpp::Any CalcParser::List_of_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitList_of_expr(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::List_of_exprContext* CalcParser::list_of_expr() {
  List_of_exprContext *_localctx = _tracker.createInstance<List_of_exprContext>(_ctx, getState());
  enterRule(_localctx, 6, CalcParser::RuleList_of_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::T__2: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case CalcParser::MAX:
      case CalcParser::MIN:
      case CalcParser::SUMLIST:
      case CalcParser::SUB:
      case CalcParser::ID:
      case CalcParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(68);
        expr(0);
        setState(73);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CalcParser::T__3) {
          setState(69);
          match(CalcParser::T__3);
          setState(70);
          expr(0);
          setState(75);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CalcParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalcParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CalcParser::_decisionToDFA;
atn::PredictionContextCache CalcParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CalcParser::_atn;
std::vector<uint16_t> CalcParser::_serializedATN;

std::vector<std::string> CalcParser::_ruleNames = {
  "prog", "stat", "expr", "list_of_expr"
};

std::vector<std::string> CalcParser::_literalNames = {
  "", "'='", "'('", "')'", "','", "'>'", "'>='", "'max'", "'min'", "'add'", 
  "'!'", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> CalcParser::_symbolicNames = {
  "", "", "", "", "", "GT", "GE", "MAX", "MIN", "SUMLIST", "FACT", "MUL", 
  "DIV", "ADD", "SUB", "ID", "INT", "NEWLINE", "WS"
};

dfa::Vocabulary CalcParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CalcParser::_tokenNames;

CalcParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x14, 0x51, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x6, 0x2, 0xc, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0xd, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1b, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x31, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x41, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x44, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x4a, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4d, 0xb, 0x5, 0x5, 0x5, 0x4f, 0xa, 0x5, 
    0x3, 0x5, 0x2, 0x3, 0x6, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x2, 0x2, 0x5b, 
    0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x4e, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x5, 0x4, 
    0x3, 0x2, 0xb, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x7, 0x2, 0x2, 0x3, 0x10, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x12, 0x5, 0x6, 0x4, 0x2, 0x12, 0x13, 0x7, 0x13, 0x2, 
    0x2, 0x13, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 0x11, 0x2, 0x2, 
    0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 0x16, 0x17, 0x5, 0x6, 0x4, 0x2, 0x17, 
    0x18, 0x7, 0x13, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1b, 
    0x7, 0x13, 0x2, 0x2, 0x1a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x14, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x1d, 0x8, 0x4, 0x1, 0x2, 0x1d, 0x1e, 0x7, 0x10, 0x2, 
    0x2, 0x1e, 0x31, 0x5, 0x6, 0x4, 0xd, 0x1f, 0x20, 0x7, 0x9, 0x2, 0x2, 
    0x20, 0x21, 0x7, 0x4, 0x2, 0x2, 0x21, 0x22, 0x5, 0x8, 0x5, 0x2, 0x22, 
    0x23, 0x7, 0x5, 0x2, 0x2, 0x23, 0x31, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 
    0x7, 0xa, 0x2, 0x2, 0x25, 0x26, 0x7, 0x4, 0x2, 0x2, 0x26, 0x27, 0x5, 
    0x8, 0x5, 0x2, 0x27, 0x28, 0x7, 0x5, 0x2, 0x2, 0x28, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x7, 0xb, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x4, 0x2, 
    0x2, 0x2b, 0x2c, 0x5, 0x8, 0x5, 0x2, 0x2c, 0x2d, 0x7, 0x5, 0x2, 0x2, 
    0x2d, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x7, 0x12, 0x2, 0x2, 0x2f, 
    0x31, 0x7, 0x11, 0x2, 0x2, 0x30, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x24, 0x3, 0x2, 0x2, 0x2, 0x30, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x42, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0xc, 0x8, 0x2, 
    0x2, 0x33, 0x34, 0x7, 0xd, 0x2, 0x2, 0x34, 0x41, 0x5, 0x6, 0x4, 0x9, 
    0x35, 0x36, 0xc, 0x7, 0x2, 0x2, 0x36, 0x37, 0x7, 0xe, 0x2, 0x2, 0x37, 
    0x41, 0x5, 0x6, 0x4, 0x8, 0x38, 0x39, 0xc, 0x6, 0x2, 0x2, 0x39, 0x3a, 
    0x7, 0xf, 0x2, 0x2, 0x3a, 0x41, 0x5, 0x6, 0x4, 0x7, 0x3b, 0x3c, 0xc, 
    0x5, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x10, 0x2, 0x2, 0x3d, 0x41, 0x5, 0x6, 
    0x4, 0x6, 0x3e, 0x3f, 0xc, 0x9, 0x2, 0x2, 0x3f, 0x41, 0x7, 0xc, 0x2, 
    0x2, 0x40, 0x32, 0x3, 0x2, 0x2, 0x2, 0x40, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x38, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x4b, 0x5, 0x6, 0x4, 0x2, 0x47, 0x48, 0x7, 0x6, 0x2, 
    0x2, 0x48, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9, 0xd, 0x1a, 0x30, 
    0x40, 0x42, 0x4b, 0x4e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CalcParser::Initializer CalcParser::_init;
