#include "tokenizer.h"

#include "parser.h"

using std::stack;
using std::vector;

bool is_value(const Token& token) {
    return token.p.type == NUMBER || token.p.type == DECIMAL;
}

stack<Token> parse(const vector<Token>& tokens) {
    stack<Token> op;
    stack<Token> fin;

    for (vector<Token>::const_iterator i = tokens.begin(); i != tokens.end(); i++) {
        Token e (*i);
        if (is_value(*i)) {
            fin.push(e);
            continue;
        }
        if (i->p.type == LPARE) {
            op.push(e);
            continue;
        }
        if (i->p.type == RPARE) {
            while (op.top().p.type != LPARE) {
                fin.push(op.top());
                op.pop();
            }
            op.pop();
            continue;
        }
        if (true) { // if (is_operator(*i)) { // should be, actually
            if ((op.empty()) || (e.p.prec > op.top().p.prec) || (e.p.right_assoc && e.p.prec >= op.top().p.prec) || op.top().p.type == LPARE) {
                op.push(e);
                continue;
            } 
            while ((!op.empty()) && ((e.p.prec < op.top().p.prec) || (!e.p.right_assoc && e.p.prec <= op.top().p.prec))) {
                fin.push(op.top());
                op.pop();
            }
            op.push(e);
        }
    }
    while (!op.empty()) {
        fin.push(op.top());
        op.pop();
    }
    return fin;
}