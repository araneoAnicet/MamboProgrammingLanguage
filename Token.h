#pragma once
#include "TokenValue.h"
#include <string>

template<class T>
struct Token {
    Token(std::string name, TokenValue<T>* value, int line_index, int expression_index) {
        this->name = name;
        this->value = value;
        this->line_index = line_index;
        this->expression_index = expression_index;
    }
    int line_index;
    int expression_index;
    TokenValue<T>* value;
    std::string name;
};
