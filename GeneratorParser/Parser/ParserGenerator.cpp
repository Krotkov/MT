//
// Created by kranya on 23.12.2019.
//

#include <bits/stdc++.h>
#include "ParserGenerator.h"

void parser_error(const char *error) {
    std::cerr << error;
}

int parser_wrap() {
    return 1;
}

std::string ParserGenerator::readFile(const std::string &file) {
    std::ifstream f(file);
    std::string ans = "", str;
    while (getline(f, str)) {
        ans += str;
        ans += "\n";
    }
    std::cout << ans << std::endl;
    return ans;
}

void ParserGenerator::countFirst(std::unordered_map<std::string, std::unordered_set<std::string>> &first) {
    bool change = true;
    while (change) {
        change = false;
        for (const auto &neTerm: neTermRules) {
            std::string name = neTerm.first;
            for (const auto &rule: neTerm.second) {
                auto terms = getFirstTerms(first, rule.first);
                auto &oldTerms = first[name];
                size_t oldSize = oldTerms.size();
                oldTerms.insert(terms.begin(), terms.end());
                if (oldSize != oldTerms.size()) change = true;
            }
        }
    }
}

std::unordered_set<std::string>
ParserGenerator::getFirstTerms(std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                               const std::vector<std::string> &tokens) {
    std::unordered_set<std::string> ans;
    if (tokens.empty()) {
        ans.insert("EPS");
    } else {
        for (const auto &token: tokens) {
            std::unordered_set<std::string> newTokens;
            if (neTerms.find(token) == neTerms.end()) {
                newTokens.insert(token);
            } else {
                newTokens.insert(first[token].begin(), first[token].end());
            }
            ans.insert(newTokens.begin(), newTokens.end());
            if (token != tokens.back()) {
                if (ans.find("EPS") != ans.end()) {
                    ans.erase("EPS");
                } else {
                    break;
                }
            }
        }
    }
    return ans;
}

void ParserGenerator::countFollow(std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                                  std::unordered_map<std::string, std::unordered_set<std::string>> &follow) {
    follow[startPoint].insert("END");
    bool change = true;
    while (change) {
        change = false;
        size_t commonSize = 0;
        for (auto a: follow) {
            commonSize += a.second.size();
        }
        for (const auto &neTerm: neTermRules) {
            std::string name = neTerm.first;
            for (const auto &rule: neTerm.second) {
                getFollowTerms(name, first, follow, rule.first);
            }
        }
        size_t newCommonSize = 0;
        for (auto a: follow) {
            newCommonSize += a.second.size();
        }
        if (commonSize != newCommonSize) change = true;
    }
}

void ParserGenerator::getFollowTerms(const std::string &curNeTerm,
                                     std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                                     std::unordered_map<std::string, std::unordered_set<std::string>> &follow,
                                     const std::vector<std::string> &tokens) {
    for (auto token1 = tokens.begin(); token1 < tokens.end(); token1++) {
        if (neTerms.find(*token1) != neTerms.end()) {
            std::unordered_set<std::string> curFirst;
            for (auto token2 = token1 + 1; token2 < tokens.end(); token2++) {
                if (neTerms.find(*token2) != neTerms.end()) {
                    curFirst.insert(first[*token2].begin(), first[*token2].end());
                    if (curFirst.find("EPS") != curFirst.end()) {
                        if (token2 + 1 != tokens.end()) curFirst.erase("EPS");
                    } else {
                        break;
                    }
                } else {
                    curFirst.insert(*token2);
                    break;
                }
            }
            if (curFirst.find("EPS") != curFirst.end() || curFirst.empty()) {
                curFirst.erase("EPS");
                follow[*token1].insert(follow[curNeTerm].begin(), follow[curNeTerm].end());
            }
            follow[*token1].insert(curFirst.begin(), curFirst.end());
        }
    }
}

std::pair<std::vector<std::string>, std::string>
ParserGenerator::findRule(const std::string &neTerm, const std::string &term,
                          std::unordered_map<std::string, std::unordered_set<std::string>> &first) {
    auto rules = neTermRules[neTerm];
    for (const auto &rule: rules) {
        if (!rule.first.empty()) {
            if (neTerms.find(rule.first[0]) != neTerms.end()) {
                size_t ind = 0;
                while (ind < rule.first.size() &&
                       neTerms.find(rule.first[ind]) != neTerms.end() && first[rule.first[ind]].find("EPS")
                                                                          != first[rule.first[ind]].end()) {
                    ind++;
                }
                for (size_t i = 0; i < std::min(ind+1, rule.first.size()); i++) {
                    if (neTerms.find(rule.first[i]) != neTerms.end()) {
                        if (first[rule.first[i]].find(term) != first[rule.first[i]].end()) return rule;
                    } else {
                        if (term == rule.first[i]) return rule;
                    }
                }
            } else {
                if (rule.first[0] == term) return rule;
            }
        }
    }
    throw std::runtime_error("Can't find rule");
}

