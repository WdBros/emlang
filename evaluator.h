#pragma once

#include <vector>
#include <map>
#include <stack>
#include <functional>
#include <string>

#include <iostream>

#include "tokenizer.h"

Token literal(std::stack<Token>& stack);
Token infix_operator(std::stack<Token>& stack);

Token add(Token val1, Token val2);
Token sub(Token val1, Token val2);
Token mul(Token val1, Token val2);
Token _div(Token val1, Token val2);
Token pow(Token val1, Token val2);

const std::map<TokenCategory, std::function<Token(std::stack<Token>& stack)>> evaluation_map = {
    { LITERAL, literal },
    { INFIX_OPERATOR, infix_operator },
};
