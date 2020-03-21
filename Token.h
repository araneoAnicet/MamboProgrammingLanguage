#pragma once
#include "TokenValue.h"
#include <string>


struct Token {
    Token(std::string name, std::string type, TokenValue* value) {
        this->name = name;
        this->type = type;
        this->value = value;
    }
    int line_index;
    TokenValue* value;
    std::string type;
    std::string name;
};
