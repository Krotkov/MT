%{
%}
%tokens
NAME
PLUS
WHITE
%skip
WHITE
%%
[ \t\n]+
{
return WHITE;
}
[abc]+
{
return NAME;
}
\+
{
return PLUS;
}
%%