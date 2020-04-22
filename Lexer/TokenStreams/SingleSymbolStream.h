#include "TokenStream.h"

class SingleSymbolStream: public TokenStream {
public:
    void pattern_check(char input) override;
};
