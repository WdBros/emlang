#pragma once

#include <stack>
#include <vector>

#include "tokenizer.h"

// typedef struct Element {
//     Token token;
//     int prec;

//     Element(Token token) : token(token), prec(token.p.prec) { }
// } Element;

std::stack<Token> parse(const std::vector<Token>& tokens);