//picture.cc
#include "picture.h"

Picture::Picture(std::vector<std::vector<Pixel>> pixelvect) {
    char currentpixel;
    pixelvector = pixelvect;
    for (unsigned int i = pixelvector.size() -1 ; i; i--) {
        for (unsigned int j = 0; j < pixelvector[i].size(); j++) {
            currentpixel = convertpixel(i, j);
            std::cout << currentpixel;
        }
        std::cout << std::endl;
    }
}

char Picture::convertpixel(int x, int y) {
    Pixel currentpixel = pixelvector[x][y]; //get pixel
    //calculate luminance
    float red = currentpixel.red * REDM;
    float green = currentpixel.green * GREENM;
    float blue = currentpixel.blue * BLUEM;
    float sum = red + green + blue;

    int intensityonscale = sum / (255.f / DIVIDER);
    if (intensityonscale < 0) {
        intensityonscale = 0;
    } else if (intensityonscale >= (signed int)GRAYSCALE.size()) {
        intensityonscale = GRAYSCALE.size() - 1;
    }

    return GRAYSCALE[intensityonscale];
}