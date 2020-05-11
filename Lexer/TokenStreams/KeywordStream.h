#pragma once
#include "TokenStream.h"
#include "KeywordsTree.h"
#include "StringStream.h"
#include "../Tokenizer.h"


class KeywordStream: public TokenStream {
private:
    KeywordsTree tree;
    bool lexemes_have_only_digits = true;
    void switch_state();
    void record_token();
    void record_token_and_switch_state();
public:
    KeywordStream();
    void set_prev_char(char prev_char);
    void pattern_check(char input) override;
};
