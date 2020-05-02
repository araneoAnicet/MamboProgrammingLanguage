#include "CommentStream.h"

void CommentStream::pattern_check(char input) {
    if (input == '\n') {
        this->next_state = std::make_shared<KeywordStream>();
        this->next_state->set_prev_char(input);
        this->has_changed_state = true;
        this->stream_switcher.shift_chars(input);
    }
}