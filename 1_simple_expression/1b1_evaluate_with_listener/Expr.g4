grammar Expr;

s : e EOF ;

e : SUB e
  | MAX '(' list_of_e ')'
  | e (MUL | DIV) e
  | e (ADD | SUB) e
  | INT
  ;
  
list_of_e : 
  | e ',' list_of_e
  | e
  ;
// versió alternativa: e (',' e)*;


ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
MAX : 'max';

INT : [0-9]+ ;
WS  : [ \t\n]+ -> skip ;
