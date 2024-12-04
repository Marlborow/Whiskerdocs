#ifndef WHISKERDOCS_H
#define WHISKERDOCS_H

#include <cstring>
#include <cstdio>
#include "WebsiteGenerator.h"

class Whiskerdocs {
    private:
        bool init_success;
        char* filename;
        char* file_extension;

        WebsiteGenerator* websiteGenerator;
    public:
        char* getFileExtension(const char* file);
        Whiskerdocs(const char* file);
        ~Whiskerdocs();
};

#endif
