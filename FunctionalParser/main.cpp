//
// Created by kranya on 15.12.2019.
//

#include <bits/stdc++.h>
#include "grammar.tab.hpp"
#include "grammar.lexer.hpp"

using namespace std;

extern string* result;

void yyerror(const char* error) {
    cerr << error;
}

int yywrap() {
    return 1;
}

int main() {
    freopen("/home/kranya/MT/FunctionalParser/input.l", "r", stdin);
    string str, str1;
    while (getline(cin, str1)) {
        str += str1;
        str += "\n";
    }
    yy_scan_string(str.data());
    yyparse();
    if (result != nullptr) {
        cout << *result << endl;
    }
    return 0;
}