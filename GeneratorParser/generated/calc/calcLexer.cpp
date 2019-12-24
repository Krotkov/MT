#include <bits/stdc++.h>
#include "calcLexer.h"

calcLexer::calcLexer() {
    curPos = 0;
    _curToken = BEGIN;
    skips = { WHITE };
}

Token calcLexer::curToken() {
    return _curToken;
}

void calcLexer::updateInput(const std::string& newInput) {
    input = newInput;
    curPos = 0;
}

std::string calcLexer::tokenString() {
    return _tokenString;
}

void calcLexer::nextToken() {
    Token t = findNextToken();
    while (skips.find(t) != skips.end()) {
        t = findNextToken();
    }
    _curToken = t;
}

Token calcLexer::findNextToken() {
    std::smatch m;
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^([ \t\n]+))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return WHITE;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^([0-9]+))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return NUM;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\+))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return PLUS;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\-))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return MINUS;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\\))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return DIV;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\*))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return MUL;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\())"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return LBR;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\)))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return RBR;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex("$"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return END;
    }
    throw std::runtime_error("bad argument");
}
