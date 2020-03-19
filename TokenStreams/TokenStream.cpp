#include "TokenStream.h"


void TokenStream::set_string_input(std::string string_input) {
    this->string_input = string_input;
}

void TokenStream::set_token_addr(Token* token_addr) {
    this->token_addr = token_addr;
}

void TokenStream::set_first_character_input(char first_input) {
    this->prev_input = first_input;
}

bool TokenStream::has_changed_state() {
    return this->has_changed_state;
}

