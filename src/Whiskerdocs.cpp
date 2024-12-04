#include "Whiskerdocs.h"

Whiskerdocs::Whiskerdocs(const char* file)
{
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

    websiteGenerator = new WebsiteGenerator(file);
}

Whiskerdocs::~Whiskerdocs()
{
    //Clean up pointers.
    delete [] file_extension;
    delete [] filename;
    delete [] websiteGenerator;
}

char* Whiskerdocs::getFileExtension(const char* file)
{
    if(file == nullptr) return nullptr;
    const char* dot = strrchr(file, '.');

    if(dot == nullptr || *(dot + 1) == '\0') return nullptr;

    //get characters after the dot
    dot++;

    char* extension = new char[strlen(dot)+1];
    strcpy(extension, dot);
    return extension;
}

