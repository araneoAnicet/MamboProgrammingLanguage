#pragma once
#include <string>


class Token {
public:
    Token(int type, std::string value, int id);
    int line_index;
    std::string value;
    int type;
    int id;
};
