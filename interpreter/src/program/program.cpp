#include "program.h"
#include "../lexer/lexer.h"
#include "../types/tokenList.h"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

void program::run(string src)
{
    //cout << src;
    lexer lex(src);
    tokenList list = lex.scanTokens();

    for (auto token : list.tokens)
    {
        cout << token << endl;
    }
}

void program::error(int line, string message)
{
    report(line, "", message);
}

void program::report(int line, string where, string message)
{
    cout << line << " | Error" << where << ": " << message << endl;
    hadError = true;
}