grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' func_params? ')' (':' type)? declarations statements ENDFUNC
        ;
        
func_params
        : ID ':' type (',' ID ':' type)*
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
        : left_expr ASSIGN expr ';'           				# assignStmt
        | IF expr THEN statements (ELSE statements)? ENDIF  # ifStmt
        | WHILE expr 'do' statements ENDWHILE 				# whileStmt
        | FOR ident 'in' 
			'range' '(' (expr (',' expr)*)?  ')' 'do'
			statement*
			ENDFOR 											# for
        | ident '(' (expr (',' expr)*)? ')' ';'             # procCall
        | RETURN expr? ';'                    				# returnStmt
        | READ left_expr ';'                  				# readStmt
        | WRITE expr ';'                      				# writeExpr
        | WRITE STRING ';'                    				# writeString
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident '[' expr ']' 			
        | ident							
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    : '(' expr ')'                         		# parenthesis
        | op=(MINUS|NOT|PLUS) expr            		# unary
        | MAX '(' (expr (',' expr)*)? ')' 			# max
        | expr op=(MUL|DIV|MOD) expr          		# arithmetic
        | expr op=(PLUS|MINUS) expr           		# arithmetic
        | expr op=(EQUAL|NEQ|LT|GT|LE|GE) expr  	# relational
        | expr op=AND expr                   		# boolean
        | expr op=OR expr                    		# boolean
        | (INTVAL|FLOATVAL|CHARVAL|BOOLVAL)   		# value
        | ident '(' (expr (',' expr)*)? ')'     	# funcCall
        | ident '[' expr ']'			        	# exprIdent
        | ident                               		# exprIdent
        ;

// Identifiers
ident   : ID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

// ----- Relational Operators -----
ASSIGN    : '=' ;
EQUAL     : '==' ;
NEQ       : '!=' ;
LT        : '<' ;
LE        : '<=' ;
GT        : '>' ;
GE        : '>=' ;

// ----- Boolean Operators -----
AND       : 'and';
OR        : 'or';
NOT       : 'not';

// ----- Max | Min -----
MAX       : 'max';

// ----- Arithmetic Operators -----
PLUS      : '+' ;
MINUS     : '-' ;
MUL       : '*';
DIV       : '/';
MOD		  : '%';

// ----- Types -----
VAR       : 'var';
INT       : 'int';
FLOAT     : 'float';
BOOL      : 'bool';
CHAR      : 'char';
ARRAY     : 'array' ;

// ----- Statements -----
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE     : 'while';
FOR		  : 'for';
ENDFOR	  : 'endfor';
ENDWHILE  : 'endwhile';

// ----- Functions -----
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
RETURN    : 'return' ;

// ----- Input/Output -----
READ      : 'read' ;
WRITE     : 'write' ;


// ----- Values -----
BOOLVAL   : 'true' | 'false';
ID        : ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : ('0'..'9')+ '.' ('0'..'9')+;
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
