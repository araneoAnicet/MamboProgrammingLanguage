#pragma once
#include "Token.h"
#include "Tokenizer.h"
#include "TokenStreams/KeywordStream.h"
#include "TokenStreams/StringStream.h"
#include <map>


class StreamSwitcher {
private:
    std::shared_ptr<TokenStream> current_stream;
    char current_char;
    char prev_char;
public:
    void shift_chars(char input);
    bool check_dividing_symbol();
    bool check_string();
    bool check_comment();
    bool check_number();
    bool check_variable();
    std::shared_ptr<TokenStream> get_stream();
};
