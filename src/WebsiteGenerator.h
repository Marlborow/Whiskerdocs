#ifndef WEBSITEGENERATOR_H
#define WEBSITEGENERATOR_H

#include <cstdio>
#include <cstdlib>
#include <cstring>


class WebsiteGenerator
{
    private:
        bool interpret_success;
        char* sourceCode;
        char* webpage;
        bool interpretData();
    public:
        WebsiteGenerator(const char* file);
        ~WebsiteGenerator();
        bool interpreted() const;
};

#endif
