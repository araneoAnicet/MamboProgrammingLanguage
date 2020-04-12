#include "Tokenizer.h"


Token* Tokenizer::generate_token(int token_type, std::string lexeme) {
    return new Token(token_type, lexeme);
}

std::map<char, int> Tokenizer::dividing_symbols = {
        {'+', MMB_PLUS},
        {'-', MMB_MINUS},
        {'*', MMB_MULT},
        {'\"', MMB_QUOTE_DOUBLE},
        {'\'', MMB_QUOTE},
        {'(', MMB_BRCKT_OPN},
        {')', MMB_BRCKT_CLS},
        {'[', MMB_BRCKT_OPN_SQR},
        {']', MMB_BRCKT_CLS_SQR},
        {'{', MMB_BRCKT_OPN_FIG},
        {'}', MMB_BRCKT_CLS_FIG},
        {'.', MMB_DOT}
};

