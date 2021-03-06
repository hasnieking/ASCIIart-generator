#include <iostream>
#include <string>
#include <vector>
#include "hexdump.h"
#include "picture.h"
#include "bmp.h"


int main(int argc, char **argv) {
    std::vector<std::string> hexdumps;
    Hexdump *currentdump;
    //Quit when there are no files
    if (argc < 2) {
        std::cout << "No files specified" << std::endl;
        return 1;
    }
    
    //make dump for all argv's
    for (int i = 1; i < argc; i++) {
        try {
            currentdump = new Hexdump(argv[i]);
        } catch (const char* msg) {
            currentdump = NULL;
        }
        if (currentdump != NULL) {
            hexdumps.push_back(currentdump->getDump());
            delete currentdump;
        }
    }

    //print all images
    Picture* currentpict;
    BMP* bmp;
    for (unsigned int i = 0; i < hexdumps.size(); i++) {
        bmp = new BMP(hexdumps[i]);
        std::vector<std::vector<Pixel>> imagevect = bmp->getImage();
        delete bmp;
        currentpict = new Picture(imagevect);
        delete currentpict;

        std::cout << std::string(WHITESPACE, '\n');
    }

    return 0;
}