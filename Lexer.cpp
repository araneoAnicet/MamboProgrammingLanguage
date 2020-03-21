#include "Lexer.h"
#include "TokenStreams/TokenStream.h"

std::vector<Token*> Lexer::tokenize() {
    return this->tokens;
}

void Lexer::identify_lexemes(std::string filename) {
    TokenStream* token_stream;
    Token* temp_token = nullptr;
    std::fstream file(filename);
    std::string line;
    int line_index = 1;
    token_stream->set_token_addr(temp_token);
    while(std::getline(file, line)) {
        for (char character : line) {
            token_stream = token_stream->pattern_check(character);
            if (token_stream->has_generated_token()) {
                temp_token->line_index = line_index;
                this->tokens.push_back(temp_token);
            }
        }
        line_index++;
    }
}