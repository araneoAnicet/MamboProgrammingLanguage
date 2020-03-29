#include "Token.h"
#include "Tokenizer.h"
#include "TokenStreams/KeywordStream.h"
#include "TokenStreams/StringStream.h"
#include <map>


// token stream flags
#define FLAG_DIV_SYMB 0
#define FLAG_STR 1
#define FLAG_COMM 2
#define FLAG_NUM 3
#define FLAG_VAR 4

class StreamSwitcher {
private:
    std::map<int, TokenStream*> flags;

public:
    StreamSwitcher();
    bool check_dividing_symbol(char input);
    bool check_string(char input);
    bool check_comment(char input);
    bool check_number(char input);
    bool check_variable(char input);
    TokenStream* switch_stream();
};
