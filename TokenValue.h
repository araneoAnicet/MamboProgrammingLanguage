#pragma once
#include <string>


class TokenValue {
public:
    virtual std::string represent() = 0;
    virtual double get() = 0;
};
