#include "interpreter.hpp"
#include <stdexcept>

double Interpreter::visit(AST* node) {
    if (auto* n = dynamic_cast<Num*>(node)) return visitNum(n);
    if (auto* t = dynamic_cast<Text*>(node)) return visitText(t);
    if (auto* v = dynamic_cast<Var*>(node)) return visitVar(v);
    if (auto* b = dynamic_cast<BinOp*>(node)) return visitBinOp(b);
    if (auto* a = dynamic_cast<Assign*>(node)) return visitAssign(a);
    throw std::runtime_error("Unknown AST node");
}

double Interpreter::visitNum(Num* node) {
    return node->value;
}

double Interpreter::visitText(Text* node) {
    return std::stod(node->value);
}

double Interpreter::visitVar(Var* node) {
    if (variables.find(node->name) != variables.end()) {
        return variables[node->name];
    } else {
        throw std::runtime_error("Undefined variable: " + node->name);
    }
}

double Interpreter::visitBinOp(BinOp* node) {
    if (node->op == "+") return visit(node->left) + visit(node->right);
    if (node->op == "-") return visit(node->left) - visit(node->right);
    if (node->op == "*") return visit(node->left) * visit(node->right);
    if (node->op == "/") return visit(node->left) / visit(node->right);
    throw std::runtime_error("Unknown operator: " + node->op);
}

double Interpreter::visitAssign(Assign* node) {
    std::string var_name = node->left->name;
    double value = visit(node->right);
    variables[var_name] = value;
    return value;
}