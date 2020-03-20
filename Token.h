#pragma once
#include "TokenValue.h"
#include <string>


struct Token {
    Token(std::string name, std::string type, TokenValue* value, int line_index) {
        this->name = name;
        this->type = type;
        this->value = value;
        this->line_index = line_index;
    }
    int line_index;
    TokenValue* value;
    std::string type;
    std::string name;
};
