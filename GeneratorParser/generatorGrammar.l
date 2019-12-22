%{
#include <bits/stdc++.h>
#include "generatorGrammar.tab.hpp"
%}

%option outfile = "generatorGrammar.lexer.cpp" header-file = "generatorGrammar.lexer.hpp"

white [ \t\n]*
digit [0-9]
text  [^\n]+
letter [A-Z]
name {letter}*

%%
{white}      ;

"{"  {
    yylval.str = new std::string(yytext);
    return LBR;
}
"}" {
    yylval.str = new std::string(yytext);
    return RBR;
}
"%{"    {
    yylval.str = new std::string(yytext);
    return PROCLB;
}
"%}"    {
    yylval.str = new std::string(yytext);
    return PROCRB;
}
"%%"    {
    yylval.str = new std::string(yytext);
    return PROCPROC;
}
"," {
    yylval.str = new std::string(yytext);
    return COMMA;
}
"%tokens" {
    yylval.str = new std::string(yytext);
    return TOKENS;
}
"%skip" {
    yylval.str = new std::string(yytext);
    return SKIP;
}
{text}  {
    yylval.str = new std::string(yytext);
    return TEXT;
}
{name} {
    yylval.str = new std::string(yytext);
    return NAME;
}
%%