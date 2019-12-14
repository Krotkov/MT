//
// Created by kranya on 09.12.2019.
//

#include "gtest/gtest.h"
#include "Parser.h"

TEST(correctness, empty) {
    auto x = std::string("");
    EXPECT_NO_THROW(Parser().parse(x));
}

TEST(correctness, bad_function) {
    auto x = std::string("fuunction e(): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_with_no_type) {
    auto x = std::string("function e();");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_without_name) {
    auto x = std::string("function (): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_without_brackets) {
    auto x = std::string("function aba: integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, bad_procedure) {
    auto x = std::string("proceduure aba();");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, procedure_with_type) {
    auto x = std::string("procedure aba(): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, procedure_bad_ending) {
    auto x = std::string("procedure aba(),");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, procedure_without_ending) {
    auto x = std::string("procedure aba()");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_with_untype_var) {
    auto x = std::string("function aba(a): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_with_untype_var2) {
    auto x = std::string("function aba(a: integer; b): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_with_bad_separator) {
    auto x = std::string("function aba(), integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_with_bad_var_separator) {
    auto x = std::string("function aba(a; b :integer): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, function_with_bad_var_separator2) {
    auto x = std::string("function aba(a :integer, b: double): integer;");
    EXPECT_THROW(Parser().parse(x), std::runtime_error);
}

TEST(correctness, big_function) {
    auto x = std::string("function abaa(a, b: integer; c, d: double): longint;");
    EXPECT_NO_THROW(Parser().parse(x));
}

TEST(correctness, big_procedure) {
    auto x = std::string("procedure abaa(a, b: integer; c, d: double);");
    EXPECT_NO_THROW(Parser().parse(x));
}

