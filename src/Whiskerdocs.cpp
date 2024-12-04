#include "Whiskerdocs.h"
#include <cstring>

Whiskerdocs::Whiskerdocs(const char* file)
{
    file_extension = nullptr;
    filename = nullptr;
    websiteGenerator = nullptr;

    this->file_extension = getFileExtension(file);
    if(!this->file_extension || strcmp(this->file_extension, "wd") != 0)
    {
        printf("Failed to initialize Whiskerdocs, Filetype incorrect\n");
        this->init_success = false;
        this->filename = nullptr;
        return;
    }

    this->init_success = true;
    this->filename = new char[strlen(file)+1];
    strcpy(filename, file);
    websiteGenerator = new WebsiteGenerator(filename);
}

Whiskerdocs::~Whiskerdocs()
{
    //Clean up pointers.
    if (file_extension   != nullptr) delete [] file_extension;
    if (filename         != nullptr) delete [] filename;
    if (websiteGenerator != nullptr) delete websiteGenerator;
}

char* Whiskerdocs::getFileExtension(const char* file)
{
    if(file == nullptr) return nullptr;
    const char* dot = strrchr(file, '.');

    if(dot == nullptr || *(dot + 1) == '\0') return nullptr;
    dot++;

   if (file_extension != nullptr) {
        delete[] file_extension;
        file_extension = nullptr;
    }

    char* extension = new char[strlen(dot)+1];
    strcpy(extension, dot);
    return extension;
}

