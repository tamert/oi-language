#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>
#include "lexer.hpp"

class AST {
public:
    virtual ~AST() = default;
};

class BinOp : public AST {
public:
    AST* left;
    std::string op;
    AST* right;
    
    BinOp(AST* left, const std::string& op, AST* right);
};

class Num : public AST {
public:
    double value;
    
    Num(double value);
};

class Text : public AST {
public:
    std::string value;
    
    Text(const std::string& value);
};

class Var : public AST {
public:
    std::string name;
    
    Var(const std::string& name);
};

class Assign : public AST {
public:
    Var* left;
    AST* right;
    
    Assign(Var* left, AST* right);
};

class Parser {
public:
    std::vector<Token> tokens;
    size_t pos;
    
    Parser(const std::vector<Token>& tokens);
    Token consume(TokenType expected_type);
    AST* factor();
    AST* term();
    AST* assignment();
    AST* parse();
};

#endif