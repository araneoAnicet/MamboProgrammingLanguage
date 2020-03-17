#pragma once
#include "TokenStream.h"

class StringStream: public TokenStream {
    void set_first_character_input(char first_input) override;
    void set_string_input(std::string string_input) override;
    void set_token_addr(Token* token_addr) override;
    TokenStream* pattern_check(std::string input) override;
    bool has_changed_state() override;
};
