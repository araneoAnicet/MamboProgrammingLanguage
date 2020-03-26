#pragma once
#include <string>
#include "../Tokenizer.h"


class TokenStream {
protected:
    TokenStream* next_state;
    bool state_is_changed = false;
    bool token_is_generated;
    std::string string_input;
    Token* token_addr;
    char prev_char;
public:
    virtual void interrupt_stream() = 0;
    void set_string_input(std::string string_input);
    void set_token_addr(Token* token_addr);
    bool has_generated_token();
    bool has_changed_state();
    TokenStream* get_next_state();
    void set_prev_char(char prev_char);
    virtual void pattern_check(char input) = 0;
};
