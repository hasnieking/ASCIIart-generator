//general.cc
#include <string>
#include <iostream>

std::string hexendianconverter(const std::string input) {
    if (input.size() % 2 != 0 || input.size() < 2) {
        throw "Incorrect hexadecimal input";
    }
    std::string temp;
    for (int i = 0; i < (signed int)input.size(); i += 2) {
        temp.insert(0, input.substr(i, 2));
    }
    return temp;
}