#ifndef TOKENIZER_H
#define TOKENIZER_H


enum TokenType{
    //?,@function, ...
    TOKEN_NULL,
    TOKEN_FUNCTION,
    TOKEN_DATA,

    //(, )
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    // {, }
    TOKEN_LCURLY,
    TOKEN_RCURLY,
    // [, ]
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
};


class Token {
    public:
        char* getData();
        unsigned int getType();
    private:
        enum TokenType type;
        char* data;
};

#endif
