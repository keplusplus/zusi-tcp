//
// Created by keile on 22.03.2021.
//

#include "Attribute.h"

Attribute::Attribute(Socket *s) : sock(s) {
    length = -1;
    id = nullptr;
    data = nullptr;
}

bool Attribute::read() {
    if(length == -1) {
        return false;
    }

    unsigned char* received_id = sock->receive(2);
    if(received_id == nullptr) {
        return false;
    }

    this->id = received_id;

    unsigned char* received_data = sock->receive(length - 2);
    if(received_data == nullptr) {
        return false;
    }

    this->data = received_data;

    return true;
}

bool Attribute::write() {
    if(length == -1 || id == nullptr || data == nullptr) {
        return false;
    }

    bool s1 = sock->send(reinterpret_cast<unsigned char*>(&length), 4);
    if(!s1) {
        return false;
    }

    bool s2 = sock->send(id, 2);
    if(!s2) {
        return false;
    }

    bool s3 = sock->send(data, length - 2);
    if(!s3) {
        return false;
    }

    return true;
}

int Attribute::getLength() {
    return length;
}

void Attribute::setLength(int l) {
    length = l;
}

unsigned char* Attribute::getId() {
    return id;
}

void Attribute::setId(unsigned char* i) {
    id = i;
}

unsigned char* Attribute::getData() {
    return data;
}

void Attribute::setData(unsigned char* d) {
    data = d;
}