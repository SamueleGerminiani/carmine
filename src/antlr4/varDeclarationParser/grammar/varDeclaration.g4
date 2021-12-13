grammar varDeclaration;

file : cDeclaration EOF;

cDeclaration : cStatement ';'
             | cStatement ';' cDeclaration;

cStatement : varDec;


varDec : vartype name;


name : NAME;
vartype :  VARTYPE;

VARTYPE:
  'bool' 
| 'unsigned char' 
| 'unsigned short' 
| 'unsigned int' 
| 'unsigned long long' 
| 'char' 
| 'short' 
| 'int' 
| 'long long' 
| 'float' 
| 'double' 
; 


NAME
   : VALID_ID_START VALID_ID_CHAR*
   ;

fragment VALID_ID_START
    : ('a' .. 'z')
    | ('A' .. 'Z')
    | ('_')
    ;

fragment VALID_ID_CHAR
    : VALID_ID_START
    | ('0' .. '9')
    | ('.')
    | ('_')
    | ('[') 
    | (']')
    | '::' 
    ;
// Ignore: \r, \n, \t
WS : [ \t\r\n] -> skip;
