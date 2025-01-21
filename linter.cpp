#include "linter.h"

using std::vector;

namespace linter {

bool number_linter(vector<Token>::const_iterator i) {
    bool out = (++i)->p.type != NUMBER;
    i--;
    return out;
}

bool infix_linter(vector<Token>::const_iterator i) {
    bool out = (++i)->p.type == NUMBER || i->p.type == RPARE;
    i--;
    return out;
}

bool lpare_linter(vector<Token>::const_iterator i) {
    bool out = (++i)->p.type == NUMBER || i->p.type == LPARE;
    i--;
    return out; 
}

bool rpare_linter(vector<Token>::const_iterator i) {
    bool out = (++i)->p.is_infix || i->p.type == RPARE;
    i--;
    return out;
}

void lint(const vector<Token>& tokens) {
    for (vector<Token>::const_iterator i = tokens.begin(); i < tokens.end() - 1; i++) {
        if (!linter_map.at(i->p.type)(i)) {
            throw ("lol");
        }
    }
    if ((--tokens.end())->p.type != NUMBER) {
        throw ("lol");
    }
}

}