#include "lexer.hpp"
#include "parser.hpp"
#include "interpreter.hpp"
#include <fstream>
#include <sstream>

int main() {
    std::ifstream file("examples/example.oi");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();
    
    std::vector<Token> tokens = tokenize(code);
    Parser parser(tokens);
    AST* tree = parser.parse();
    Interpreter interpreter;
    interpreter.visit(tree);
    
    for (const auto& var : interpreter.variables) {
        std::cout << var.first << " = " << var.second << std::endl;
    }
    
    return 0;
}