#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

enum TokenType {
    NUMBER, TEXT, IDENT, OP, ASSIGN, END, NEWLINE, MISMATCH
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& code);

#endif