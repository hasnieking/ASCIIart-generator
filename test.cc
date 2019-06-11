//test.cc
#include <iostream>
#include "general.h"
#include "bmp.h"
#include "hexdump.h"
#include "picture.h"

using namespace std;

int main() {
    //hex tests
    if (hexendianconverter("A6B97D").compare("7DB9A6") != 0) return 1;
    if (hexendianconverter("C3").compare("C3") != 0) return 1;
    if (hextoint("A7") != 167) return 1;
    if (hextoint("C380F") != 800783) return 1;

    //4x6 bmp test
    string dump1 = "424d7e0000000000000036000000280000000400000006000000010018000000000048000000c40e0000c40e00000000000000000000ffff00ffff00c0c0c0c0c0c0ffff00ffff00c0c0c0c0c0c08080ff8080ffffffffffffff8080ff8080ffffffffffffff0080ff0080ff8080808080800080ff0080ff808080808080";
    BMP *bmp = new BMP(dump1);
    Pixel pixel = bmp->getPixel(0, 5);
    if (pixel.red != 255 || pixel.green != 128 || pixel.blue != 0) return 1;
    delete bmp;

    //6x6 bmp test
    Hexdump *currentdump = new Hexdump("6x6bitmap.bmp");
    string dump2 = currentdump->getDump();
    bmp = new BMP(dump2);
    pixel = bmp->getPixel(5, 5);
    if (pixel.red != 0 || pixel.green != 0 || pixel.blue != 255) return 1;
    vector<vector<Pixel>> imagevect = bmp->getImage();
    if (imagevect[5][5].red != 0 || imagevect[5][5].green != 0 || imagevect[5][5].blue != 255) return 1;
    delete bmp;

    Picture* print = new Picture(imagevect);
    delete print;

    cout << "Code works correctly" << endl;
    return 0;
}