void ParserGenerator::printRule(std::ofstream &file, std::pair<std::vector<std::string>, std::string>& rule) {
    int ind = 1;
    for (const auto& tt: rule.first) {
        if (neTerms.find(tt) != neTerms.end()) {
            file << "        auto val" << ind << " = " << tt << "();\n";
        } else {
            if (tt != "EPS") {
                file << "        auto val" << ind << " = lexer.tokenString();\n"
                     << "        lexer.nextToken();\n";
            }
        }
        ind++;
    }

    auto newCode = processCode(rule.second);

    file << "       " << newCode.first << "\n";
    if (!newCode.second) {
        file << "        " << commonType << " retVal;\n";
    }
    file << "       return retVal;\n";
}

std::pair<std::string, bool> ParserGenerator::processCode(std::string code) {
    for (size_t i = 1; i < 100; i++) {
        std::string oldVal = "$" + std::to_string(i);
        std::string newVal = "val" + std::to_string(i);
        while (code.find(oldVal) != std::string::npos) {
            code.replace(code.find(oldVal), oldVal.size(), newVal);
        }
    }
    if (code.find("$$") != std::string::npos) {
        code.replace(code.find("$$"), 2, "auto retVal");
        return {code, true};
    } else {
        return {code, false};
    }
}

void ParserGenerator::generateHppFile(const std::string &name, const std::string &fileName) {
    std::ofstream file(fileName);
    std::string tab = "    ";
    file << "#pragma once\n"
         << "#include <bits/stdc++.h>\n"
         << "#include \"" << name << "Lexer.h" << "\"\n"
         << header << "\n";

    file << "class " << name << "Parser {\n"
         << "    " << name << "Lexer lexer;\n";
    for (const auto &t: neTerms) {
        file << tab << commonType << " " << t << "();\n";
    }
    file << "public:\n"
         << "    " << name << "Parser() = default;\n"
         << "    void updateInput(std::string& input);\n"
         << "    " << commonType << " parse();\n"
         << "};\n";

}

void ParserGenerator::generateCppFile(const std::string &name, const std::string &fileName,
                                      std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                                      std::unordered_map<std::string, std::unordered_set<std::string>> &follow) {
    std::string className = name + "Parser";
    std::ofstream file(fileName);
    file << "#include <bits/stdc++.h>\n"
         << "#include \"" << name << "Parser.h\"\n\n"
         << "void " << className << "::updateInput(std::string& input) {\n"
         << "    lexer.updateInput(input);\n"
         << "}\n";

    file << commonType << " " << className << "::parse() {\n"
         << "    lexer.nextToken();\n"
         << "    return " << startPoint << "();\n"
         << "}\n";

    for (const auto &neTerm: neTerms) {
        file << commonType << " " << className << "::" << neTerm << "() {\n";
        bool needFollow = false;
        file << "    ";
        for (const auto &term: first[neTerm]) {
            if (term != "EPS") {
                file << "if (lexer.curToken() == " << term << ") {\n";
                auto rule = findRule(neTerm, term, first);
                printRule(file, rule);
                file << "    } else ";
            } else {
                needFollow = true;
            }
        }
        if (needFollow) {
            file << "if (";
            for (const auto& term: follow[neTerm]) {
                file << "lexer.curToken() == " << term << " || ";
            }
            file << "false) {\n";
            auto rule = findRule(neTerm, "EPS", first);
            printRule(file, rule);
            file << "    } else ";
        }
        file << "{\n"
             << "       throw new std::runtime_error(\"bad token\");\n";
        file << "    }\n";
        file << "}\n";
    }
}

void ParserGenerator::generate(const std::string &directory, const std::string &file) {
    std::string className = file + "Parser";
    std::string fileName = directory + "/" + file + ".y";
    std::string str = readFile(fileName);
    parser__scan_string(str.data());
    parser_parse();
    for (auto& rules: neTermRules) {
        for (auto& rule: rules.second) {
            auto& tokens = rule.first;
            if (tokens.empty()) tokens.emplace_back("EPS");
        }
    }
    std::unordered_map<std::string, std::unordered_set<std::string>> first, follow;
    countFirst(first);
    countFollow(first, follow);
    generateHppFile(file, directory + "/" + className + ".h");
    generateCppFile(file, directory + "/" + className + ".cpp", first, follow);
}


