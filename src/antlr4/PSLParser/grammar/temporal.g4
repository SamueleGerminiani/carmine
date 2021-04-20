grammar temporal;
import proposition;

formula : implication EOF;
implication: ALWAYS '(' tformula IMPL tformula ')'
    | ALWAYS '(' tformula IMPL2 tformula   ')'
	| ALWAYS '(' LGPAREN sere RGPAREN LCPAREN  RCPAREN IMPL tformula ')'
	| ALWAYS '(' LGPAREN sere RGPAREN LCPAREN  RCPAREN IMPL2 tformula ')'
	| ALWAYS '(' LGPAREN sere RGPAREN BIND1 tformula ')'
	| ALWAYS '(' LGPAREN sere RGPAREN BIND2 tformula ')';

sere : boolean
	 | LPAREN sere RPAREN
	 | LGPAREN sere RGPAREN
	 | LCPAREN TIMES NUMERIC DOTS NUMERIC RCPAREN
	 | LCPAREN PLUS RCPAREN
	 | sere LCPAREN TIMES NUMERIC DOTS NUMERIC RCPAREN
	 | sere LCPAREN PLUS RCPAREN
	 | sere LCPAREN COL TIMES NUMERIC DOTS NUMERIC RCPAREN
	 | sere LCPAREN COL PLUS RCPAREN
	 | sere LCPAREN ASS NUMERIC DOTS NUMERIC RCPAREN
	 | sere LCPAREN IMPL NUMERIC DOTS NUMERIC RCPAREN
	 | sere AND sere
	 | sere OR sere
	 | DSYM1 NUMERIC sere
	 | DSYM1 LCPAREN NUMERIC DOTS NUMERIC RCPAREN sere
	 | sere DSYM1 NUMERIC sere
	 | sere DSYM1 LCPAREN NUMERIC DOTS NUMERIC RCPAREN sere
	 | sere COL sere
	 | sere SCOL sere
	 | FIRST_MATCH LPAREN sere RPAREN
	 ;

tformula: boolean
    | TIMER '(' boolean ',' NUMERIC ')'
	| LPAREN tformula RPAREN 
	| LGPAREN sere RGPAREN
	| LGPAREN sere RGPAREN NOT
	| NOT tformula 
	| NEXT tformula 
	| NEXT LCPAREN NUMERIC DOTS NUMERIC RCPAREN tformula 
	| NEXT LCPAREN NUMERIC DOTS NUMERIC NOT RCPAREN tformula 
	| tformula UNTIL tformula 
	| tformula WUNTIL tformula 
	| tformula SRELEASE tformula
	| tformula RELEASE tformula
	| tformula AND tformula 
	| tformula BAND tformula 
	| tformula OR tformula 
	| tformula BOR tformula 
	| tformula XOR tformula 
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

DSYM1
    : '##'
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
	
