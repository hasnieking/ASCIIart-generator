//image.h
#include <cstdint>
#include <vector>
#include <string>

struct pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class Image {
    public:
        Image(std::string hexdump, int width, int height);
    private:
        void store(std::string hexdump);
        std::vector<std::vector<pixel>> image;

};