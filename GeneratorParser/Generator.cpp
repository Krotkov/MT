//
// Created by kranya on 22.12.2019.
//

#include "Generator.h"

void yyerror(const char* error) {
    std::cerr << error;
}

int yywrap() {
    return 1;
}

void Generator::generateLexer(const std::string &directory, const std::string &fileName) {
    std::string lex = readFile(directory + "/" + fileName + ".l");
    yy_scan_string(lex.data());
    yyparse();
    std::string name = fileName + "Lexer";
    std::ofstream hFile(directory + "/" + (name + ".h"));
    hFile << "#pragma once\n"
          << "#include <bits/stdc++.h>\n";
    hFile << header << "\n";
    hFile << "enum Token {\n"
          << "  ";
    std::reverse(tokens.begin(), tokens.end());
    for (auto token: tokens) {
        hFile << token << ", ";
    }
    hFile << "END";
    hFile << "\n};\n";

    std::string className = fileName + "Lexer";

    std::string tab = "    ";

    hFile << "class " << className << "{\n"
          << "public:\n"
          << tab << className << "();\n"
          << tab << "void updateInput(const std::string& input);\n"
          << tab << "void nextToken();\n"
          << tab << "Token curToken();\n"
          << tab << "std::string tokenString();\n"
          << "private:\n"
          << tab << "Token findNextToken();\n"
          << tab << "Token _curToken;\n"
          << tab << "std::string _tokenString;\n"
          << tab << "std::string input;\n"
          << tab << "std::size_t curPos;\n"
          << tab << "std::unordered_set<Token> skips;\n"
          << tab << "std::unordered_map<Token, std::regex> tokenRegex;\n"
          << "};\n";

    std::ofstream cppFile(directory + "/" + (name + ".cpp"));
    cppFile << "#include <bits/stdc++.h>\n"
            << "#include \"" << className << ".h\"" << "\n\n"
            << className << "::" << className << "() {\n"
            << tab << "curPos = 0;\n"
            << tab << "skips = { ";
    for (auto skip = ++skipp.begin(); skip != skipp.end(); skip++) {
        cppFile << *skip << ", ";
    }
    cppFile << *skipp.begin() << " };\n}\n\n";

    cppFile << "Token " << className << "::curToken() {\n"
            << tab << "return _curToken;\n"
            << "}\n\n";

    cppFile << "void " << className << "::updateInput(const std::string& newInput) {\n"
            << tab << "input = newInput;\n"
            << tab << "curPos = 0;\n"
            << "}\n\n";

    cppFile << "std::string " << className << "::tokenString() {\n"
            << tab << "return _tokenString;\n"
            << "}\n\n";

    cppFile << "void " << className << "::nextToken() {\n"
            << tab << "Token t = findNextToken();\n"
            << tab << "while (skips.find(t) != skips.end()) {\n"
            << tab << tab << "t = findNextToken();\n"
            << tab << "}\n"
            << tab << "_curToken = t;\n"
            << "}\n\n";

    cppFile << "Token " << className << "::findNextToken() {\n";
    cppFile << tab << "std::smatch m;\n";
    for (const auto& pr: regToCode) {
        cppFile << tab << "if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R\"(^" << pr.first << ")\"))) {\n"
                << tab << tab << "curPos += m.str().size();\n"
                << tab << tab << "_tokenString = m.str();\n"
                << tab << tab << pr.second
                << tab << "}\n";
    }
    cppFile << tab << "if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(\"$\"))) {\n"
            << tab << tab << "curPos += m.str().size();\n"
            << tab << tab << "_tokenString = m.str();\n"
            << tab << tab << "return END;\n"
            << tab << "}\n";
    cppFile << tab << "throw new std::runtime_error(\"bad argument\");\n";
    cppFile << "}\n";
};

void Generator::generate(const std::string &directory, const std::string &fileName) {
    generateLexer(directory, fileName);
}

std::string Generator::readFile(const std::string & file) {
    std::string ans = "", str;
    std::ifstream f(file);
    while (getline(f, str)) {
        ans += str;
        ans += "\n";
    }
    return ans;
}
