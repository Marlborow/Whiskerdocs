#ifndef TOKENIZER_H
#define TOKENIZER_H


enum TokenType{
    //?,@function, ...
    TOKEN_NULL,
    TOKEN_FUNCTION,
    TOKEN_TYPE,
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
        const char* getData() const;
        const unsigned int getType() const;

    Token(enum TokenType type, const char* data);
    ~Token();
    private:
        enum TokenType type;
        const char* data;
};

#endif
