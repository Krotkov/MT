//
// Created by kranya on 09.12.2019.
//

#include <iostream>
#include <set>
#include "Parser.h"

int main () {
    std::string str;
    getline(std::cin, str);
    Tree ans = Parser().parse(str);
    std::set<int> se;
    printTree(ans, 0, se);
    return 0;
}