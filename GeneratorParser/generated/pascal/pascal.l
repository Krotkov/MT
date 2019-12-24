%{
%}
%tokens
WHITE
FUNCTION
PROCEDURE
NAME
LBR
RBR
COMMA
COLON
SEMICOLON
TYPE
%skip
WHITE
%%
[ \t\n]+
{
return WHITE;
}
function
{
return FUNCTION;
}
procedure
{
return PROCEDURE;
}
\(
{
return LBR;
}
\)
{
return RBR;
}
:
{
return COLON;
}
;
{
return SEMICOLON;
}
\,
{
return COMMA;
}
Integer|Boolean|Float
{
return TYPE;
}
[a-zA-z]+
{
return NAME;
}
%%