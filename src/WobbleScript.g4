grammar WobbleScript;

prog: directive* decl*;

directive: importDirective;

importDirective: 'import' path=(STRING1 | STRING2) ('as' alias=ID)?;

decl: typeDecl | classDecl | funcDecl;

typeDecl: 'type' name=ID '=' type ';'?;

classDecl: 'class' name=ID '{' '}';

classMember:
    'abstract' name=ID paramList ':' returnType=type ';' #AbstractClassMember
    | 'abstract' name=ID paramList ':' returnType=type ';' #AbstractClassMember
;

funcDecl: 'function' name=ID paramList ':' returnType=type block;

paramList: '(' (param ','?)* ')';

param: name=ID ':' type;

type:
    ID #TypeRef
    | left=type '|' right=type #UnionType
    | type '?' #NullableType
    | '{' (objectTypeField ','?)* '}' #ObjectType
    | '(' type ')' #ParenType
;

objectTypeField: name=ID ':' type;

stmt:
    expr #ExprStmt
    | 'var' (varDecl ',')* varDecl #VarDeclStmt
    | 'for' '(' 'var' variableName=ID 'of' expr ')' block #ForOrStmt
    | 'while' '(' condition=expr ')' block #WhileStmt
    | 'return' expr #ReturnStmt
    | 'throw' expr #ReturnStmt
    | ';' #EmptyStmt
;

block:
    '=>' expr #ArrowBlock
    | '{' stmt* '}' #RegularBlock
    | stmt #SingleStmtBlock
;

varDecl: name=ID ('=' initializer=expr)?;

expr:
    ID #IdExpr
    | STRING1 #String1Literal
    | STRING2 #String2Literal
    | TILDE_STRING #TildeStringLiteral
    | ('<' type '>')? '[' (expr ','?)+ ']' #ArrayLiteralExpr
    | callee=expr argList #CallExpr
    | 'new' callee=expr argList #NewExpr
    | left=expr op=('*'|'/'|'%') right=expr #MulDivModExpr
    | left=expr op=('+'|'-') right=expr #AddSubExpr
    | left=expr op=('^'|'&'|'|') right=expr #XorAndOrExpr
    | left=expr op=('>'|'>='|'<'|'<=') right=expr #LtGtExpr
    | left=expr op=('=='|'!=') right=expr #BoolEqExpr
    | left=expr op=('&&'|'||') right=expr #BoolAndOrExpr
    | '(' expr ')' #ParenExpr
;

argList: '(' (expr ','?)* ')';

WS: [ \n\r\t]+ -> skip;
SL_COMMENT: '//'(~'\n')* -> skip;
STRING1: '"' (('\\"') | ~('"' | '\n') )* '"';
STRING2: '\'' (('\\\'') | ~('\'' | '\n') )* '\'';
TILDE_STRING: '`' (('\\`') | ~('`' | '\n') )* '`';
ID: [A-Za-z_][A-Za-z0-9_]*;
