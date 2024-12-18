#include "WebsiteGenerator.h"

WebsiteGenerator::WebsiteGenerator(const char* file)
{
    sourceCode = nullptr;
    webpage    = nullptr;

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
    fclose(sourceFile);

    if(!this->interpretData()) return;
}

WebsiteGenerator::~WebsiteGenerator()
{
    if (sourceCode != nullptr) delete [] sourceCode;
    if (webpage    != nullptr) delete [] webpage;
}

bool WebsiteGenerator::interpreted() const
{
    return interpret_success;
}

bool isSpecialCharacter(char c)
{
    return (
            c == '[' || c == ']' || c == '{' || c == '}' || c == '(' ||
            c == ')' || c == ','
    );
}

bool isWhitespaceCharacter(char c)
{
    return (
       c == ' ' || c == '\t' || c == '\n' || c == '\r'
    );
}

bool WebsiteGenerator::interpretData()
{
    const char* current = sourceCode;
    if (!current) return false;

    char word[512] = {0};
    size_t wordCount = 0;

    while (*current != '\0')
    {
        if (wordCount >= (sizeof(word) - 1))
        {
            printf("Error when processing word\nPossible buffer overflow attempt\nHalting program.\n");
            memset(word, 0, sizeof(word));
            this->interpret_success = false;
            break;
        }

        if (isSpecialCharacter(*current))
        {
            if (wordCount > 0)
            {
                word[wordCount] = '\0';
                printf("%s\n", word);
                memset(word, 0, sizeof(word));
                wordCount = 0;
            }
            printf("%c\n", *current);
        }
        else if (isWhitespaceCharacter(*current))
        {
            if (wordCount > 0)
            {
                word[wordCount] = '\0';
                printf("%s\n", word);
                memset(word, 0, sizeof(word));
                wordCount = 0;
            }
        }
        else
        {
            word[wordCount] = *current;
            ++wordCount;
        }

        ++current;
    }

    if (wordCount > 0 && this->interpret_success)
    {
        word[wordCount] = '\0';
        printf("%s\n", word);
        memset(word, 0, sizeof(word));
    }

    return this->interpret_success;
}



