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

void KeywordStream::interrupt_stream() {
    this->token_is_generated = false;
    this->ignore_input = false;
}

void KeywordStream::set_prev_char(char prev_char) {
    this->tree.find_keyword(prev_char);
    if (this->tree.has_found_not_keyword()) {
        this->tree.refresh_temp_tree();
        this->ignore_input = true;
    }
}

void KeywordStream::pattern_check(char input) {
    Token* temp_token_addr;

    if (input == '\'') {
        if (this->tree.has_found_keyword()) {
            temp_token_addr = Tokenizer::generate_token(MMB_KEY, tree.get_keyword());
            *(this->token_addr) = *temp_token_addr;
            delete temp_token_addr;
            this->token_is_generated = true;
        }
        this->next_state = std::make_shared<StringStream>();
        this->next_state->set_token_addr(this->token_addr);
        this->state_is_changed = true;
    }

    if (
        Tokenizer::dividing_symbols.find(input) != Tokenizer::dividing_symbols.end()
        || input == ' '
        || input == '\n'
        || input == '\t'
    ) {

        if (this->tree.has_found_keyword()) {
            temp_token_addr = Tokenizer::generate_token(MMB_KEY, tree.get_keyword());
            *(this->token_addr) = *temp_token_addr;
            delete temp_token_addr;
            this->token_is_generated = true;
        }
        this->tree.refresh_temp_tree();
        this->ignore_input = false;
        return;
    }
    if (!this->ignore_input) {
        this->tree.find_keyword(input);
        if (this->tree.has_found_not_keyword()) {
            this->tree.refresh_temp_tree();
            this->ignore_input = true;
        }
    }
    this->prev_char = input;
}