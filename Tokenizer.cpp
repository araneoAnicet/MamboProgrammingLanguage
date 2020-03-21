#include "Tokenizer.h"

template<int token_type>
Token* Tokenizer::generate_token(std::string lexeme) {
    return new Token(token_type, lexeme);
}
