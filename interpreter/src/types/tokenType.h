#pragma once

#include <iostream>
#include <string>

enum tokenType
{
    // Single-character tokens.
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACK,
    RIGHT_BRACK,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    // One or two character tokens.
    NEG,
    NEG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    // Literals.
    IDENTIFIER,
    STRING,
    NUMBER_INT,
    NUMBER_DEC,

    // Keywords.
    INTEGER,
    DECIMAL,
    AND,
    OR,
    CLASS,
    ELSE,
    FALSE,
    TRUE,
    FOR,
    WHILE,
    IF,
    NIL,
    RETURN,
    SUPER,
    THIS,

    ENDOF
};

inline std::ostream &operator<<(std::ostream &out, const tokenType &t)
{
    const std::string nameList[] = {
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACK", "RIGHT_BRACK", "LEFT_BRACE", "RIGHT_BRACE", "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR", "NEG", "NEG_EQUAL", "EQUAL", "EQUAL_EQUAL", "GREATER", "GREATER_EQUAL", "LESS", "LESS_EQUAL", "IDENTIFIER", "STRING", "NUMBER_INT", "NUMBER_DEC", "INTEGER", "DECIMAL", "AND", "OR", "CLASS", "ELSE", "FALSE", "TRUE", "FOR", "WHILE", "IF", "NIL", "RETURN", "SUPER", "THIS", "ENDOF"};
    return out << nameList[t];
}
