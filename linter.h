#pragma once

#include "tokenizer.h"

#include <vector>
#include <map>
#include <functional>

namespace linter {

bool number_linter(std::vector<Token>::const_iterator); 
bool infix_linter(std::vector<Token>::const_iterator); 
bool lpare_linter(std::vector<Token>::const_iterator);
bool rpare_linter(std::vector<Token>::const_iterator);


const std::map<TokenType, std::function<bool(std::vector<Token>::const_iterator)>> linter_map = {
    { NUMBER, number_linter },
    { DECIMAL, number_linter },
    { ADD, infix_linter },
    { SUB, infix_linter },
    { MUL, infix_linter },
    { DIV, infix_linter },
    { LPARE, lpare_linter },
    { RPARE, rpare_linter },
};

void lint(const std::vector<Token>& tokens);

}
