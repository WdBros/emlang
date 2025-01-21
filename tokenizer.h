#pragma once

#include <map>
#include <set>
#include <vector>
#include <string>

enum TokenCategory {
    LITERAL,
    INFIX_OPERATOR,
    DELIMITER
};

enum TokenType {
    // PRIMITIVES
    NUMBER,
    DECIMAL,
    STRING,
    // OPERATORS
    ADD,
    SUB,
    MUL,
    DIV,
    // DELIMITERS
    LPARE,
    RPARE,
};

const std::map<TokenType, TokenCategory> TokenCategoryMap = {
    { NUMBER, LITERAL },
    { DECIMAL, LITERAL },
    { STRING, LITERAL },
    { ADD, INFIX_OPERATOR },
    { SUB, INFIX_OPERATOR },
    { MUL, INFIX_OPERATOR },
    { DIV, INFIX_OPERATOR },
    { LPARE, DELIMITER },
    { RPARE, DELIMITER },
};

const std::map<std::string, TokenType> TokenTypeMap = {
    { "+", ADD },  
    { "-", SUB },
    { "*", MUL },
    { "/", DIV },
    { "(", LPARE }, 
    { ")", RPARE },
};

typedef struct {
    public:
        TokenType type;
        TokenCategory category;
        int prec;
        bool is_value;
        bool right_assoc;
        bool is_infix;
} TokenProperties;

const std::map<TokenType, TokenProperties> TokenMap = {
    // PRIMITIVES
    { NUMBER, { NUMBER, TokenCategoryMap.at(NUMBER), 0, true, false, false } },
    { DECIMAL, { DECIMAL, TokenCategoryMap.at(DECIMAL), 0, true, false, false } },
    { STRING, { STRING, TokenCategoryMap.at(STRING), 0, true, false, false } },
    // OPERATORS
    { ADD, { ADD, TokenCategoryMap.at(ADD), 1, false, false, true } },
    { SUB, { SUB, TokenCategoryMap.at(SUB), 1, false, false, true } },
    { MUL, { MUL, TokenCategoryMap.at(MUL), 2, false, false, true } },
    { DIV, { DIV, TokenCategoryMap.at(DIV), 2, false, false, true } },
    // DELIMITERS
    { LPARE, { LPARE, TokenCategoryMap.at(LPARE), 0, false, false, false } },
    { RPARE, { RPARE, TokenCategoryMap.at(RPARE), 0, false, false, false } },
};

class Token {
    public:
    const std::string value;
    const TokenProperties& p;
    Token(TokenType type) : p(TokenMap.at(type)), value(NULL) { };
    Token(TokenType type, std::string value) : p(TokenMap.at(type)), value(value) { };
};

bool basic_validation(const std::string& s);

bool is_digit(const char& c);

int str_to_int(const std::string& s);

std::string no_whitespace_cp(const std::string& s);

std::vector<Token> tokenize(const std::string& input);