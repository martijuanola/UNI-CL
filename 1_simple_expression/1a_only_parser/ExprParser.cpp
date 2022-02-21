
// Generated from Expr.g4 by ANTLR 4.9.2



#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SContext ------------------------------------------------------------------

ExprParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::EContext* ExprParser::SContext::e() {
  return getRuleContext<ExprParser::EContext>(0);
}


size_t ExprParser::SContext::getRuleIndex() const {
  return ExprParser::RuleS;
}


ExprParser::SContext* ExprParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    e(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EContext ------------------------------------------------------------------

ExprParser::EContext::EContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::EContext *> ExprParser::EContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::EContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::EContext::INT() {
  return getToken(ExprParser::INT, 0);
}


size_t ExprParser::EContext::getRuleIndex() const {
  return ExprParser::RuleE;
}



ExprParser::EContext* ExprParser::e() {
   return e(0);
}

ExprParser::EContext* ExprParser::e(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::EContext *_localctx = _tracker.createInstance<EContext>(_ctx, parentState);
  ExprParser::EContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleE, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(15);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__0: {
        setState(7);
        match(ExprParser::T__0);
        setState(8);
        match(ExprParser::T__1);
        setState(9);
        e(0);
        setState(10);
        match(ExprParser::T__2);
        setState(11);
        e(0);
        setState(12);
        match(ExprParser::T__3);
        break;
      }

      case ExprParser::INT: {
        setState(14);
        match(ExprParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(28);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(26);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleE);
          setState(17);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(18);
          match(ExprParser::T__4);
          setState(19);
          e(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleE);
          setState(20);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(21);
          match(ExprParser::T__5);
          setState(22);
          e(4);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<EContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleE);
          setState(23);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(24);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__6

          || _la == ExprParser::T__7)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(25);
          e(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(30);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return eSempred(dynamic_cast<EContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::eSempred(EContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "s", "e"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'MAX'", "'('", "','", "')'", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "INT", "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xc, 0x22, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x12, 0xa, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x1d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
       0x20, 0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 0x3, 
       0x3, 0x2, 0x9, 0xa, 0x2, 0x23, 0x2, 0x6, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 0x7, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x8, 0x3, 0x1, 0x2, 0x9, 0xa, 0x7, 
       0x3, 0x2, 0x2, 0xa, 0xb, 0x7, 0x4, 0x2, 0x2, 0xb, 0xc, 0x5, 0x4, 
       0x3, 0x2, 0xc, 0xd, 0x7, 0x5, 0x2, 0x2, 0xd, 0xe, 0x5, 0x4, 0x3, 
       0x2, 0xe, 0xf, 0x7, 0x6, 0x2, 0x2, 0xf, 0x12, 0x3, 0x2, 0x2, 0x2, 
       0x10, 0x12, 0x7, 0xb, 0x2, 0x2, 0x11, 0x8, 0x3, 0x2, 0x2, 0x2, 0x11, 
       0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 
       0xc, 0x6, 0x2, 0x2, 0x14, 0x15, 0x7, 0x7, 0x2, 0x2, 0x15, 0x1d, 0x5, 
       0x4, 0x3, 0x7, 0x16, 0x17, 0xc, 0x5, 0x2, 0x2, 0x17, 0x18, 0x7, 0x8, 
       0x2, 0x2, 0x18, 0x1d, 0x5, 0x4, 0x3, 0x6, 0x19, 0x1a, 0xc, 0x4, 0x2, 
       0x2, 0x1a, 0x1b, 0x9, 0x2, 0x2, 0x2, 0x1b, 0x1d, 0x5, 0x4, 0x3, 0x5, 
       0x1c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x16, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0x19, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x5, 0x11, 0x1c, 0x1e, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
