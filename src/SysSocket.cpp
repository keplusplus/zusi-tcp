//
// Created by keile on 22.03.2021.
//
#include "SysSocket.h"

SysSocket::SysSocket() {
    sock = -1;
    port = 0;
    address = "";
}

bool SysSocket::conn(string address, int p) {
    address = address;
    port = p;

    if(sock == -1) {
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if(sock == -1) {
            return false;
        }
    }

    if(inet_addr(address.c_str()) == -1) {
        struct hostent* he;
        struct in_addr** addr_list;

        if((he = gethostbyname(address.c_str())) == NULL) {
            return false;
        }

        addr_list = (struct in_addr**) he->h_addr_list;

        for(int i = 0; addr_list[i] != NULL; i++) {
            server.sin_addr = *addr_list[i];
            break;
        }
    } else {
        server.sin_addr.s_addr = inet_addr(address.c_str());
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if(connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        return false;
    }

    return true;
}

unsigned char* SysSocket::receive(unsigned int length) {
    unsigned char buffer[length];

    int r = recv(sock, buffer, length, 0);
    if(r < 0) {
        return nullptr;
    }

    response_data = buffer;
    response_length = r;

    return response_data;
}

bool SysSocket::send(unsigned char *data, unsigned int length) {
    if(::send(sock, data, length, 0) < 0) {
        return false;
    }

    return true;
}