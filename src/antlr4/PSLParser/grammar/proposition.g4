grammar proposition;


// ------------------------------------------ BOOLEAN
boolean
    : NOT boolean
    | logic relop logic
    | numeric relop numeric
    | logic EQ logic
    | numeric EQ numeric
    | boolean EQ boolean
    | logic NEQ logic
    | numeric NEQ numeric
    | boolean NEQ boolean
    | boolean booleanop=AND boolean
    | boolean booleanop=OR boolean
/*
    | boolean 'xor' boolean
    | boolean '<->' boolean
    | boolean '->' boolean
*/
    | booleanAtom
/*
    | LPAREN CAST_BOOL RPAREN numeric
    | LPAREN CAST_BOOL RPAREN logic
*/
    | logic
    | numeric
    | LPAREN boolean RPAREN
    ;

booleanAtom
    : booleanConstant
    | booleanVariable
    ;

booleanConstant
    : BOOLEAN
    ;

booleanVariable
    : '<' variable ',bool>' 
    ;

// ------------------------------------------ LOGIC
logic
    : NEG logic 
    | logic artop=(TIMES|DIV) logic
    | logic artop=(PLUS|MINUS) logic
    | logic logop=LSHIFT logic
    | logic logop=RSHIFT logic
    | logic logop=BAND logic
    | logic logop=BXOR logic
    | logic logop=BOR logic
    | logicAtom
    | LPAREN logic RPAREN
    ;

logicAtom
    : logicConstant
    | logicVariable
    | enumVariable
    | namedLogicConst
    ;

logicConstant
    : VERILOG_BINARY
    | GCC_BINARY
    | NUMERIC
    ;

namedLogicConst
    : '<' namedConst ',constlogic(' NUMERIC ')>';

logicVariable
    : '<' variable ',logic(' SIGN ',' NUMERIC ')>' 
    ;

enumVariable
    : '<' variable ',enum(' enumName ')>'
    ;
enumName: VARIABLE;
namedConst: VARIABLE;

SIGN
    :
    'u'
    | 's';


// ------------------------------------------ NUMERIC
numeric
    : numeric artop=(TIMES|DIV) numeric
    | numeric artop=(PLUS|MINUS) numeric
    | numericAtom
/*
    | LPAREN CAST_NUMERIC RPAREN logic
*/
    | logic
    | LPAREN numeric RPAREN
    ;

numericAtom
    : numericConstant
    | numericVariable
    ;

numericConstant
    :  NUMERIC
    ;

numericVariable
    : '<' variable ',numeric(' NUMERIC ')>' 
    ;




variable
    : '*'? VARIABLE
    ;

LGPAREN
    : '{'
    ;

RGPAREN
    : '}'
    ;
LCPAREN
    : '['
    ;

RCPAREN
    : ']'
    ;

LPAREN
    : '('
    ;

RPAREN
    : ')'
    ;

CAST_BOOL
    : 'bool'
    ;

CAST_NUMERIC
    : 'double'
    ;

//==== Token VARIABLE ==========================================================
VARIABLE
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
    | '::' 
    ;
//------------------------------------------------------------------------------


//==== Token constant ==========================================================
    NUMERIC
    : '-'? ('0' .. '9') + ('.' ('0' .. '9') +)?
    ;

    
    VERILOG_BINARY
    : ('\'')('b')('0' .. '1')+
    ;

    GCC_BINARY
    : '0b' ('0' .. '1')+
    ;
    

/*
//allow a size from 1 to 64
    fragment BINARY_SIZE
    : ('1' .. '9')
    | ('1' .. '5') ('0' .. '9')
    | '6' ('0' .. '4')
    ;

*/
    BOOLEAN
    : '@true' 
    | '@false'
    ;


//------------------------------------------------------------------------------


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

//==== Relational Operators ====================================================
relop
    : GT
    | GE
    | LT
    | LE
    ;

GT
    : '>'
    ;

GE
    : '>='
    ;

LT
    : '<'
    ;

LE
    : '<='
    ;

EQ
    : '=='
    ;

NEQ
    : '!='
    ;
//------------------------------------------------------------------------------


//==== Logic Operators =========================================================

BAND
    : '&'
    ;

BOR
    : '|'
    ;

BXOR
    : '^'
    ;

NEG
    : '~'
    ;

LSHIFT: '<<';

RSHIFT: '>>';

//------------------------------------------------------------------------------


//==== Boolean Operators ========================================================

AND
    : '&&'
    ;

OR
    : '||'
    ;

NOT
    : '!'
    ;
//------------------------------------------------------------------------------

// Ignore: \r, \n, \t
WS : [ \t\r\n] -> skip;
