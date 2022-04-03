
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, ASSIGN = 13, 
    EQUAL = 14, NEQ = 15, LT = 16, LE = 17, GT = 18, GE = 19, AND = 20, 
    OR = 21, NOT = 22, PLUS = 23, MINUS = 24, MUL = 25, DIV = 26, MOD = 27, 
    VAR = 28, INT = 29, FLOAT = 30, BOOL = 31, CHAR = 32, ARRAY = 33, IF = 34, 
    THEN = 35, ELSE = 36, ENDIF = 37, WHILE = 38, ENDWHILE = 39, FUNC = 40, 
    ENDFUNC = 41, RETURN = 42, READ = 43, WRITE = 44, PACK = 45, UNPACK = 46, 
    BOOLVAL = 47, ID = 48, INTVAL = 49, FLOATVAL = 50, CHARVAL = 51, STRING = 52, 
    COMMENT = 53, WS = 54
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

