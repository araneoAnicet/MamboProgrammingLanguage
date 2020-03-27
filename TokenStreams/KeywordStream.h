#pragma once
#include "TokenStream.h"
#include "KeywordsTree.h"
#include "StringStream.h"
#include "../Tokenizer.h"
#include <iostream>


class KeywordStream: public TokenStream {
private:
    KeywordsTree tree;
    bool ignore_input = false;
public:
    KeywordStream();
    void set_prev_char(char prev_char);
    void interrupt_stream() override;
    void pattern_check(char input) override;
};
