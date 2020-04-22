#include "SingleSymbolStream.h"

void SingleSymbolStream::pattern_check(char input) {
    Token* temp_token = Tokenizer::generate_token(
        Tokenizer::dividing_symbols.find(this->prev_char)->second,
        "" + this->prev_char
    );
    *(this->token_addr) = *temp_token;
    delete temp_token;
    this->token_is_generated = true;

    this->stream_switcher.shift_chars(input);
    this->stream_switcher.check_comment();
    this->stream_switcher.check_dividing_symbol();
    this->stream_switcher.check_string();

    
    this->next_state = this->stream_switcher.get_stream();
    if (this->next_state == nullptr) {
        this->next_state = std::make_shared<KeywordStream>();
    }
    this->next_state->set_prev_char(input);
    this->state_is_changed = true;
}