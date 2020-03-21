#pragma once
#include <map>
#include <string>
#include "Token.h"


class Tokenizer {
public:
    static std::map<char, int> dividing_symbols;
    template<int token_type>
    static Token* generate_token(std::string lexeme);
};

std::map<char, int> Tokenizer::dividing_symbols = {
        {'+', MMB_PLUS},
        {'-', MMB_MINUS},
        {'*', MMB_MULT},
        {'/', MMB_DIV},
        {'\"', MMB_QUOTE_DOUBLE},
        {'\'', MMB_QUOTE},
        {'(', MMB_BRCKT_OPN},
        {')', MMB_BRCKT_CLS},
        {'[', MMB_BRCKT_OPN_SQR},
        {']', MMB_BRCKT_CLS_SQR},
        {'{', MMB_BRCKT_OPN_FIG},
        {'}', MMB_BRCKT_CLS_FIG}
};
