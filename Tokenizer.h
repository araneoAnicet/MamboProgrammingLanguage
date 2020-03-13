#pragma once
#include <map>
#include <string>
#include "Token.h"


class Tokenizer {
public:
    static std::map<char, std::string> dividing_symbols;
    Token* generate_token(std::string lexeme);
};

std::map<char, std::string> Tokenizer::dividing_symbols = {
        {'+', "PLUS"},
        {'-', "MINUS"},
        {'*', "MULT"},
        {'/', "DIV"},
        {'\"', "QUOTE_DOUBLE"},
        {'\'', "QUOTE"},
        {'(', "BRACKET_OPEN"},
        {')', "BRACKET_CLOSE"},
        {'[', "BRACKET_OPEN_SQR"},
        {']', "BRACKET_CLOSE_SQR"},
        {'{', "BRACKET_OPEN_FIG"},
        {'}', "BRACKET_CLOSE_FIG"}
};
