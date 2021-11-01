#pragma once
#include <string>

using namespace std;
class program
{
private:
    int code;

    static void report(int line, string where, string message);

public:
    void run(string src);

    static void error(int line, string message);

    static inline bool hadError = false;
};