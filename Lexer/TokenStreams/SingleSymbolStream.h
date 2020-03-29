#include "TokenStream.h"

class SingleSymbolStream: public TokenStream {
public:
    // FINISH LATER
    void interrupt_stream() override;
    void pattern_check(char input) override;
};