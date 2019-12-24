#pragma once
#include <bits/stdc++.h>

enum Token {
  BEGIN, WHITE, NUM, MINUS, DIV, PLUS, MUL, LBR, RBR, POW, END
};
class calcLexer{
public:
    calcLexer();
    void updateInput(const std::string& input);
    void nextToken();
    Token curToken();
    std::string tokenString();
private:
    Token findNextToken();
    Token _curToken;
    std::string _tokenString;
    std::string input;
    std::size_t curPos;
    std::unordered_set<Token> skips;
    std::unordered_map<Token, std::regex> tokenRegex;
};
