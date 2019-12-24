%{
%}
%tokens
WHITE
NUM
MINUS
DIV
PLUS
MUL
LBR
RBR
%skip
WHITE
%%
[ \t\n]+
{
return WHITE;
}
[0-9]+
{
return NUM;
}
\+
{
return PLUS;
}
\-
{
return MINUS;
}
\\
{
return DIV;
}
\*
{
return MUL;
}
\(
{
return LBR;
}
\)
{
return RBR;
}
%%