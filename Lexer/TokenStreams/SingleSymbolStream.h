#include "TokenStream.h"
#include "KeywordStream.h"

class SingleSymbolStream: public TokenStream {
public:
    void pattern_check(char input) override;
};
