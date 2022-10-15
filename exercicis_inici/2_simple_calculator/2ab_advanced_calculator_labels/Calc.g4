grammar Calc;

prog:  stat+ EOF ;

stat:  expr NEWLINE           # printExpr
    |  ID '=' expr NEWLINE    # assign
    |  NEWLINE                # blank
    ;
    
expr:  SUB expr	 # subuni
    |  MAX '(' list_of_expr ')' #max
    |  MIN '(' list_of_expr ')' #min
    |  SUMLIST '(' list_of_expr ')' #sumlist
    |  expr FACT	 # fact
    |  expr MUL expr    # prod
    |  expr DIV expr    # div
    |  expr ADD expr    # plus
    |  expr SUB expr    # sub
    |  INT              # int
    |  ID               # id
    ;
    
list_of_expr : 
  | expr (',' expr)*;
    
  
GT : '>';
GE : '>=';


MAX : 'max';
MIN : 'min';
SUMLIST : 'add';
FACT: '!'  ;
MUL :  '*' ;
DIV :  '/' ;
ADD :  '+' ;
SUB :  '-' ;
ID  :  [a-zA-Z]+ ;       // match identifiers
INT :  [0-9]+ ;          // match integers
NEWLINE: '\r'? '\n' ;    // return newlines to parser (is end-statement signal)
WS  :  [ \t]+ -> skip ;  // toss out whitespace
