#include "Token.h"

Token::Token(int type, std::string value, int id) {
        this->type = type;
        this->value = value;
        this->id = id;
}