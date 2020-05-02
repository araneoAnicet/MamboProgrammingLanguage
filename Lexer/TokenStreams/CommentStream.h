#pragma once
#include "TokenStream.h"



class CommentStream: public TokenStream {
public:
    void pattern_check(char input) override;
};