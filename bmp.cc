//bmp.cc
#include "bmp.h"
#include "general.h"

//constructor
BMP::BMP(std::string hexdump) {
    storeHeader(hexdump);
    storeImage(hexdump);
    if (compression != 0) {
        throw "Can't handle compressed bmp images.";
    }
}

//deconstructor
BMP::~BMP() {
    if (image != NULL) delete image;
}

//store the header information
void BMP::storeHeader(const std::string hexdump) {
    type = hextoint(hexendianconverter(hexdump.substr(0,4)));
    size = hextoint(hexendianconverter(hexdump.substr(4,8)));
    reserved1 = hextoint(hexendianconverter(hexdump.substr(12,4)));
    reserved2 = hextoint(hexendianconverter(hexdump.substr(16,4)));
    offset = hextoint(hexendianconverter(hexdump.substr(20,8)));
    dib_header_size = hextoint(hexendianconverter(hexdump.substr(28,8)));
    width_px = hextoint(hexendianconverter(hexdump.substr(36,8)));
    height_px = hextoint(hexendianconverter(hexdump.substr(44,8)));
    num_planes = hextoint(hexendianconverter(hexdump.substr(52,4)));
    bits_per_pixel = hextoint(hexendianconverter(hexdump.substr(56,4)));
    compression = hextoint(hexendianconverter(hexdump.substr(60,8)));
    image_size_bytes = hextoint(hexendianconverter(hexdump.substr(68,8)));
    x_resolution_ppm = hextoint(hexendianconverter(hexdump.substr(76,8)));
    y_resolution_ppm = hextoint(hexendianconverter(hexdump.substr(84,8)));
    num_colors = hextoint(hexendianconverter(hexdump.substr(92,8)));
    important_colors = hextoint(hexendianconverter(hexdump.substr(100,8)));
}

//store all individual pixels
void BMP::storeImage(const std::string hexdump) {
    image = new Image(hexdump.substr(bits_per_pixel / 3 / 4 * offset), (int)width_px, (int)height_px);
}

//get a single pixel
Pixel BMP::getPixel(int x, int y) {
    return image->getpixel(x, y);
}

//get the vector of pixels
std::vector<std::vector<Pixel>> BMP::getImage() {
    return image->getImage();
}