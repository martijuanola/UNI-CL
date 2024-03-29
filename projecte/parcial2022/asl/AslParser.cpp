
// Generated from Asl.g4 by ANTLR 4.7.2


#include "AslVisitor.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

antlrcpp::Any AslParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(30);
      function();
      setState(33); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(35);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::Func_paramsContext* AslParser::FunctionContext::func_params() {
  return getRuleContext<AslParser::Func_paramsContext>(0);
}

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

antlrcpp::Any AslParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(AslParser::FUNC);
    setState(38);
    match(AslParser::ID);
    setState(39);
    match(AslParser::T__0);
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(40);
      func_params();
    }
    setState(43);
    match(AslParser::T__1);
    setState(46);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__2) {
      setState(44);
      match(AslParser::T__2);
      setState(45);
      type();
    }
    setState(48);
    declarations();
    setState(49);
    statements();
    setState(50);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_paramsContext ------------------------------------------------------------------

AslParser::Func_paramsContext::Func_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::Func_paramsContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Func_paramsContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

std::vector<AslParser::TypeContext *> AslParser::Func_paramsContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::Func_paramsContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}


size_t AslParser::Func_paramsContext::getRuleIndex() const {
  return AslParser::RuleFunc_params;
}

antlrcpp::Any AslParser::Func_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunc_params(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Func_paramsContext* AslParser::func_params() {
  Func_paramsContext *_localctx = _tracker.createInstance<Func_paramsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleFunc_params);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(AslParser::ID);
    setState(53);
    match(AslParser::T__2);
    setState(54);
    type();
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(55);
      match(AslParser::T__3);
      setState(56);
      match(AslParser::ID);
      setState(57);
      match(AslParser::T__2);
      setState(58);
      type();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

antlrcpp::Any AslParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(64);
      variable_decl();
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

antlrcpp::Any AslParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(AslParser::VAR);
    setState(71);
    match(AslParser::ID);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(72);
      match(AslParser::T__3);
      setState(73);
      match(AslParser::ID);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(AslParser::T__2);
    setState(80);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_declContext ------------------------------------------------------------------

AslParser::Array_declContext::Array_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Array_declContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::Array_declContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

AslParser::Basic_typeContext* AslParser::Array_declContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}


size_t AslParser::Array_declContext::getRuleIndex() const {
  return AslParser::RuleArray_decl;
}

