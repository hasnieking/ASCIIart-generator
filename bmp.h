//bmp.h
#include <cstdint>
#include <string>
#include "image.h"

class BMP {
    public:
        BMP(std::string hexdump);
        //std::vector<pixel> getImage();
        
    private:
        //https://engineering.purdue.edu/ece264/17au/hw/HW15
        //bmp header
        uint16_t  type;             // Magic identifier: 0x4d42
        uint32_t  size;             // File size in bytes
        uint16_t  reserved1;        // Not used
        uint16_t  reserved2;        // Not used
        uint32_t  offset;           // Offset to image data in bytes from beginning of file (54 bytes)
        uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
        int32_t   width_px;         // Width of the image
        int32_t   height_px;        // Height of image
        uint16_t  num_planes;       // Number of color planes
        uint16_t  bits_per_pixel;   // Bits per pixel
        uint32_t  compression;      // Compression type
        uint32_t  image_size_bytes; // Image size in bytes
        int32_t   x_resolution_ppm; // Pixels per meter
        int32_t   y_resolution_ppm; // Pixels per meter
        uint32_t  num_colors;       // Number of colors  
        uint32_t  important_colors; // Important colors 

        void storeHeader(const std::string hexdump); //stores header
        void storeImage(const std::string hexdump); //stores image as pixels
        Image *image; //image
};