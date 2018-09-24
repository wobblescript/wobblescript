grammar WobbleScriptParser;
import WobbleScriptLexer;

prog: directive* decl*;

directive: importDirective;

importDirective: 'import' path=(STRING1 | STRING2) ('as' alias=ID)?;

decl: typeDecl | classDecl | funcDecl;

typeDecl: 'type' name=ID '=' type ';'?;

classDecl: 'class' name=ID ('extends' extendsFrom=ID)? '{' '}';

classMember:
    'constructor' paramList block #ClassConstructor
    | 'abstract' name=ID paramList ':' returnType=type ';' #AbstractClassMethod
    | name=ID paramList ':' returnType=type block #ClassMethod
    | 'var' name=ID ':' type ';' #ClassField
;

funcDecl: 'function' name=ID paramList ':' returnType=type block;

paramList: '(' (param ','?)* ')';

param: name=ID ':' type;

type:
    ID #TypeRef
    | left=type '|' right=type #UnionType
    | type '?' #NullableType
    | '{' (objectTypeField ';'?)* '}' #ObjectType
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
    | expr '?' #NullableExpr
    | expr '!' #NonNullableExpr
    | 'function' (name=ID)? paramList block #FnExpr
    | ('<' type '>')? '[' (expr ','?)+ ']' #ArrayLiteralExpr
    | callee=expr argList #CallExpr
    | 'new' callee=expr argList #NewExpr
    | left=expr '??' right=expr #NullCoalescingExpr
    | left=expr op=('*'|'/'|'%') right=expr #MulDivModExpr
    | left=expr op=('+'|'-') right=expr #AddSubExpr
    | left=expr op=('^'|'&'|'|') right=expr #XorAndOrExpr
    | left=expr op=('>'|'>='|'<'|'<=') right=expr #LtGtExpr
    | left=expr op=('=='|'!=') right=expr #BoolEqExpr
    | left=expr op=('&&'|'||') right=expr #BoolAndOrExpr
    | '(' expr ')' #ParenExpr
;

argList: '(' (expr ','?)* ')';