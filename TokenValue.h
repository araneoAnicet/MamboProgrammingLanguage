#pragma once
#include <string>


template<class T>
class TokenValue {
public:
    virtual TokenValue(std::string stringed_value) = 0;
    virtual std::string represent() = 0;
    virtual T get() = 0;
};
