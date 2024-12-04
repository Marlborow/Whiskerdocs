#ifndef WEBSITEGENERATOR_H
#define WEBSITEGENERATOR_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "WebsiteGenerator/Metadata.h"

class WebsiteGenerator
{
    private:
        bool interpret_success;
        char* sourceCode;
        char* webpage;
        Metadata* metadata;
    public:
        WebsiteGenerator(const char* file);
        ~WebsiteGenerator();
        bool interpreted() const;
};

#endif
