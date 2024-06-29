#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <map>
#include <string>
#include "parser.hpp"

class Interpreter {
public:
    std::map<std::string, double> variables;
    
    double visit(AST* node);
    double visitNum(Num* node);
    double visitText(Text* node);
    double visitVar(Var* node);
    double visitBinOp(BinOp* node);
    double visitAssign(Assign* node);
};

#endif