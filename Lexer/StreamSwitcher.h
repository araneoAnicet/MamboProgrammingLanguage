#pragma once
#include "Token.h"
#include "Tokenizer.h"
#include "TokenStreams/KeywordStream.h"
#include "TokenStreams/StringStream.h"
#include "TokenStreams/CommentStream.h"
#include "TokenStreams/KeywordStream.h"
#include "TokenStreams/NumberStream.h"
#include "TokenStreams/SingleSymbolStream.h"
#include "TokenStreams/VariableStream.h"
#include <map>



class StreamSwitcher {
private:
    std::shared_ptr<TokenStream> current_stream = nullptr;
    char current_char;
    char prev_char;
public:
    void shift_chars(char input);
    bool check_ignored_symbol();
    bool check_dividing_symbol();
    bool check_string();
    bool check_comment();
    bool check_number();
    bool check_variable();
    std::shared_ptr<TokenStream> get_stream();
};
