//
// Created by keile on 22.03.2021.
//

#ifndef ZUSI_TCP_ATTRIBUTE_H
#define ZUSI_TCP_ATTRIBUTE_H

#include "Socket.h"

class Attribute {
private:
    Socket* sock;
    int length;
    unsigned char* id;
    unsigned char* data;

public:
    Attribute(Socket* s);
    bool read();
    bool write();
    int getLength();
    void setLength(int l);
    unsigned char* getId();
    void setId(unsigned char* i);
    unsigned char* getData();
    void setData(unsigned char* d);
};


#endif //ZUSI_TCP_ATTRIBUTE_H
