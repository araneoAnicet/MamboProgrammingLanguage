#pragma once
#include "TokenStream.h"
#include "../Tokenizer.h"



class NumberStream: public TokenStream {
private:
    bool has_dot = false;
    void switch_state();
    void record_token();
    void record_token_and_switch_state();
public:
    void pattern_check(char input) override;
};