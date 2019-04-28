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
        Image(std::string hexdump, int width, int height);
        Pixel getpixel(int x, int y);
    private:
        void store(std::string hexdump, int width, int height);
        Pixel convert(std::string values);
        std::vector<std::vector<Pixel>> image;

};

#endif