#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <iterator>
#include <cctype>


// Exercice 1
std::vector<std::string> split_string(std::string const& s);
bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);

// Exercice 2
enum class Operator { ADD, SUB, MUL, DIV, POW };
enum class TokenType { OPERATOR, OPERAND };

struct Token {
    TokenType type;
    float value;
    Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);

float npi_evaluate(std::vector<Token> const& tokens);