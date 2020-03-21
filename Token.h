#pragma once
#include <string>

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



struct Token {
    Token(int type, std::string value) {
        this->type = type;
        this->value = value;
    }
    int line_index;
    std::string value;
    int type;
};
