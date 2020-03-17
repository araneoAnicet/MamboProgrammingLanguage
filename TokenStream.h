#pragma once
#include <string>
#include "Token.h"


class TokenStream {
protected:
    char prev_input;
    bool state_is_chanched;
    std::string string_input;
    Token* token_addr;
public:
    virtual void set_first_character_input(char first_input) = 0;
    virtual void set_string_input(std::string string_input) = 0;
    virtual void set_token_addr(Token* token_addr);
    virtual TokenStream* pattern_check(std::string input) = 0;
    virtual bool has_changed_state() = 0;
};
