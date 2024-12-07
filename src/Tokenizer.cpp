#include "Tokenizer.h"
Token::Token(enum TokenType type, const char* data)
{
    this->type = type;
    this->data = data;
}

Token::~Token()
{
    if(this->data != nullptr) delete [] this->data;
}

const char* Token::getData() const
{
    return this->data;
}

const unsigned int Token::getType() const {
    return this->type;
}
