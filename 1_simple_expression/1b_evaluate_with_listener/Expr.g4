grammar Expr;

s : e ;

e : '-' e
  | PROVA '(' e ',' e ')'
  | e '*' e
  | e '/' e
  | e ('+'|'-') e
  | INT
  ;

INT : [0-9]+ ;
WS  : [ \t\n]+ -> skip ;
