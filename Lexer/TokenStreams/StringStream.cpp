#include "StringStream.h"


void StringStream::pattern_check(char input) {
    this->string_input += prev_char;
    this->prev_char = input;
    if (input == '\'') {
        this->token_is_generated = true;
        this->state_is_changed = true;
        this->next_state = std::make_shared<TokenStream>(new KeywordStream());
        this->next_state->set_token_addr(this->token_addr);
        Token* temp_token_addr = Tokenizer::generate_token(
            MMB_STR, std::string(this->string_input.begin() + 1, this->string_input.end())
            );
        *(this->token_addr) = *(temp_token_addr);
        delete temp_token_addr;
        return;
    }
}

void StringStream::interrupt_stream() {
    this->string_input = "";
    this->token_is_generated = false;
}