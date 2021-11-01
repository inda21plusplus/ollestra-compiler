#pragma once

#include <memory>
#include <string>
#include <vector>
#include <map>

#include "../types/token.h"
#include "../types/tokenList.h"

using namespace std;

class lexer
{
private:
    string src;
    int start = 0;
    int current = 0;
    int line = 1;

    bool endOfFile();
    char advance();
    void addToken(tokenType type);
    void addToken(tokenType type, string literal);
    bool match(char ex);
    char peek();
    char peekNext();
    void read_string();
    void number();
    void identifier();
    void block_comment();

public:
    lexer(string source) : src(source) {}

    tokenList tokens;

    tokenList scanTokens();
    void scanToken();
};

static map<string, tokenType> keywords =
    {{"heltal", INTEGER},
     {"decimaltal", DECIMAL},
     {"och", AND},
     {"eller", OR},
     {"grupp", CLASS},
     {"annars", ELSE},
     {"falskt", FALSE},
     {"sant", TRUE},
     {"varje", FOR},
     {"när", WHILE},
     {"om", IF},
     {"inget", NIL},
     {"ge", RETURN},
     {"super", SUPER},
     {"denna", THIS}};