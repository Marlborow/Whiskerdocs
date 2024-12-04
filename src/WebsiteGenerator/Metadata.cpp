#include "Metadata.h"

Metadata::Metadata()
{
    this->author = nullptr;
    this->title = nullptr;
    this->stylesheet = nullptr;
}

Metadata::~Metadata()
{
    delete[] author;
    delete[] title;
    delete[] stylesheet;
}

/*Helper function for setting relevent data*/
void Metadata::setData(char*& dest, const char* data)
{
    delete [] dest;
    dest = new char[strlen(data)+1];
    strcpy(dest, data);
}


void Metadata::setAuthor(const char* author)
{
    setData(this->author, author);
}

void Metadata::setTitle(const char* title)
{
    setData(this->title, title);
}

void Metadata::setStylesheet(const char* stylesheet)
{
    setData(this->stylesheet, stylesheet);
}
