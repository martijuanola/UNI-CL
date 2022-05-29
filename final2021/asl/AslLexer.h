
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, ASSIGN = 13, 
    EQUAL = 14, NEQ = 15, LT = 16, LE = 17, GT = 18, GE = 19, AND = 20, 
    OR = 21, NOT = 22, POWER = 23, PLUS = 24, MINUS = 25, MUL = 26, DIV = 27, 
    MOD = 28, VAR = 29, INT = 30, FLOAT = 31, BOOL = 32, CHAR = 33, ARRAY = 34, 
    IF = 35, THEN = 36, ELSE = 37, ENDIF = 38, WHILE = 39, ENDWHILE = 40, 
    FUNC = 41, ENDFUNC = 42, RETURN = 43, READ = 44, WRITE = 45, BOOLVAL = 46, 
    ID = 47, INTVAL = 48, FLOATVAL = 49, CHARVAL = 50, STRING = 51, COMMENT = 52, 
    WS = 53
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

