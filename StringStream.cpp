#include "StringStream.h"

void StringStream::set_string_input(std::string string_input) {
    this->string_input = string_input;
}

void StringStream::set_token_addr(Token* token_addr) {
    this->token_addr = token_addr;
}

void StringStream::set_first_character_input(char first_input) {
    this->prev_input = first_input;
}

bool StringStream::has_changed_state() {
    return this->has_changed_state;
}

