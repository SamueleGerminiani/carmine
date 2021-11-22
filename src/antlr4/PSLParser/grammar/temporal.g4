grammar temporal;
import proposition;

formula : implication EOF;
implication: ALWAYS '(' tformula IMPL tformula ')'
    | ALWAYS '(' tformula IMPL2 tformula   ')'
	| ALWAYS '(' LGPAREN sere RGPAREN LCPAREN  RCPAREN IMPL tformula ')'
	| ALWAYS '(' LGPAREN sere RGPAREN LCPAREN  RCPAREN IMPL2 tformula ')'
	| ALWAYS '(' LGPAREN sere RGPAREN SEREIMPL1 tformula ')'
	| ALWAYS '(' LGPAREN sere RGPAREN SEREIMPL2 tformula ')';

sere : boolean
     | TIMER '(' boolean ',' NUMERIC ')'
	 | LPAREN sere RPAREN
	 | LGPAREN sere RGPAREN
	 | sere BOR sere
	 | sere BAND sere
	 | sere AND sere
	 | sere SCOL sere
	 | sere COL sere
	 | sere LCPAREN TIMES NUMERIC? DOTS? NUMERIC? RCPAREN
	 | sere LCPAREN PLUS RCPAREN
	 | sere LCPAREN ASS NUMERIC DOTS? NUMERIC? RCPAREN
	 | sere LCPAREN IMPL NUMERIC DOTS? NUMERIC? RCPAREN
	 | DELAY LCPAREN? NUMERIC DOTS? NUMERIC? RCPAREN? sere
	 | sere DELAY LCPAREN? NUMERIC? DOTS? NUMERIC? RCPAREN? sere
	 ;

tformula: boolean
    | TIMER '(' boolean ',' NUMERIC ')'
	| LPAREN tformula RPAREN 
	| NOT tformula 
	| tformula AND tformula 
	| tformula OR tformula 
	| tformula XOR tformula 
	| tformula UNTIL tformula 
	| tformula RELEASE tformula
	| NEXT LCPAREN NUMERIC RCPAREN tformula 
	| NEXT tformula 
	| LGPAREN sere RGPAREN
	;

TIMER
    : '$timeout'
    ;
EVENTUALLY
    : 'F'
    ;
ALWAYS
    : 'G'
    ;
NEXT
    : 'X'
    ;
UNTIL
    : 'U'
    ;

WUNTIL
    : 'W'
    ;

SUNTIL
    : 'X[!]'
    ;

RELEASE
    : 'R'
    ;

SRELEASE
    : 'M'
    ;

DOTS
    : '..'
    ;
IMPL
    : '->'
    ;

IMPL2
    : '=>'
    ;

SEREIMPL1
    : '|->'
    ;

SEREIMPL2
    : '|=>'
    ;

IFF
    : '<->'
    ;

XOR
    : 'xor'
    ;
	
BIND1
    : '<>->'
    ;

BIND2
    : '<>=>'
    ;

ASS
    : '='
    ;


SCOL
    : ';'
    ;

COL
    : ':'
    ;

FIRST_MATCH
	:
'first_match'
	;
	
DELAY
    : '##'
    ;
