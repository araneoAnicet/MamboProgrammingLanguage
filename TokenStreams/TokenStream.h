#pragma once
#include <string>
#include "../Token.h"


class TokenStream {
protected:
    bool token_is_generated;
    std::string string_input;
    Token* token_addr;
public:
    void set_string_input(std::string string_input);
    void set_token_addr(Token* token_addr);
    bool has_generated_token();
    virtual TokenStream* pattern_check(char input) = 0;
};
