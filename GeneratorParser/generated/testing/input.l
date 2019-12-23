%{
%}
%tokens
WHITE
NUM
PLUS
MUL
LBR
RBR
%skip
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