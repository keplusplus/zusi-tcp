//
// Created by keile on 22.03.2021.
//

#ifndef ZUSI_TCP_SYSSOCKET_H
#define ZUSI_TCP_SYSSOCKET_H

#include <sys/socket.h> // socket related
#include <arpa/inet.h>  // inet_addr
#include <netdb.h>      // hostent
#include <string>       // string
#include "Socket.h"

using namespace std;

class SysSocket : public Socket {
private:
    int sock, port, response_length{};
    string address;
    unsigned char* response_data{};
    struct sockaddr_in server{};

public:
    SysSocket();
    bool conn(string address, int p);
    virtual bool send(unsigned char *data, unsigned int length) override;
    virtual unsigned char* receive(unsigned int length) override;
};


#endif //ZUSI_TCP_SYSSOCKET_H
