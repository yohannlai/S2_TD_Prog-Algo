#pragma once

#include <string>
#include <vector>

std::vector<std::string> split_string(std::string const& s);

bool is_floating(std::string const& s);

float npi_evaluate(std::vector<std::string> const& tokens);

enum class Operator { ADD, SUB, MUL, DIV };
enum class TokenType { OPERATOR, OPERAND };

struct Token
{
    TokenType type;
    float value;
    Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);

float npi_evaluate_2(std::vector<Token> const& tokens);