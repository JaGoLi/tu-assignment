#include <string>
#include <climits>
#include <stdint.h>
#include <bitset>


class SerialMessage {
    SerialMessage(std::string& code, std::string& message) {
        if (code.size() == 2) {
            data = (bitset<8>(code.c_str()[0]) << 8);
            data += (bitset<8>(code.c_str()[1]));
            data << 16;
        }
        if (message.size() == 2) {
            data += (bitset<8>(message.c_str[0]) << 8);
            data += (bitset<8>(message.c_str[1]));
        }
    }
    SerialMessage(uint16 code, uint16 message) {
        data = code;
        data << 16;
        data += message;
    }
    SerialMessage(const SerialMessage& other) {
        data = other.data;
    }

    ~SerialMessage();

private:
    uint32_t data = 0;
}