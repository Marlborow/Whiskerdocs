#include "WebsiteGenerator.h"

WebsiteGenerator::WebsiteGenerator(const char* file)
{
    sourceCode = nullptr;
    webpage    = nullptr;
    metadata   = nullptr;

    if (file == nullptr)
    {
        this->interpret_success = false;
        printf("How'd we get here?\n");
        return;
    }

    FILE* sourceFile = fopen(file,"r");
    if(!sourceFile){
    this->interpret_success = false;
        printf("Unable to interprete: %s\n", file);
        return;
    }
    char buffer[2048];
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, sourceFile);
    buffer[bytesRead] = '\0';

    sourceCode = new char[bytesRead + 1];
    strcpy(sourceCode, buffer);
    printf("%s", sourceCode);
    fclose(sourceFile);
}

WebsiteGenerator::~WebsiteGenerator()
{
    if(sourceCode != nullptr) delete [] sourceCode;
    if(webpage    != nullptr) delete webpage;
    if(metadata   != nullptr) delete [] metadata;
}

bool WebsiteGenerator::interpreted() const
{
    return interpret_success;
}
