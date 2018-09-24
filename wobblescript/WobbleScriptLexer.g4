lexer grammar WobbleScriptLexer;

WS: [ \n\r\t]+ -> skip;
SL_COMMENT: '//'(~'\n')* -> skip;
STRING1: '"' (('\\"') | ~('"' | '\n') )* '"';
STRING2: '\'' (('\\\'') | ~('\'' | '\n') )* '\'';
TILDE_STRING: '`' (('\\`') | ~('`' | '\n') )* '`';
ID: [A-Za-z_][A-Za-z0-9_]*;
