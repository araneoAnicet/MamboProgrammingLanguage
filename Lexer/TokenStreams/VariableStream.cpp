#include "VariableStream.h"

void VariableStream::record_token() {
    Token* temp_token = Tokenizer::generate_token(MMB_VAR, this->string_input);
    (*this->token_addr) = *temp_token;
    delete temp_token;
    this->token_is_generated = true;
}

void VariableStream::switch_state() {
    this->next_state = this->stream_switcher.get_stream();
    this->next_state->set_token_addr(this->token_addr);
    this->has_changed_state = true;
}

void VariableStream::record_token_and_switch_state() {
    this->record_token();
    this->switch_state();
}

void VariableStream::pattern_check(char input) {
    
    this->stream_switcher.shift_chars(input);
    if (this->stream_switcher.check_comment()) {
        this->record_token_and_switch_state();
        this->next_state->set_prev_char(input);
        return;
    }
    if (this->stream_switcher.check_dividing_symbol()) {
        this->record_token_and_switch_state();
        this->next_state->set_prev_char(input);
        return;
    }
    if (this->stream_switcher.check_string()) {
        this->record_token_and_switch_state();
        this->next_state->set_prev_char(input);
        return;
    }
    this->string_input += input;
    
}