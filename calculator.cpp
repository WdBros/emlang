// the calculator
// ---
// first step, tokenize
//  get a vector of tokens so that we can efficiently manipulate them :)
// second step, parse
//  make a tree of values and operators
// third step, evaluate
//  ideally each operator node of the tree should have an operation to simplify itself into a primitive value :)

#include <string>
#include <vector>
#include <stack>
#include <iostream>

#include "tokenizer.h"
#include "linter.h"
#include "parser.h"
#include "evaluator.h"

using std::string;
using std::vector;
using std::stack;
using std::cin; using std::cout;

int main() {
    string opa;
    cout << "> ";
    getline(cin, opa);

    // cout << basic_validation(opa) << '\n';

    vector<Token> tokenized;
    try {
        tokenized = tokenize(opa);
    }
    catch (...) {
        cout << "Unrecognized symbol(s)! Aborting!\n";
        return 1;
    }

    vector<Token> to_lint(tokenized);
    try {
        linter::lint(to_lint);
    }
    catch (...) {
        cout << "Invalid!\n";
        return 0;
    }
    cout << "Valid!\n";

    stack<Token> rpn = parse(tokenized);

    // DEBUG: prints the stack in rpn
    // while (!rpn.empty()) {
    //    cout << rpn.top().value << '\n';
    //    rpn.pop();
    // }

    cout << "---\nEQUALS:\n";

    evaluation_map.at(rpn.top().p.category)(rpn);
    cout << rpn.top().value << '\n';
}