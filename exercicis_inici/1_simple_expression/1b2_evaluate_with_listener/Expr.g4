grammar Expr;

s : e EOF ;

e : SUB e
  | (MAX | MIN) '(' list_of_e ')'
  | e (MUL | DIV) e
  | e (ADD | SUB) e
  | INT
  ;
  
list_of_e : 
  | e (',' e)*;


ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
MAX : 'max';
MIN : 'min';

INT : [0-9]+ ;
WS  : [ \t\n]+ -> skip ;
