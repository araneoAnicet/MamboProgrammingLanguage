#include "Lexer.h"
#include "TokenStreams/TokenStream.h"
#include "TokenStreams/KeywordStream.h"


std::vector<Token> Lexer::tokenize() {
    return this->tokens;
}

void Lexer::identify_lexemes(std::string filename) {
    TokenStream* token_stream = new KeywordStream();
    TokenStream* prev_state;
    Token* temp_token = new Token(0, "");
    std::fstream file(filename);
    std::string line;
    int line_index = 1;
    int token_id = 0;
    token_stream->set_token_addr(temp_token);
    while(std::getline(file, line)) {
        for (char character : line) {
            std::cout << "Current char: " << character << std::endl;  // remove
            token_stream->pattern_check(character);
            if (token_stream->has_generated_token()) {
                temp_token->line_index = line_index;
                temp_token->id = token_id;
                token_id++;
                std::cout << "Found token value: " << temp_token->value << std::endl;  // remove 
                this->tokens.push_back(*temp_token);
                token_stream->interrupt_stream();
            }

            if (token_stream->has_changed_state()) {
                std::cout << "Entered changing state" << std::endl;  // remove
                prev_state = token_stream;
                token_stream = token_stream->get_next_state();
                token_stream->set_prev_char(character);
                prev_state->reset_state_status();
                prev_state->interrupt_stream();
                delete prev_state;
            }
        }
        line_index++;
    }
    delete temp_token;
}