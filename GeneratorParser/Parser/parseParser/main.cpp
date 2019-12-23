//
// Created by kranya on 23.12.2019.
//

#include <bits/stdc++.h>
#include "generatorParser.tab.hpp"
#include "generatorParser.lexer.hpp"

void parser_error(const char* error) {
    std::cerr << error;
}

int parser_wrap() {
    return 1;
}

extern std::string* result;
extern std::unordered_map<std::string, std::vector<std::pair<std::vector<std::string>, std::string> > > neTermRules;

int main() {
    std::ifstream f("/home/kranya/MT/GeneratorParser/Parser/parseParser/input.txt");
    std::string str = "", str1;
    while (getline(f, str1)) {
        str += str1;
        str += "\n";
    }
    parser__scan_string(str.data());
    parser_parse();
    if (result != nullptr) {
        std::cout << *result << "\n";
    }
    return 0;
}
