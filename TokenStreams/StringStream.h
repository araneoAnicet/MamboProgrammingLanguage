#pragma once
#include "TokenStream.h"
#include "../Tokenizer.h"
#include "KeywordStream.h"


class StringStream: public TokenStream {
public:
    StringStream();
    void set_prev_char(char prev_char);
    void interrupt_stream() override;
    void pattern_check(char input) override;
};
