#include "serialmessage.hpp"

class SerialConnection {

    SerialConnection(const string &port, uint32_t baudrate, double timeout,
                bytesize_t bytesize, parity_t parity, stopbits_t stopbits,
                flowcontrol_t flowcontrol);

    //access functions
    bool configure();
    bool open();
    bool close();

    //read-write functions
    SerialMessage read();
    bool write(const SerialMessage&);

private:
    string port;
    uint32_t baudrate;
    bytesize_t bytesize;
    parity_t parity;
    stopbits_t stopbits;
    flowcontrol_t flowcontrol;
}