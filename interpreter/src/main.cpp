#include <iostream>
#include <fstream>
#include <string>

#include "commons.h"
#include "types/token.h"

using namespace std;

int runFromFile(string fileName);
void runPrompt();
vector<char> readBytesFromFile(string fileName);

int main(int argc, char const *argv[])
{
    if (argc > 2)
    {
        cout << "Usage: kaffe <file_path>";
        return 100;
    }
    else if (argc == 2)
    {
        cout << argv[1];
        int result = runFromFile(argv[0]);
    }
    else
    {
        runPrompt();
    }

    return 0;
}

int runFromFile(string fileName)
{
    ofstream file;
    program p;
    file.open(fileName);

    vector<char> bytes = readBytesFromFile(fileName);

    string src(bytes.begin(), bytes.end());

    p.run(src);

    if (program::hadError)
    {
        return 1;
    }

    return 0;
}

void runPrompt()
{
    program p;
    while (true)
    {
        string line;
        cout << "> ";
        cin >> line;
        if (line == "exit()")
        {
            break;
        }

        p.run(line);
        program::hadError = false;
    }
}

vector<char> readBytesFromFile(string fileName)
{
    ifstream ifs(fileName, ios::binary | ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    if (pos == 0)
    {
        return vector<char>{};
    }

    vector<char> result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);

    return result;
}