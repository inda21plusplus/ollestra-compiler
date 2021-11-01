#pragma once

#include <string>
#include <iostream>

#include "tokenType.h"

using namespace std;

class token
{
public:
    token(tokenType t, string le, string li, int l) : type(t), lexeme(le), literal(li), line(l) {}

    const tokenType type;
    const string lexeme;
    const string literal;
    const int line;
};

inline ostream &operator<<(ostream &out, const token &t)
{
    return out << t.type << ' ' << t.lexeme << ' ' << t.literal << "\n";
}