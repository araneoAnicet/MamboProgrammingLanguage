#include "StreamSwitcher.h"


int StreamSwitcher::get_flag() {
    return this->switch_flag;
}

bool StreamSwitcher::check_dividing_symbol(char input) {
    this->prev_char = input;
    if (Tokenizer::dividing_symbols.find(input) == Tokenizer::dividing_symbols.end()) {
        this->switch_flag = FLAG_DIV_SYMB;
        return true;
    }
    return false;
}

bool StreamSwitcher::check_string(char input) {
    if (input == '\'') {
        this->switch_flag = FLAG_STR;
        this->prev_char = input;
        return true;
    }
    this->prev_char = input;
    return false;
}

bool StreamSwitcher::check_comment(char input) {
    if (input == '/') {
        this->switch_flag = FLAG_COMM;
        return true;
    }
    return false;
}

bool StreamSwitcher::check_number(char input) {
    if (input > 47 && input < 58) {
        this->prev_char = input;
        this->switch_flag = FLAG_NUM;
        return true;
    }
    return false;
}

bool StreamSwitcher::check_variable(char input) {
    if ((input > 64 && input < 91) || (input > 96 && input < 123) || (input == 95)) {
        this->prev_char = input;
        this->switch_flag = FLAG_VAR;
        return true;
    }
    return false;
}

std::shared_ptr<TokenStream> StreamSwitcher::get_stream() {
    switch(this->switch_flag) {
        case FLAG_STR: return std::make_shared<StringStream>();
            break;
        case FLAG_COMM: return std::make_shared<CommentStream>();
            break;
        case FLAG_DIV_SYMB: return std::make_shared<SingleSymbolStream>();
            break;
        case FLAG_NUM: return std::make_shared<NumberStream>();
            break;
        case FLAG_VAR: return std::make_shared<VariableStream>();
            break;
    }
}