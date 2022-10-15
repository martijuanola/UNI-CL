grammar Expr;

s : e EOF ;

e : SUB e
  | MAX '(' e ',' e ')'
  | e (MUL | DIV) e
  | e (ADD | SUB) e
  | INT
  ;

ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
MAX : 'max';

INT : [0-9]+ ;
WS  : [ \t\n]+ -> skip ;

