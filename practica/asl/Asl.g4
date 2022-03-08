grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' func_params ')' (':' type)? declarations statements ENDFUNC
        ;
        
func_params
        : ( | ID ':' type (',' ID ':' type)*)
        ;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR ID (',' ID)* ':' type
        ;
        
array_decl
        : ARRAY '[' INTVAL ']'  'of' basic_type
        ;

type
        : basic_type | array_decl
        ;       

basic_type    
        : INT | FLOAT | BOOL | CHAR
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           # assignStmt
          // if-then-else statement (else is optional)
//MIRAR QUE ESTIGUI BÉ L'ELSE(test 3) 
        | IF expr THEN statements (ELSE statements)? ENDIF       # ifStmt
          // while-do-endwhile statement
        | WHILE expr 'do' statements ENDWHILE # whileStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ident '(' ')' ';'                   # procCall
          // Return statement
        | RETURN expr? ';'                    #returnStmt
          // Read a variable
        | READ left_expr ';'                  # readStmt
          // Write an expression
        | WRITE expr ';'                      # writeExpr
          // Write a string
        | WRITE STRING ';'                    # writeString
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident '[' expr ']'
        | ident
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    :  LPAR expr RPAR                     # parenthesis
        | op=(MINUS|NOT|PLUS) expr            # unary
        | expr op=(MUL|DIV) expr              # arithmetic
        | expr op=(PLUS|MINUS) expr           # arithmetic
        | expr op=(EQUAL|NEQ|LT|GT|LE|GE) expr    # relational
        | expr op=AND expr                    # boolean
        | expr op=OR expr                     # boolean
        | (INTVAL|FLOATVAL|CHARVAL|BOOLVAL)   # value
        | ID '(' (expr (',' expr)*)? ')'		  # functionCall
        | ident '[' expr ']'				  # exprIdent
        | ident                               # exprIdent
        ;

// Identifiers
ident   : ID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

LPAR      : '(';
RPAR      : ')';
ASSIGN    : '=' ;
EQUAL     : '==' ;
NEQ       : '!=' ;
LT        : '<' ;
LE        : '<=' ;
GT        : '>' ;
GE        : '>=' ;
AND       : 'and';
OR        : 'or';
NOT       : 'not';
PLUS      : '+' ;
MINUS     : '-' ;
MUL       : '*';
DIV       : '/';

VAR       : 'var';
INT       : 'int';
FLOAT     : 'float';
BOOL      : 'bool';
CHAR      : 'char';
ARRAY     : 'array' ;

IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE     : 'while';
ENDWHILE  : 'endwhile';

FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
RETURN    : 'return' ;

READ      : 'read' ;
WRITE     : 'write' ;

ID        : ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : ('0'..'9')+ '.' ('0'..'9')+;
BOOLVAL   : 'true' | 'false';
CHARVAL   : '\'' ( ESC_SEQ | ~('\\'|'"') ) '\'';

// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
