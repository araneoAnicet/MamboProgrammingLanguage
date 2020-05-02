#pragma once
#include <string>
#include <memory>
#include "../Tokenizer.h"
#include "../StreamSwitcher.h"

class StreamSwitcher;

class TokenStream {
protected:
    std::shared_ptr<TokenStream> next_state;
    bool state_is_changed = false;
    StreamSwitcher stream_switcher;
    bool token_is_generated = false;
    std::string string_input;
    Token* token_addr;
    char prev_char;
public:
    void set_string_input(std::string string_input);
    void set_token_addr(Token* token_addr);
    bool has_generated_token();
    bool has_changed_state();
    std::shared_ptr<TokenStream> get_next_state();
    void set_prev_char(char prev_char);
    virtual void pattern_check(char input) = 0;
};
