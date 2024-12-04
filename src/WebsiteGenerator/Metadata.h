#ifndef METADATA_H
#define METADATA_H

#include <cstring>

class Metadata {
    public:
        Metadata();
        ~Metadata();
        void setAuthor(const char* author);
        void setTitle(const char* title);
        void setStylesheet(const char* stylehseet);

    private:
        char* author;
        char* title;
        char* stylesheet;
};

#endif
