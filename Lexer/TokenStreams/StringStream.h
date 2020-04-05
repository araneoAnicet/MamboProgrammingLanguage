#pragma once
#include "TokenStream.h"
#include "../Tokenizer.h"
#include "KeywordStream.h"


class StringStream: public TokenStream {
public:
    void pattern_check(char input) override;
};
