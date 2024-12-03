#include <iostream>
#include <cstring>

class Whiskerdocs {
    private:
        bool  init_success;
        char* filename;
        char* file_extension;
    public:
        char* getFileExtension(const char* file);
        Whiskerdocs(const char* file);
        ~Whiskerdocs();
};

Whiskerdocs::Whiskerdocs(const char* file)
{
    this->file_extension = getFileExtension(file);
    if(this->file_extension == nullptr || strcmp(this->file_extension, "wd") != 0)
    {
        std::cout << "Failed to initialize Whiskerdoc, Filetype incorrect\n";
        this->init_success = false;
        this->filename = nullptr;
        return;
    }

    this->init_success = true;
    this->filename = new char[strlen(file) +1];
    strcpy(filename, file);
    std::cout << this->file_extension << std::endl;
}

Whiskerdocs::~Whiskerdocs()
{
    //Delete file extension poitners
    if(file_extension)
    {
        delete file_extension;
        file_extension = nullptr;
    }
}

char* Whiskerdocs::getFileExtension(const char* file)
{
    if(file == nullptr) return nullptr;

    const char* dot = strrchr(file, '.');

    if(dot == nullptr || *(dot+1) == '\0') return nullptr;
    dot++;
    char* extension = new char[strlen(dot)+1];
    strcpy(extension, dot);
    return extension;
}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        return 1;
    }

    char* filename = argv[1];
    Whiskerdocs whisker(filename);
    return 0;
}
