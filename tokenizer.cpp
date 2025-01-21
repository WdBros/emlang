#include "tokenizer.h"

using std::map;
using std::string;
using std::vector;

bool basic_validation(const string& s) {
    int para_level = 0;
    bool unclosed_quote = false;
    for (string::const_iterator i = s.begin(); i != s.end(); i++) {
        switch (*i)
        {
        case '"':
            unclosed_quote = !unclosed_quote;
            break;
        case '(':
            para_level++;
            break;
        case ')':
            para_level--;
            break;
        default:
            break;
        }
    }
    return para_level == 0 && !unclosed_quote;
}

bool is_digit(const char& c) {
    return c >= '0' &&
           c <= '9';
}

int str_to_int(const string& s) {
    int a = 0, d = 1;
    for (string::const_iterator i = s.end() - 1; i != s.begin(); i--)
    {
        a += (*i - 48) * d;
        d *= 10;
    }
    a += (*s.begin() - 48) * d;
    return a;
}

string no_whitespace_cp(const string& s) {
    string output = "";
    for (string::const_iterator i = s.begin(); i != s.end(); i++) {
        if (*i != ' ' && *i != '\n' && *i != '\t') { output += *i; }
    }
    return output;
}

vector<Token> tokenize(const string& input) {
    string _input = no_whitespace_cp(input); // remove whitespace
    vector<Token> output;
    
    for (string::size_type s = 0, i = 0; i < _input.size(); i++, s++) // for each char in input
    {
        char c = _input.at(i); // above cont.

        // tokens of multiple chars
        if (c == '"') {
            i++; // TODO: writing the tokenizer for strings :)
            while (i < _input.size()) {
                c = _input.at(i);
                if (c == '"') {
                    break;
                }
                i++;
            }
        }
        if (is_digit(c)) {
            bool dec = false;
            while (i < _input.size()) {
                c = _input.at(i);
                if (!is_digit(c)) {
                    if (c == '.') {
                        dec = true;
                    }
                    else {
                        break;
                    }
                }
                i++;
            }
            if (dec) {
                output.push_back(Token(DECIMAL, _input.substr(s, i - s)));
            }
            else {
                output.push_back(Token(NUMBER, _input.substr(s, i - s)));
            }
            s = --i;
            continue;
        }

        // tokens of single char
        string conversion {c};
        output.push_back(Token(TokenTypeMap.at(conversion), conversion));
    }
    return output;
}