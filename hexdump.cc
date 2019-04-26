//hexdump.cc
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "hexdump.h"

Hexdump::Hexdump(std::string filename) {
    try {
        handle(filename);
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
}

//generate dump
//Used code: https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.cpp
void Hexdump::handle(std::string filename) {
    unsigned char buffer[16];
    int counter1, counter2;
    std::ifstream input;
    std::stringstream stream;

    //Open the file.
    input.open(filename.c_str());

    if (!input) {
        std::cout << "Unable to open file: " << filename << std::endl;
        throw "Unable to open file";
    }

    //Dump the file contents.
    while (!input.eof()) {
        input.read((char*)buffer, 16);

        counter1 = input.gcount();

        if (counter1 <= 0) {
            break;
        }

        //Print 16 data items, in pairs, in hexadecimal.
        counter2 = 0;
        for (int i = 0; i < 16; i++ ) {   
            counter2++;
            if (counter2 <= counter1) {
                stream << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)buffer[i] << ' ';
            }
        }
    }

    //store the result
    dump = stream.str();
    dump.pop_back();
    //Close the file.
    input.close();
}

std::string Hexdump::getDump() {
    return dump;
}