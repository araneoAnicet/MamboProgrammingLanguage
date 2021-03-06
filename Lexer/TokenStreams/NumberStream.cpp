#include "NumberStream.h"

void NumberStream::switch_state() {
    this->next_state = this->stream_switcher.get_stream();
    this->next_state->set_token_addr(this->token_addr);
    this->has_changed_state = true;
}

void NumberStream::record_token() {
    Token* temp_token;
    
    temp_token = Tokenizer::generate_token(MMB_NUM, this->string_input);
    *(this->token_addr) = *temp_token;
    delete temp_token;
    this->has_generated_token = true;
}

void NumberStream::record_token_and_switch_state() {
    this->record_token();
    this->switch_state();
    }

void NumberStream::pattern_check(char input) {
    if (this->stream_switcher.check_number()) {
        this->stream_switcher.shift_chars(input);
        this->string_input += input;
        return;
    }

    if (this->stream_switcher.check_string()) {
        this->record_token_and_switch_state();
        return;
    }

    if (this->stream_switcher.check_comment()) {
        this->record_token_and_switch_state();
        return;
    }

    if (this->stream_switcher.check_dividing_symbol()) {
        this->record_token_and_switch_state();
        return;
    }

    if (this->stream_switcher.check_variable()) {
        this->stream_switcher.shift_chars(input);
        this->string_input += input;
        this->switch_state();
        this->next_state->set_string_input(this->string_input);
        this->next_state->set_prev_char(input);
        return;
    }
}