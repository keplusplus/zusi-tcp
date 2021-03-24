//
// Created by keile on 22.03.2021.
//

#ifndef ZUSI_TCP_SOCKET_H
#define ZUSI_TCP_SOCKET_H

class Socket {
public:
    virtual ~Socket() { }
    virtual unsigned char* receive(unsigned int length) = 0;
    virtual bool send(unsigned char* data, unsigned int length) = 0;
};

#endif //ZUSI_TCP_SOCKET_H
