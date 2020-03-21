#include "TokenStream.h"


void TokenStream::set_string_input(std::string string_input) {
    this->string_input = string_input;
}

void TokenStream::set_token_addr(Token* token_addr) {
    this->token_addr = token_addr;
}

bool TokenStream::has_changed_state() {
    return this->changed_state;
}

TokenStream* TokenStream::get_next_state() {
    return this->next_state;
}

bool TokenStream::has_generated_token() {
    return this->token_is_generated;
}

