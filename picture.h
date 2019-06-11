//picture.h
#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include <iostream>
#include "general.h"
#include "image.h"

class Picture {
    public:
        Picture(std::vector<std::vector<Pixel>> pixelvect); //constructor (and prints it)
    private:
        std::vector<std::vector<Pixel>> pixelvector;
        char convertpixel(int x, int y);
};




#endif