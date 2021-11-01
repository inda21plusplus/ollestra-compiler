#include "lexer.h"
#include "../program/program.h"

tokenList lexer::scanTokens()
{
    while (!endOfFile())
    {
        start = current;
        scanToken();
    }

    tokens.add(make_shared<token>(ENDOF, "", string(), line));
    return tokens;
}

void lexer::scanToken()
{
    char c = advance();
    switch (c)
    {
    case '(':
        addToken(LEFT_PAREN);
        break;
    case ')':
        addToken(RIGHT_PAREN);
        break;
    case '[':
        addToken(LEFT_BRACK);
        break;
    case ']':
        addToken(RIGHT_BRACK);
        break;
    case '{':
        addToken(LEFT_BRACE);
        break;
    case '}':
        addToken(RIGHT_BRACE);
        break;
    case ',':
        addToken(COMMA);
        break;
    case '.':
        addToken(DOT);
        break;
    case '-':
        addToken(MINUS);
        break;
    case '+':
        addToken(PLUS);
        break;
    case ';':
        addToken(SEMICOLON);
        break;
    case '*':
        addToken(STAR);
        break;
    case '!':
        addToken(match('=') ? NEG_EQUAL : NEG);
        break;
    case '=':
        addToken(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
    case '<':
        addToken(match('=') ? LESS_EQUAL : LESS);
        break;
    case '>':
        addToken(match('=') ? GREATER_EQUAL : GREATER);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && !endOfFile())
            {
                advance();
            }
        }
        else if (match('*'))
        {
        }
        else
        {
            addToken(SLASH);
        }
    case ' ':
    case '\r':
    case '\t':
        break;
    case '\n':
        line++;
        break;
    case '"':

    default:
        if (isdigit(c))
        {
            number();
        }
        else if (isalpha(c))
        {
            identifier();
        }
        else
        {
            program::error(line, "Unexpected character.");
        }
        break;
    }
}

bool lexer::endOfFile()
{
    return current >= src.length();
}

char lexer::advance()
{
    return src[current++];
}

void lexer::addToken(tokenType type)
{
    addToken(type, string());
}

void lexer::addToken(tokenType type, string literal)
{
    string txt = src.substr(start, current);
    tokens.add(make_shared<token>(type, txt, literal, line));
}

bool lexer::match(char ex)
{
    if (endOfFile())
        return false;
    if (src[current] != ex)
        return false;

    current++;
    return true;
}

char lexer::peek()
{
    if (endOfFile())
        return '\0';

    return src[current];
}

char lexer::peekNext()
{
    if (current + 1 >= src.length())
        return '\0';

    return src[current + 1];
}

void lexer::read_string()
{
    while (peek() != '"' && !endOfFile())
    {
        if (peek() == '\n')
            line++;
        advance();
    }

    if (endOfFile())
    {
        program::error(line, "Unfinished string.");
        return;
    }

    advance();

    string val = src.substr(start + 1, current - 1);
    addToken(STRING, val);
}

void lexer::block_comment()
{
    while (peek() != '*' && peekNext() != '/')
    {
        if (peek() == '\n')
            line++;
        advance();
    }

    if (endOfFile())
    {
        program::error(line, "Unfinished block comment.");
        return;
    }

    advance();
}

void lexer::number()
{
    bool isDecimal = false;
    while (isdigit(peek()))
    {
        advance();
    }

    if (peek() == '.' && isdigit(peekNext()))
    {
        isDecimal = true;
        advance();

        while (isdigit(peek()))
        {
            advance();
        }
    }

    addToken(isDecimal ? NUMBER_DEC : NUMBER_INT, src.substr(start, current));
}

bool isalphanumeric(char c)
{
    return isalpha(c) || isdigit(c);
}

void lexer::identifier()
{
    while (isalphanumeric(peek()))
    {
        advance();
    }

    string txt = src.substr(start, current);
    if (keywords.find(txt) == keywords.end())
    {
        addToken(IDENTIFIER);
    }
    else
    {
        tokenType type = keywords.at(txt);
        addToken(type);
    }
}
