#pragma once
#include <bits/stdc++.h>
#include "inputLexer.h"
#include <bits/stdc++.h>
#include "../Tree.h"

class inputParser {
    inputLexer lexer;
    Tree E();
    Tree E2();
    Tree F();
    Tree T();
    Tree T2();
public:
    inputParser() = default;
    void updateInput(std::string& input);
    Tree parse();
};
