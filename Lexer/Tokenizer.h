#pragma once
#include <map>
#include <string>
#include "Token.h"
#include <map>

// token types
#define MMB_STR 0
#define MMB_NUM 1
#define MMB_KEY 2
#define MMB_COMM 3
#define MMB_VAR 4
#define MMB_PLUS 5
#define MMB_MINUS 6
#define MMB_MULT 7
#define MMB_DIV 8
#define MMB_QUOTE_DOUBLE 9
#define MMB_QUOTE 10
#define MMB_BRCKT_OPN 11
#define MMB_BRCKT_CLS 12
#define MMB_BRCKT_OPN_SQR 13
#define MMB_BRCKT_CLS_SQR 14
#define MMB_BRCKT_OPN_FIG 15
#define MMB_BRCKT_CLS_FIG 16
#define MMB_DOT 17
#define MMB_NUM_FLOAT 18


class Tokenizer {
public:
    static std::map<char, int> dividing_symbols;
    static Token* generate_token(int token_type, std::string lexeme);
};
