#pragma once

#include "token.h"

#include <memory>
#include <vector>

class tokenList
{
public:
    tokenList() {}
    tokenList(shared_ptr<token> obj) { add(obj); }

    void clear() { tokens.clear(); }
    void add(shared_ptr<token> obj) { tokens.push_back(obj); }
    std::vector<shared_ptr<token>> tokens;
};