#include "CommentStream.h"

void CommentStream::pattern_check(char input) {
    if (input == '\n') {
        this->next_state = std::make_shared<KeywordStream>();
        this->next_state->set_prev_char(input);
        this->next_state->set_token_addr(this->token_addr);
        this->has_changed_state = true;
    }
}