antlrcpp::Any AslParser::Array_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArray_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Array_declContext* AslParser::array_decl() {
  Array_declContext *_localctx = _tracker.createInstance<Array_declContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleArray_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(AslParser::ARRAY);
    setState(83);
    match(AslParser::T__4);
    setState(84);
    match(AslParser::INTVAL);
    setState(85);
    match(AslParser::T__5);
    setState(86);
    match(AslParser::T__6);
    setState(87);
    basic_type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_declContext ------------------------------------------------------------------

AslParser::Struct_declContext::Struct_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Struct_declContext::STRUCT() {
  return getToken(AslParser::STRUCT, 0);
}

std::vector<AslParser::FieldContext *> AslParser::Struct_declContext::field() {
  return getRuleContexts<AslParser::FieldContext>();
}

AslParser::FieldContext* AslParser::Struct_declContext::field(size_t i) {
  return getRuleContext<AslParser::FieldContext>(i);
}

std::vector<AslParser::Basic_typeContext *> AslParser::Struct_declContext::basic_type() {
  return getRuleContexts<AslParser::Basic_typeContext>();
}

AslParser::Basic_typeContext* AslParser::Struct_declContext::basic_type(size_t i) {
  return getRuleContext<AslParser::Basic_typeContext>(i);
}


size_t AslParser::Struct_declContext::getRuleIndex() const {
  return AslParser::RuleStruct_decl;
}

antlrcpp::Any AslParser::Struct_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStruct_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Struct_declContext* AslParser::struct_decl() {
  Struct_declContext *_localctx = _tracker.createInstance<Struct_declContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleStruct_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(AslParser::STRUCT);
    setState(90);
    match(AslParser::T__7);
    setState(91);
    field();
    setState(92);
    match(AslParser::T__2);
    setState(93);
    basic_type();
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(94);
      match(AslParser::T__3);
      setState(95);
      field();
      setState(96);
      match(AslParser::T__2);
      setState(97);
      basic_type();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(104);
    match(AslParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::Basic_typeContext* AslParser::TypeContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}

AslParser::Array_declContext* AslParser::TypeContext::array_decl() {
  return getRuleContext<AslParser::Array_declContext>(0);
}

AslParser::Struct_declContext* AslParser::TypeContext::struct_decl() {
  return getRuleContext<AslParser::Struct_declContext>(0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

antlrcpp::Any AslParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::INT:
      case AslParser::FLOAT:
      case AslParser::BOOL:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(106);
        basic_type();
        break;
      }

      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(107);
        array_decl();
        break;
      }

      case AslParser::STRUCT: {
        enterOuterAlt(_localctx, 3);
        setState(108);
        struct_decl();
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

//----------------- Basic_typeContext ------------------------------------------------------------------

AslParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Basic_typeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::Basic_typeContext::getRuleIndex() const {
  return AslParser::RuleBasic_type;
}

antlrcpp::Any AslParser::Basic_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBasic_type(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Basic_typeContext* AslParser::basic_type() {
  Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleBasic_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

antlrcpp::Any AslParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(113);
      statement();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ProcCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WriteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ReadStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReadStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MapeigContext ------------------------------------------------------------------

std::vector<AslParser::IdentContext *> AslParser::MapeigContext::ident() {
  return getRuleContexts<AslParser::IdentContext>();
}

AslParser::IdentContext* AslParser::MapeigContext::ident(size_t i) {
  return getRuleContext<AslParser::IdentContext>(i);
}

tree::TerminalNode* AslParser::MapeigContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

std::vector<AslParser::ExprContext *> AslParser::MapeigContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::MapeigContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::MapeigContext::MapeigContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::MapeigContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitMapeig(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WriteStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteString(this);
  else
    return visitor->visitChildren(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(186);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(119);
      left_expr();
      setState(120);
      match(AslParser::ASSIGN);
      setState(121);
      expr(0);
      setState(122);
      match(AslParser::T__9);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::MapeigContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(124);
      ident();
      setState(125);
      match(AslParser::ASSIGN);
      setState(126);
      match(AslParser::T__4);
      setState(127);
      expr(0);
      setState(128);
      match(AslParser::T__10);
      setState(129);
      expr(0);
      setState(130);
      match(AslParser::T__2);
      setState(131);
      expr(0);
      setState(132);
      match(AslParser::T__11);
      setState(133);
      ident();
      setState(134);
      match(AslParser::T__12);
      setState(135);
      ident();
      setState(136);
      match(AslParser::T__5);
      setState(137);
      match(AslParser::T__9);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(139);
      match(AslParser::IF);
      setState(140);
      expr(0);
      setState(141);
      match(AslParser::THEN);
      setState(142);
      statements();
      setState(145);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(143);
        match(AslParser::ELSE);
        setState(144);
        statements();
      }
      setState(147);
      match(AslParser::ENDIF);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(149);
      match(AslParser::WHILE);
      setState(150);
      expr(0);
      setState(151);
      match(AslParser::T__13);
      setState(152);
      statements();
      setState(153);
      match(AslParser::ENDWHILE);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(155);
      ident();
      setState(156);
      match(AslParser::T__0);
      setState(165);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(157);
        expr(0);
        setState(162);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__3) {
          setState(158);
          match(AslParser::T__3);
          setState(159);
          expr(0);
          setState(164);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(167);
      match(AslParser::T__1);
      setState(168);
      match(AslParser::T__9);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(170);
      match(AslParser::RETURN);
      setState(172);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(171);
        expr(0);
      }
      setState(174);
      match(AslParser::T__9);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(175);
      match(AslParser::READ);
      setState(176);
      left_expr();
      setState(177);
      match(AslParser::T__9);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(179);
      match(AslParser::WRITE);
      setState(180);
      expr(0);
      setState(181);
      match(AslParser::T__9);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(183);
      match(AslParser::WRITE);
      setState(184);
      match(AslParser::STRING);
      setState(185);
      match(AslParser::T__9);
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

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::FieldContext* AslParser::Left_exprContext::field() {
  return getRuleContext<AslParser::FieldContext>(0);
}

AslParser::ExprContext* AslParser::Left_exprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

antlrcpp::Any AslParser::Left_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeft_expr(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 22, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(188);
      ident();
      setState(189);
      match(AslParser::T__14);
      setState(190);
      field();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(192);
      ident();
      setState(193);
      match(AslParser::T__4);
      setState(194);
      expr(0);
      setState(195);
      match(AslParser::T__5);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(197);
      ident();
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

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleanContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BooleanContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::ExprIdentContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NEQ() {
  return getToken(AslParser::NEQ, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LE() {
  return getToken(AslParser::LE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GE() {
  return getToken(AslParser::GE, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::RelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

tree::TerminalNode* AslParser::UnaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::UnaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

AslParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::FuncCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::FuncCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::FuncCallContext::FuncCallContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParenthesisContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::StructIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::FieldContext* AslParser::StructIdentContext::field() {
  return getRuleContext<AslParser::FieldContext>(0);
}

AslParser::StructIdentContext::StructIdentContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::StructIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStructIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(201);
      match(AslParser::T__0);
      setState(202);
      expr(0);
      setState(203);
      match(AslParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(205);
      dynamic_cast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS))) != 0))) {
        dynamic_cast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(206);
      expr(11);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(207);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FuncCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(208);
      ident();
      setState(209);
      match(AslParser::T__0);
      setState(218);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(210);
        expr(0);
        setState(215);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__3) {
          setState(211);
          match(AslParser::T__3);
          setState(212);
          expr(0);
          setState(217);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(220);
      match(AslParser::T__1);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<StructIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(222);
      ident();
      setState(223);
      match(AslParser::T__14);
      setState(224);
      field();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(226);
      ident();
      setState(227);
      match(AslParser::T__4);
      setState(228);
      expr(0);
      setState(229);
      match(AslParser::T__5);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(231);
      ident();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(251);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(249);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(234);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(235);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::MUL)
            | (1ULL << AslParser::DIV)
            | (1ULL << AslParser::MOD))) != 0))) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(236);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(237);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(238);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::MINUS)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(239);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(240);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(241);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::EQUAL)
            | (1ULL << AslParser::NEQ)
            | (1ULL << AslParser::LT)
            | (1ULL << AslParser::LE)
            | (1ULL << AslParser::GT)
            | (1ULL << AslParser::GE))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(242);
          expr(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(243);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(244);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::AND);
          setState(245);
          expr(8);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(246);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(247);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::OR);
          setState(248);
          expr(7);
          break;
        }

        } 
      }
      setState(253);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

