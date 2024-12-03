#ifndef WHISKERDOCS_H
#define WHISKERDOCS_H

class Whiskerdocs {
    private:
        bool init_success;
        char* filename;
        char* file_extension;
    public:
        char* getFileExtension(const char* file);
        Whiskerdocs(const char* file);
        ~Whiskerdocs();
};

#endif
