#include "lexer.hpp"
#include <regex>

std::vector<Token> tokenize(const std::string& code) {
    std::vector<Token> tokens;
    std::regex token_specification(R"((\d+(\.\d*)?)|(\".*?\")|(\w+)|([+\-*/])|(=)|(;)|(\n)|([ \t]+)|(.)");
    std::smatch match;
    std::string::const_iterator searchStart(code.cbegin());
    
    while (std::regex_search(searchStart, code.cend(), match, token_specification)) {
        if (match[1].matched) tokens.push_back({NUMBER, match[1].str()});
        else if (match[2].matched) tokens.push_back({TEXT, match[2].str()});
        else if (match[3].matched) tokens.push_back({IDENT, match[3].str()});
        else if (match[4].matched) tokens.push_back({OP, match[4].str()});
        else if (match[5].matched) tokens.push_back({ASSIGN, match[5].str()});
        else if (match[6].matched) tokens.push_back({END, match[6].str()});
        else if (match[7].matched) tokens.push_back({NEWLINE, match[7].str()});
        else if (match[8].matched) continue;
        else tokens.push_back({MISMATCH, match[9].str()});
        
        searchStart = match.suffix().first;
    }
    
    return tokens;
}