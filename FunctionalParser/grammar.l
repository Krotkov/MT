%{
#include <bits/stdc++.h>
#include "grammar.tab.hpp"
#include <string>
%}

%option outfile = "grammar.lexer.cpp" header-file = "grammar.lexer.hpp"

white [ \t\n]
digit [0-9]
letter [a-z]
name {letter}({letter}|{digit})*
number ({digit})*
comp "=="|"!="|">"|">="|"<"|"<="

%%
{white}      ;

"Integer" {
    yylval.str = new std::string("int32_t");
    return INT;
}
"Float" {
    yylval.str = new std::string("float");
    return FLOAT;
}
"Bool" {
    yylval.str = new std::string("bool");
    return BOOL;
}
"True" {
    yylval.str = new std::string("true");
    return TRUE;
}
"False" {
    yylval.str = new std::string("false");
    return FALSE;
}
"and" {
    yylval.str = new std::string("&&");
    return AND;
}
"not" {
    yylval.str = new std::string("!");
    return NOT;
}
"or" {
    yylval.str = new std::string("||");
    return OR;
}
"Main" {
    yylval.str = new std::string("main");
    return MAIN;
}

"(" {return LBRACKET;}
")" {return RBRACKET;}
"+"  {return PLUS;}
"-"  {return MINUS;}
"div" {return DIV;}
"mod" {return MOD;}
"="  {return EQUAL;}
"readInt" {return READINT;}
"writeInt" {return WRITEINT;}
"let"   {return LET;}
"$"  {return DOLLAR;}
","  {return COMMA;}
";" {return SEMICOLON;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"*"  {return MUL;}

{comp} {
    yylval.str = new std::string(yytext);
    return COMP;
}

{number} {
    yylval.str = new std::string(yytext);
    return NUMBER;
}

{name} {
    yylval.str = new std::string(yytext);
    return NAME;
}

%%