//
// Created by kranya on 23.12.2019.
//

#ifndef PARSERGENERATOR_PARSERGENERATOR_H
#define PARSERGENERATOR_PARSERGENERATOR_H

#include "parseParser/parseParser.h"

extern std::string *result;
extern std::unordered_map<std::string, std::vector<std::pair<std::vector<std::string>, std::string> > > neTermRules;
extern std::set<std::string> neTerms;
extern std::string startPoint;
extern std::string header;
extern std::string commonType;

class ParserGenerator {
    static std::string readFile(const std::string &file);

    static void countFirst(std::unordered_map<std::string, std::unordered_set<std::string>> &first);

    static std::unordered_set<std::string>
    getFirstTerms(std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                  const std::vector<std::string> &tokens);

    static void countFollow(std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                            std::unordered_map<std::string, std::unordered_set<std::string>> &second);

    static void
    getFollowTerms(const std::string &curNeTerm,
                   std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                   std::unordered_map<std::string, std::unordered_set<std::string>> &second,
                   const std::vector<std::string> &tokens);

    static void generateHppFile(const std::string &name, const std::string &fileName);

    static void generateCppFile(const std::string &name,
                                const std::string &fileName,
                                std::unordered_map<std::string, std::unordered_set<std::string>> &first,
                                std::unordered_map<std::string, std::unordered_set<std::string>> &follow);

    static std::pair<std::vector<std::string>, std::string> findRule(const std::string &neTerm, const std::string &term,
                                                                     std::unordered_map<std::string, std::unordered_set<std::string>> &first);

    static void printRule(std::ofstream &file, std::pair<std::vector<std::string>, std::string>& rule);

    static std::pair<std::string, bool> processCode(std::string code);

public:
    static void generate(const std::string &directory, const std::string &file);
};


#endif //PARSERGENERATOR_PARSERGENERATOR_H
