#pragma once
#include "TokenStream.h"

class StringStream: public TokenStream {
    TokenStream* pattern_check(std::string input) override;  // define later
};
