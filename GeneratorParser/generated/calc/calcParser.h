#pragma once
#include <bits/stdc++.h>
#include "calcLexer.h"
#include <bits/stdc++.h>
#include "../Tree.h"

class calcParser {
    calcLexer lexer;
    Tree E();
    Tree E2();
    Tree F();
    Tree T();
    Tree T2();
public:
    calcParser() = default;
    void updateInput(std::string& input);
    Tree parse();
};
