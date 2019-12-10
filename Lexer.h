//
// Created by kranya on 09.12.2019.
//

#ifndef MT_LEXER_H
#define MT_LEXER_H

#include <string>

enum Token {
    LBRACKET, RBRACKET, FUNCTION, PROCEDURE, NAME, TYPE, COLON, SEMICOLON, END, BEGIN, COMMA
};

class Lexer {
    std::string stream;
    int curPos{};
    Token _curToken{};

    static bool isBlank(char c);
    std::string getStr();
    char curChar();
    char nextChar();
    static bool checkVarName(std::string&);
    static bool checkSymbol(char c);

public:
    explicit Lexer (std::string& str);

    Lexer();

    void nextToken();

    Token curToken();
};


#endif //MT_LEXER_H
