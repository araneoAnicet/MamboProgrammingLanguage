#include "StringStream.h"
#include <iostream>


StringStream::StringStream() {
    std::cout << "Init String Stream" << std::endl;  // remove
}

void StringStream::set_prev_char(char prev_char) {
    this->prev_char = prev_char;
}

void StringStream::pattern_check(char input) {
    this->string_input += prev_char;
    this->prev_char = input;
    if (input == '\'') {
        this->token_is_generated = true;
        this->state_is_changed = true;
        this->next_state = new KeywordStream();
        this->next_state->set_token_addr(this->token_addr);
        Token* temp_token_addr = Tokenizer::generate_token(
            MMB_STR, std::string(this->string_input.begin() + 1, this->string_input.end())
            );
        std::cout << "Found string: " << std::string(this->string_input.begin() + 1, this->string_input.end()) << std::endl;  // remove
        *(this->token_addr) = *(temp_token_addr);
        delete temp_token_addr;
        return;
    }
}

void StringStream::interrupt_stream() {
    this->string_input = "";
    this->token_is_generated = false;
}