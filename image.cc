//image.cc
#include <string>
#include "image.h"
#include "general.h"

#include <iostream>

//constructor
Image::Image(std::string hexdump, int width, int height) {
    store(hexdump, width, height);
}

//store the pixels in a vector
void Image::store(std::string hexdump, int width, int height) {
    std::string current;
    int counter = 0;
    std::vector<Pixel> row;
    Pixel currentpixel;
    int padding = ((4 - (3 * width) % 4) % 4) * COLOURSTRSIZE;
    for (unsigned int i = 0; i < hexdump.size(); i += PIXELSTRSIZE) {
        currentpixel = convert(hexdump.substr(i, PIXELSTRSIZE));
        row.push_back(currentpixel);
        counter++;
        if (counter >= width) {
            image.push_back(row);
            row.clear();
            counter = 0;
            i += padding;
        }
    }
}

//convert hexadecimal string to pixel
Pixel Image::convert(std::string values) {
    Pixel pixel;
    pixel.blue = hextoint(values.substr(0,2));
    pixel.green = hextoint(values.substr(2,2));
    pixel.red = hextoint(values.substr(4,2));
    return pixel;
}

//get a single pixel
Pixel Image::getpixel(int x, int y) {
    return image[y][x];
}

//get the vector of all pixels
std::vector<std::vector<Pixel>> Image::getImage() {
    return image;
}