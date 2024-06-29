#include "parser.hpp"
#include <stdexcept>

BinOp::BinOp(AST* left, const std::string& op, AST* right)
    : left(left), op(op), right(right) {}

Num::Num(double value) : value(value) {}

Text::Text(const std::string& value) : value(value) {}

Var::Var(const std::string& name) : name(name) {}

Assign::Assign(Var* left, AST* right) : left(left), right(right) {}

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

Token Parser::consume(TokenType expected_type) {
    Token token = tokens[pos];
    if (token.type == expected_type) {
        pos++;
        return token;
    } else {
        throw std::runtime_error("Unexpected token");
    }
}

AST* Parser::factor() {
    Token token = tokens[pos];
    if (token.type == NUMBER) {
        consume(NUMBER);
        return new Num(std::stod(token.value));
    } else if (token.type == TEXT) {
        consume(TEXT);
        return new Text(token.value);
    } else if (token.type == IDENT) {
        consume(IDENT);
        return new Var(token.value);
    }
    return nullptr;
}

AST* Parser::term() {
    AST* node = factor();
    while (pos < tokens.size() && tokens[pos].type == OP) {
        std::string op = consume(OP).value;
        node = new BinOp(node, op, factor());
    }
    return node;
}

AST* Parser::assignment() {
    Var* var = static_cast<Var*>(factor());
    consume(ASSIGN);
    AST* expr = term();
    return new Assign(var, expr);
}

AST* Parser::parse() {
    return assignment();
}