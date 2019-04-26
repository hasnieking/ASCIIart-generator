//hexdump.h
#include <string>

class Hexdump {
    public:
        Hexdump(std::string filename);
        ~Hexdump(){}
        std::string getDump();
    private:
        void handle(std::string filename);
        std::string dump;
};