antlrcpp::Any AslParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 26, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

AslParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FieldContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::FieldContext::getRuleIndex() const {
  return AslParser::RuleField;
}

antlrcpp::Any AslParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FieldContext* AslParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 28, AslParser::RuleField);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "func_params", "declarations", "variable_decl", 
  "array_decl", "struct_decl", "type", "basic_type", "statements", "statement", 
  "left_expr", "expr", "ident", "field"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'('", "')'", "':'", "','", "'['", "']'", "'of'", "'{'", "'}'", "';'", 
  "'?'", "'for'", "'in'", "'do'", "'.'", "'='", "'=='", "'!='", "'<'", "'<='", 
  "'>'", "'>='", "'and'", "'or'", "'not'", "'+'", "'-'", "'*'", "'/'", "'%'", 
  "'var'", "'int'", "'float'", "'bool'", "'char'", "'array'", "'struct'", 
  "'if'", "'then'", "'else'", "'endif'", "'while'", "'endwhile'", "'func'", 
  "'endfunc'", "'return'", "'read'", "'write'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ASSIGN", 
  "EQUAL", "NEQ", "LT", "LE", "GT", "GE", "AND", "OR", "NOT", "PLUS", "MINUS", 
  "MUL", "DIV", "MOD", "VAR", "INT", "FLOAT", "BOOL", "CHAR", "ARRAY", "STRUCT", 
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "ENDWHILE", "FUNC", "ENDFUNC", 
  "RETURN", "READ", "WRITE", "BOOLVAL", "ID", "INTVAL", "FLOATVAL", "CHARVAL", 
  "STRING", "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
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
    0x3, 0x3a, 0x105, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x6, 0x2, 0x22, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x23, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x31, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x3e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x41, 0xb, 0x4, 0x3, 
    0x5, 0x7, 0x5, 0x44, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x47, 0xb, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x4d, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0x50, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x7, 0x8, 0x66, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x69, 0xb, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x70, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x7, 0xb, 0x75, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0x78, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0x94, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xa3, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0xa6, 0xb, 0xc, 0x5, 0xc, 0xa8, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xaf, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xbd, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0xc9, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xd8, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 
    0xdb, 0xb, 0xe, 0x5, 0xe, 0xdd, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xeb, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xfc, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xff, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x3, 0x1a, 0x11, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 
    0x8, 0x3, 0x2, 0x22, 0x25, 0x3, 0x2, 0x1b, 0x1d, 0x4, 0x2, 0x33, 0x33, 
    0x35, 0x37, 0x3, 0x2, 0x1e, 0x20, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x13, 
    0x18, 0x2, 0x11a, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x36, 0x3, 0x2, 0x2, 0x2, 0x8, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x48, 0x3, 0x2, 0x2, 0x2, 0xc, 0x54, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x76, 0x3, 0x2, 0x2, 0x2, 0x16, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x100, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x22, 0x5, 0x4, 0x3, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 
    0x2, 0x2, 0x3, 0x26, 0x3, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0x2e, 
    0x2, 0x2, 0x28, 0x29, 0x7, 0x34, 0x2, 0x2, 0x29, 0x2b, 0x7, 0x3, 0x2, 
    0x2, 0x2a, 0x2c, 0x5, 0x6, 0x4, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x30, 0x7, 0x4, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x5, 0x2, 0x2, 0x2f, 0x31, 
    0x5, 0x10, 0x9, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x5, 0x8, 
    0x5, 0x2, 0x33, 0x34, 0x5, 0x14, 0xb, 0x2, 0x34, 0x35, 0x7, 0x2f, 0x2, 
    0x2, 0x35, 0x5, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x34, 0x2, 0x2, 
    0x37, 0x38, 0x7, 0x5, 0x2, 0x2, 0x38, 0x3f, 0x5, 0x10, 0x9, 0x2, 0x39, 
    0x3a, 0x7, 0x6, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x34, 0x2, 0x2, 0x3b, 0x3c, 
    0x7, 0x5, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0x10, 0x9, 0x2, 0x3d, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x5, 0xa, 0x6, 0x2, 
    0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 
    0x21, 0x2, 0x2, 0x49, 0x4e, 0x7, 0x34, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x6, 
    0x2, 0x2, 0x4b, 0x4d, 0x7, 0x34, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x5, 0x2, 0x2, 0x52, 0x53, 
    0x5, 0x10, 0x9, 0x2, 0x53, 0xb, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 
    0x26, 0x2, 0x2, 0x55, 0x56, 0x7, 0x7, 0x2, 0x2, 0x56, 0x57, 0x7, 0x35, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x8, 0x2, 0x2, 0x58, 0x59, 0x7, 0x9, 0x2, 
    0x2, 0x59, 0x5a, 0x5, 0x12, 0xa, 0x2, 0x5a, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5c, 0x7, 0x27, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0xa, 0x2, 0x2, 0x5d, 
    0x5e, 0x5, 0x1e, 0x10, 0x2, 0x5e, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x5f, 0x67, 
    0x5, 0x12, 0xa, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 0x61, 0x62, 0x5, 
    0x1e, 0x10, 0x2, 0x62, 0x63, 0x7, 0x5, 0x2, 0x2, 0x63, 0x64, 0x5, 0x12, 
    0xa, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x69, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0xb, 0x2, 0x2, 0x6b, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x70, 0x5, 0x12, 0xa, 0x2, 0x6d, 0x70, 0x5, 
    0xc, 0x7, 0x2, 0x6e, 0x70, 0x5, 0xe, 0x8, 0x2, 0x6f, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x11, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x9, 0x2, 0x2, 0x2, 
    0x72, 0x13, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x5, 0x16, 0xc, 0x2, 0x74, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x18, 
    0xd, 0x2, 0x7a, 0x7b, 0x7, 0x12, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x1a, 0xe, 
    0x2, 0x7c, 0x7d, 0x7, 0xc, 0x2, 0x2, 0x7d, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x7f, 0x5, 0x1c, 0xf, 0x2, 0x7f, 0x80, 0x7, 0x12, 0x2, 0x2, 0x80, 
    0x81, 0x7, 0x7, 0x2, 0x2, 0x81, 0x82, 0x5, 0x1a, 0xe, 0x2, 0x82, 0x83, 
    0x7, 0xd, 0x2, 0x2, 0x83, 0x84, 0x5, 0x1a, 0xe, 0x2, 0x84, 0x85, 0x7, 
    0x5, 0x2, 0x2, 0x85, 0x86, 0x5, 0x1a, 0xe, 0x2, 0x86, 0x87, 0x7, 0xe, 
    0x2, 0x2, 0x87, 0x88, 0x5, 0x1c, 0xf, 0x2, 0x88, 0x89, 0x7, 0xf, 0x2, 
    0x2, 0x89, 0x8a, 0x5, 0x1c, 0xf, 0x2, 0x8a, 0x8b, 0x7, 0x8, 0x2, 0x2, 
    0x8b, 0x8c, 0x7, 0xc, 0x2, 0x2, 0x8c, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8e, 0x7, 0x28, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x1a, 0xe, 0x2, 0x8f, 0x90, 
    0x7, 0x29, 0x2, 0x2, 0x90, 0x93, 0x5, 0x14, 0xb, 0x2, 0x91, 0x92, 0x7, 
    0x2a, 0x2, 0x2, 0x92, 0x94, 0x5, 0x14, 0xb, 0x2, 0x93, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x7, 0x2b, 0x2, 0x2, 0x96, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x7, 0x2c, 0x2, 0x2, 0x98, 0x99, 0x5, 0x1a, 0xe, 0x2, 0x99, 
    0x9a, 0x7, 0x10, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x14, 0xb, 0x2, 0x9b, 0x9c, 
    0x7, 0x2d, 0x2, 0x2, 0x9c, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x5, 
    0x1c, 0xf, 0x2, 0x9e, 0xa7, 0x7, 0x3, 0x2, 0x2, 0x9f, 0xa4, 0x5, 0x1a, 
    0xe, 0x2, 0xa0, 0xa1, 0x7, 0x6, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0x1a, 0xe, 
    0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x4, 0x2, 0x2, 0xaa, 0xab, 0x7, 0xc, 
    0x2, 0x2, 0xab, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xac, 0xae, 0x7, 0x30, 0x2, 
    0x2, 0xad, 0xaf, 0x5, 0x1a, 0xe, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xbd, 0x7, 0xc, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x31, 0x2, 0x2, 0xb2, 0xb3, 
    0x5, 0x18, 0xd, 0x2, 0xb3, 0xb4, 0x7, 0xc, 0x2, 0x2, 0xb4, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x32, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x1a, 
    0xe, 0x2, 0xb7, 0xb8, 0x7, 0xc, 0x2, 0x2, 0xb8, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xba, 0x7, 0x32, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x38, 0x2, 0x2, 
    0xbb, 0xbd, 0x7, 0xc, 0x2, 0x2, 0xbc, 0x79, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0x7e, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbf, 0x5, 0x1c, 0xf, 0x2, 0xbf, 0xc0, 0x7, 0x11, 0x2, 0x2, 
    0xc0, 0xc1, 0x5, 0x1e, 0x10, 0x2, 0xc1, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc3, 0x5, 0x1c, 0xf, 0x2, 0xc3, 0xc4, 0x7, 0x7, 0x2, 0x2, 0xc4, 0xc5, 
    0x5, 0x1a, 0xe, 0x2, 0xc5, 0xc6, 0x7, 0x8, 0x2, 0x2, 0xc6, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc9, 0x5, 0x1c, 0xf, 0x2, 0xc8, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0x19, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x8, 0xe, 0x1, 0x2, 
    0xcb, 0xcc, 0x7, 0x3, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x1a, 0xe, 0x2, 0xcd, 
    0xce, 0x7, 0x4, 0x2, 0x2, 0xce, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 
    0x9, 0x3, 0x2, 0x2, 0xd0, 0xeb, 0x5, 0x1a, 0xe, 0xd, 0xd1, 0xeb, 0x9, 
    0x4, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x1c, 0xf, 0x2, 0xd3, 0xdc, 0x7, 0x3, 
    0x2, 0x2, 0xd4, 0xd9, 0x5, 0x1a, 0xe, 0x2, 0xd5, 0xd6, 0x7, 0x6, 0x2, 
    0x2, 0xd6, 0xd8, 0x5, 0x1a, 0xe, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd8, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x4, 
    0x2, 0x2, 0xdf, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x1c, 0xf, 
    0x2, 0xe1, 0xe2, 0x7, 0x11, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x1e, 0x10, 0x2, 
    0xe3, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x1c, 0xf, 0x2, 0xe5, 
    0xe6, 0x7, 0x7, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x1a, 0xe, 0x2, 0xe7, 0xe8, 
    0x7, 0x8, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x5, 
    0x1c, 0xf, 0x2, 0xea, 0xca, 0x3, 0x2, 0x2, 0x2, 0xea, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xea, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xed, 0xc, 0xc, 0x2, 0x2, 0xed, 0xee, 0x9, 0x5, 0x2, 0x2, 0xee, 0xfc, 
    0x5, 0x1a, 0xe, 0xd, 0xef, 0xf0, 0xc, 0xb, 0x2, 0x2, 0xf0, 0xf1, 0x9, 
    0x6, 0x2, 0x2, 0xf1, 0xfc, 0x5, 0x1a, 0xe, 0xc, 0xf2, 0xf3, 0xc, 0xa, 
    0x2, 0x2, 0xf3, 0xf4, 0x9, 0x7, 0x2, 0x2, 0xf4, 0xfc, 0x5, 0x1a, 0xe, 
    0xb, 0xf5, 0xf6, 0xc, 0x9, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x19, 0x2, 0x2, 
    0xf7, 0xfc, 0x5, 0x1a, 0xe, 0xa, 0xf8, 0xf9, 0xc, 0x8, 0x2, 0x2, 0xf9, 
    0xfa, 0x7, 0x1a, 0x2, 0x2, 0xfa, 0xfc, 0x5, 0x1a, 0xe, 0x9, 0xfb, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xef, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0x34, 0x2, 0x2, 0x101, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x34, 0x2, 0x2, 0x103, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x16, 0x23, 0x2b, 0x30, 0x3f, 0x45, 0x4e, 
    0x67, 0x6f, 0x76, 0x93, 0xa4, 0xa7, 0xae, 0xbc, 0xc8, 0xd9, 0xdc, 0xea, 
    0xfb, 0xfd, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
