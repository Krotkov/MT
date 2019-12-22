//
// Created by kranya on 22.12.2019.
//

#ifndef MT_GENERATOR_H
#define MT_GENERATOR_H

#include <bits/stdc++.h>
#include "generatorGrammar.tab.hpp"
#include "generatorGrammar.lexer.hpp"

extern std::string* result;
extern std::vector< std::pair<std::string, std::string> > regToCode;
extern std::vector<std::string> tokens;
extern std::string header;
extern std::unordered_set<std::string> skipp;

class Generator {
    static void generateLexer(const std::string& directory, const std::string& fileName);
    static std::string readFile(const std::string& name);
public:
    static void generate(const std::string& directory, const std::string& fileName);
};


#endif //MT_GENERATOR_H
