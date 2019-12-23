%{
%}
%tokens
NAME
PLUS
WHITE
%skip
%%
[ \t\n]+
{
return WHITE;
}
[a-zA-Z]+
{
return NAME;
}
\+
{
return PLUS;
}
%%