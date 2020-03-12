#pragma once
#include <string>


template<class T>
class TokenValue {
public:
    virtual std::string represent() = 0;
    virtual T get() = 0;
};