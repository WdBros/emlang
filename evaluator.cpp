#include "evaluator.h"

using std::vector;
using std::map;
using std::stack;
using std::function;
using std::to_string;

map<TokenType, function<Token(Token, Token)>> infix_operator_fmap = {
    { ADD, add },
    { SUB, sub },
    { MUL, mul },
    { DIV, _div },
};

//  ___    ___   _   _  _ _____   ___ ___ ___ _      __  ____   __  ___ _   ___ ___   _  _   _   ___    _____ ___   ___    __  __   _   _  ___   __  _    ___ _  _ ___ ___ 
// |_ _|  / __| /_\ | \| |_   _| | __| __| __| |    |  \/  \ \ / / | __/_\ / __| __| | || | /_\ |   \  |_   _/ _ \ / _ \  |  \/  | /_\ | \| \ \ / / | |  |_ _| \| | __/ __|
//  | |  | (__ / _ \| .` | | |   | _|| _|| _|| |__  | |\/| |\ V /  | _/ _ \ (__| _|  | __ |/ _ \| |) |   | || (_) | (_) | | |\/| |/ _ \| .` |\ V /  | |__ | || .` | _|\__ \
// |___|  \___/_/ \_\_|\_| |_|   |_| |___|___|____| |_|  |_| |_|   |_/_/ \_\___|___| |_||_/_/ \_\___/    |_| \___/ \___/  |_|  |_/_/ \_\_|\_| |_|   |____|___|_|\_|___|___/
//                                                                                                                                                                         

Token literal(stack<Token>& stack) {
    return stack.top();
}

Token infix_operator(stack<Token>& stack) {
    TokenType type = stack.top().p.type;
    stack.pop();
    Token val1 = evaluation_map.at(stack.top().p.category)(stack);
    // std::cout << val1.value << '\n';
    stack.pop();
    Token val2 = evaluation_map.at(stack.top().p.category)(stack);
    // std::cout << val2.value << '\n';
    stack.pop();
    Token out = infix_operator_fmap.at(type)(val1, val2);
    stack.push(out);
    return out;
}

Token add(Token val1, Token val2) {
    if (val2.p.type == DECIMAL || val1.p.type == DECIMAL) {
        Token res = Token(DECIMAL, to_string(std::stod(val2.value) + std::stod(val1.value)));
        return res;
    }
    else {
        Token res = Token(NUMBER, to_string(std::stoi(val2.value) + std::stoi(val1.value)));
        return res;
    }
}

Token sub(Token val1, Token val2) {
    if (val2.p.type == DECIMAL || val1.p.type == DECIMAL) {
        Token res = Token(DECIMAL, to_string(std::stod(val2.value) - std::stod(val1.value)));
        return res;
    }
    else {
        Token res = Token(NUMBER, to_string(std::stoi(val2.value) - std::stoi(val1.value)));
        return res;
    }
}

Token mul(Token val1, Token val2) {
    if (val2.p.type == DECIMAL || val1.p.type == DECIMAL) {
        Token res = Token(DECIMAL, to_string(std::stod(val2.value) * std::stod(val1.value)));
        return res;
    }
    else {
        Token res = Token(NUMBER, to_string(std::stoi(val2.value) * std::stoi(val1.value)));
        return res;
    }
}

Token _div(Token val1, Token val2) {
    if (val2.p.type == DECIMAL || val1.p.type == DECIMAL) {
        Token res = Token(DECIMAL, to_string(std::stod(val2.value) / std::stod(val1.value)));
        return res;
    }
    else {
        Token res = Token(NUMBER, to_string(std::stoi(val2.value) / std::stoi(val1.value)));
        return res;
    }
}
