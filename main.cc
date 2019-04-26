#include <iostream>
#include <string>
#include <vector>
#include "hexdump.h"


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

    //print all dumps
    for (unsigned int i = 0; i < hexdumps.size(); i++) {
        std::cout << hexdumps[i] << std::endl;
    }

    return 0;
}