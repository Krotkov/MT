#pragma once
#include <bits/stdc++.h>
#include "inputLexer.h"
#include <bits/stdc++.h>

class inputParser {
    inputLexer lexer;
    int E();
    int E2();
    int F();
    int T();
    int T2();
public:
    inputParser() = default;
    void updateInput(std::string& input);
    void parse();
};
