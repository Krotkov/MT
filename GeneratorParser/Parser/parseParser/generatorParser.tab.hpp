/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_PARSER_HOME_KRANYA_MT_GENERATORPARSER_PARSER_PARSEPARSER_GENERATORPARSER_TAB_HPP_INCLUDED
# define YY_PARSER_HOME_KRANYA_MT_GENERATORPARSER_PARSER_PARSEPARSER_GENERATORPARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXT = 258,
    WHITE = 259,
    PROCLB = 260,
    PROCRB = 261,
    PROCPROC = 262,
    LBR = 263,
    RBR = 264,
    TYPE = 265,
    TOKEN = 266,
    START = 267,
    CAR = 268,
    COMMA = 269,
    COLON = 270,
    SEMICOLON = 271
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "generatorParser.y"

    std::string* str;
    std::vector<std::string>* vect;
    std::pair<std::vector<std::string>, std::string>* pir;
    std::vector<std::pair<std::vector<std::string>, std::string> >* vectpir;

#line 81 "/home/kranya/MT/GeneratorParser/Parser/parseParser/generatorParser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_HOME_KRANYA_MT_GENERATORPARSER_PARSER_PARSEPARSER_GENERATORPARSER_TAB_HPP_INCLUDED  */
