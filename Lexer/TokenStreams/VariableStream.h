#pragma once
#include "TokenStream.h"

class VariableStream: public TokenStream {
private:
    void switch_state();
    void record_token();
    void record_token_and_switch_state();
public:
    void pattern_check(char input) override;
};