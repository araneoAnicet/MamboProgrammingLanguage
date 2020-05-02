#include "StreamSwitcher.h"


void StreamSwitcher::shift_chars(char input) {
    this->prev_char = this->current_char;
    this->current_char = input;
}

bool StreamSwitcher::check_dividing_symbol() {
    if (Tokenizer::dividing_symbols.find(this->current_char) == Tokenizer::dividing_symbols.end()) {
        this->current_stream = std::make_shared<SingleSymbolStream>();
        return true;
    }
    return false;
}

bool StreamSwitcher::check_string() {
    if (this->current_char == '\'') {
        this->current_stream = std::make_shared<StringStream>();
        return true;
    }
    return false;
}

bool StreamSwitcher::check_comment() {
    if (this->current_char == '/' && this->prev_char == '/') {
        this->current_stream = std::make_shared<CommentStream>();
        return true;
    }
    return false;
}

bool StreamSwitcher::check_number() {
    if (this->current_char > 47 && this->current_char < 58) {
        this->current_stream = std::make_shared<NumberStream>();
        return true;
    }
    return false;
}

bool StreamSwitcher::check_variable() {
    if (
        (this->current_char > 64 && this->current_char < 91)
    || (this->current_char > 96 && this->current_char < 123)
    || (this->current_char == 95)
    ) {
        this->current_stream = std::make_shared<VariableStream>();
        return true;
    }
    return false;
}

std::shared_ptr<TokenStream> StreamSwitcher::get_stream() {
    return this->current_stream;
}
