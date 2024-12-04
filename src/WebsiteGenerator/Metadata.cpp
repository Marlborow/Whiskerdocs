#include "Metadata.h"

Metadata::Metadata()
{
    author = nullptr;
    title = nullptr;
    stylesheet = nullptr;
}

Metadata::~Metadata()
{
    if(author     != nullptr) delete[] author;
    if(title      != nullptr) delete[] title;
    if(stylesheet != nullptr )delete[] stylesheet;
}

void Metadata::setAuthor(const char* author)
{
}

void Metadata::setTitle(const char* title)
{
}

void Metadata::setStylesheet(const char* stylesheet)
{
}
