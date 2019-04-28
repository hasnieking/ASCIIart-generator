//general.cc
#include <string>
#include <sstream>

//convert endians to each other
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

//convert hex string to int
int hextoint(const std::string input) {
    if(input.find_first_not_of("0123456789abcdefABCDEF", 2) != std::string::npos) {
        throw "Not a hexadecimal input";
    }
    int value;
    std::stringstream(input) >> std::hex >> value;
    return value;
}