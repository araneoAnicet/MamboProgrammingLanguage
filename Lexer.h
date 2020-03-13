#pragma once
#include "Token.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class Lexer {
private:
    std::vector<Token*> tokens;
public:
    void identify_lexemes(std::string filename);
    std::vector<Token*> tokenize();
};