#pragma once
#include "TokenValue.h"
#include <string>

// token types
#define MMB_STR 0
#define MMB_NUM 1
#define MMB_KEY 2
#define MMB_COMM 3
#define MMB_VAR 4



struct Token {
    Token(std::string name, int type, std::string value) {
        this->name = name;
        this->type = type;
        this->value = value;
    }
    int line_index;
    std::string value;
    int type;
    std::string name;
};
