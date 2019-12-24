%{
#include <bits/stdc++.h>
#include "generatorParser.tab.hpp"
%}

%option prefix="parser_"

%option outfile = "generatorParser.lexer.cpp" header-file = "generatorParser.lexer.hpp"

white [ \t\n`]*
digit [0-9]
text  [^\n`]+
letter [A-Z]

%%
{white}      ;

"{"  {
    parser_lval.str = new std::string(parser_text);
    return LBR;
}
"}" {
    parser_lval.str = new std::string(parser_text);
    return RBR;
}
"%{"    {
    parser_lval.str = new std::string(parser_text);
    return PROCLB;
}
"%}"    {
    parser_lval.str = new std::string(parser_text);
    return PROCRB;
}
"%%"    {
    parser_lval.str = new std::string(parser_text);
    return PROCPROC;
}
"," {
    parser_lval.str = new std::string(parser_text);
    return COMMA;
}
"%type" {
    parser_lval.str = new std::string(parser_text);
    return TYPE;
}
"%token" {
    parser_lval.str = new std::string(parser_text);
    return TOKEN;
}
"%start" {
    parser_lval.str = new std::string(parser_text);
    return START;
}
"%attribute" {
    parser_lval.str = new std::string(parser_text);
    return ATTRIBUTE;
}
":" {
    parser_lval.str = new std::string(parser_text);
    return COLON;
}
";" {
    return SEMICOLON;
}
"|" {
    return CAR;
}
{text}  {
    parser_lval.str = new std::string(parser_text);
    return TEXT;
}
%%
