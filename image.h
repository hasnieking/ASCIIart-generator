//image.h
#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <vector>
#include <string>

//contains intensity of colours
struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

//the individual pixels image
class Image {
    public:
        Image(std::string hexdump, int width, int height); //constructor
        Pixel getpixel(int x, int y); //get a single pixel
        std::vector<std::vector<Pixel>> getImage(); //get vector of all pixels
    private:
        void store(std::string hexdump, int width, int height); //store all pixels
        Pixel convert(std::string values); //convert hex string to intensity individual colours (0-255)
        std::vector<std::vector<Pixel>> image; //vector of all pixels

};

#endif