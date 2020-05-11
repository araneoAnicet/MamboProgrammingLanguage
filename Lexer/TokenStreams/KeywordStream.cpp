#include "KeywordStream.h"

KeywordStream::KeywordStream() {
    this->tree.set_keywords({
        "func",
        "import",
        "loop",
        "if",
        "else",
        "or",
        "not",
        "and",
        "equals",
        "out",
        "next"
    });
}

void KeywordStream::set_prev_char(char prev_char) {
    this->tree.find_keyword(prev_char);
    if (this->tree.has_found_not_keyword()) {
        this->tree.refresh_temp_tree();
        // fix here
    }
}


void KeywordStream::switch_state() {
    this->next_state = this->stream_switcher.get_stream();
    this->next_state->set_token_addr(this->token_addr);
    this->state_is_changed = true;
}

void KeywordStream::record_token() {
    Token* temp_token_addr;
    if (this->tree.has_found_keyword()) {
        temp_token_addr = Tokenizer::generate_token(MMB_KEY, this->tree.get_keyword());
    } else {
        if (this->lexemes_have_only_digits) {
            temp_token_addr = Tokenizer::generate_token(MMB_NUM, this->string_input);
        } else {
            temp_token_addr = Tokenizer::generate_token(MMB_VAR, this->string_input);
        }
    }
    *(this->token_addr) = *temp_token_addr;
    delete temp_token_addr;
    this->token_is_generated = true;
}

void KeywordStream::record_token_and_switch_state() {
    this->record_token();
    this->switch_state();
}

void KeywordStream::pattern_check(char input) {

    this->stream_switcher.shift_chars(input);
    this->tree.find_keyword(input);

    if (!(this->stream_switcher.check_number())) {
        this->lexemes_have_only_digits = false;
    }

    if (this->stream_switcher.check_ignored_symbol()) {  // next state is KeywordStream    
        this->record_token_and_switch_state();
        this->next_state->set_prev_char(input);
        return;
    }

    if (this->stream_switcher.check_string()) {    
        this->record_token_and_switch_state();
        this->next_state->set_prev_char(input);
        return;
    }

    if (this->stream_switcher.check_dividing_symbol()) {
            this->record_token_and_switch_state();
            this->next_state->set_prev_char(input);
            return;
    }

    if (this->stream_switcher.check_variable()) {
        this->switch_state();
        this->next_state->set_string_input(this->string_input);
        this->next_state->set_prev_char(input);
    }
    
}