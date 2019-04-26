#include <iostream>
#include <string>
#include <vector>
#include "hexdump.h"


int main(int argc, char **argv) {
    std::vector<std::string> hexdumps;
    Hexdump *currentdump;
    if (argc < 2) {
        std::cout << "No files specified" << std::endl;
        return 1;
    }
    
    for (int i = 1; i < argc; i++) {
        currentdump = new Hexdump(argv[i]);
        hexdumps.push_back(currentdump->getDump());
        delete currentdump;
    }

    for (unsigned int i = 0; i < hexdumps.size(); i++) {
        std::cout << hexdumps[i] << std::endl;
    }

    return 0;
}