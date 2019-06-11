//general.h
#ifndef GENERAL_H
#define GENERAL_H
#include <string>

const int PIXELSIZE = 24;  //bits per pixel
const int PIXELSTRSIZE = PIXELSIZE / 4; //chars per pixel
const int COLOURSIZE = PIXELSIZE / 3; //bits per colour
const int COLOURSTRSIZE = COLOURSIZE / 4; //chars per colour
const float REDM = 0.2126, GREENM = 0.7152, BLUEM = .0722; //for multiplying to calculate luminance

const std::string GRAYSCALE = "$@B%%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
const unsigned int DIVIDER = GRAYSCALE.size();

std::string hexendianconverter(const std::string input);
int hextoint(const std::string input);

#endif