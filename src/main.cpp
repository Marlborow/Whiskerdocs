#include "Whiskerdocs.h"

int main(int argc, char* argv[])
{
    if(argc < 2) {
        return 1;
    }

    char* filename = argv[1];
    Whiskerdocs whisker(filename);
    return 0;
}
