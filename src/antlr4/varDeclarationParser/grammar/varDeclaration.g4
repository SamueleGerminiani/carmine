grammar varDeclaration;

file : cDeclaration EOF;

cDeclaration : cStatement ';'
             | cStatement ';' cDeclaration;

cStatement : varDec | enumDec;


varDec : vartype name ass?;
ass: '=' NAME | '=' NUMERIC;
enumDec : ENUM name OB enum_list CB
        | TYPEDEF ENUM OB enum_list CB name
        | ENUM OB enum_list CB;

LSBRACKET: '(';
RSBRACKET: ')';

TYPEDEF : 'typedef';
ENUM : 'enum';
OB : '{';
CB : '}';

enum_list :
      name ('=' addLogic)?
    | name ('=' addLogic)? ',' enum_list;

addLogic : logic;
name : NAME;
logicName : NAME;
vartype :  VARTYPE | enumType;
enumType : name;
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
  'bool *' 
| 'unsigned char *' 
| 'unsigned short *' 
| 'unsigned int *' 
| 'unsigned long long *' 
| 'char *' 
| 'short *' 
| 'int *' 
| 'long long *' 
| 'float *' 
| 'double *' 
; 

logic
    : logic artop=(TIMES|DIV) logic
    | logic artop=(PLUS|MINUS) logic
    | logicAtom
    | '(' logic ')'
    ;

logicAtom
    : logicConstant
    | logicName
    ;

logicConstant
    : VERILOG_BINARY
    | GCC_BINARY
    | NUMERIC
    ;

NUMERIC
: '-'? ('0' .. '9') + ('.' ('0' .. '9') +)?
;


VERILOG_BINARY
: ('\'')('b')('0' .. '1')+
;

GCC_BINARY
: '0b' ('0' .. '1')+
;

//==== Arithmetic Operators ====================================================
PLUS
    : '+'
    ;

MINUS
    : '-'
    ;

TIMES
    : '*'
    ;

DIV
    : '/'
    ;
//------------------------------------------------------------------------------

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
