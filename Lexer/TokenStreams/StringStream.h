#pragma once
#include "TokenStream.h"
#include "../Tokenizer.h"
#include "KeywordStream.h"


class StringStream: public TokenStream {
public:
    void interrupt_stream() override;
    void pattern_check(char input) override;
};
