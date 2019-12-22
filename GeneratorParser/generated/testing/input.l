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
[abc]+
{
return NAME;
}
\+
{
return PLUS;
}
%%