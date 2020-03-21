#pragma once
#include <string>
#include "../Token.h"


class TokenStream {
protected:
    static TokenStream* instance;
    TokenStream* next_state;
    bool changed_state = false;
    bool token_is_generated;
    std::string string_input;
    Token* token_addr;
public:
    virtual void generate_instance() = 0;
    void set_string_input(std::string string_input);
    void set_token_addr(Token* token_addr);
    bool has_generated_token();
    bool has_changed_state();
    TokenStream* get_next_state();
    virtual void pattern_check(char input) = 0;
};
