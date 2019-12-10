//
// Created by kranya on 09.12.2019.
//

#include <iostream>
#include "Lexer.h"

Lexer::Lexer(std::string &str) {
    this->stream = str;
    this->stream += '$';
    this->curPos = 0;
    this->_curToken = Token::BEGIN;
}

bool Lexer::isBlank(char c) {
    return (c == ' ' || c == '\r' || c == '\n' || c == '\t');
}

std::string Lexer::getStr() {
    char curSymbol = curChar();
    std::string ans;
    while (!isBlank(curSymbol) && curSymbol != '$' && checkSymbol(curSymbol)) {
        ans += curSymbol;
        curSymbol = nextChar();
    }
    return ans;
}

Token Lexer::curToken() {
    return _curToken;
}

char Lexer::curChar() {
    return stream[curPos];
}

char Lexer::nextChar() {
    curPos++;
    return stream[curPos];
}

void Lexer::nextToken() {
    char c = curChar();
    while (isBlank(c)) {
        c = nextChar();
    }
    switch (c) {
        case '(':
            _curToken = Token::LBRACKET;
            nextChar();
            break;
        case ')':
            _curToken = Token::RBRACKET;
            nextChar();
            break;
        case ':':
            _curToken = Token::COLON;
            nextChar();
            break;
        case ';':
            _curToken = Token::SEMICOLON;
            nextChar();
            break;
        case ',':
            _curToken = Token::COMMA;
            nextChar();
            break;
        case '$':
            _curToken = Token::END;
            nextChar();
            break;
        default:
            if (!checkSymbol(curChar())) {
                throw std::runtime_error("bad symbol");
            }
            std::string str = getStr();
            if (str == "function") _curToken = Token::FUNCTION;
            else if (str == "procedure") _curToken = Token::PROCEDURE;
            else if (str == "integer" || str == "longint" || str == "double" || str == "boolean" || str == "short")
                _curToken = Token::TYPE;
            else {
                if (checkVarName(str)) {
                    _curToken = Token::NAME;
                } else {
                    throw std::runtime_error("bad name");
                }
            }
    }
}

bool Lexer::checkVarName(std::string &str) {
    bool ans = true;
    if (str[0] < 'a' || str[0] > 'z') ans = false;
    for (size_t i = 1; i < str.size(); i++) {
        if (!checkSymbol(str[i])) {
            ans = false;
        }
    }
    return ans;
}

bool Lexer::checkSymbol(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

Lexer::Lexer() = default;



