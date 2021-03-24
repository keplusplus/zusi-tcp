#include <iostream>
#include <iomanip>
#include "src/SysSocket.h"
#include "src/Attribute.h"

using namespace std;

void dump_bytes(unsigned char* b, int len) {
    cout << "Length: " << len << " bytes" << endl;
    for(int i = 0; i < len; i++) {
        if(i > 0) cout << " ";
        cout << "0x" << setfill('0') << setw(2) << hex << uppercase << static_cast<unsigned>(*(b + i));
    }
    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    SysSocket socket = SysSocket();
    int conn = socket.conn("127.0.0.1", 1436);
    if(conn) {
        cout << "Connection established." << endl;
    } else {
        cout << "Socket connection failed." << endl;
        return 0;
    }

    Attribute attr = Attribute(&socket);
    attr.setLength(10);
    unsigned char id[] = { 0x03, 0x00 };
    attr.setId(id);
    unsigned char data[] = { 0x46, 0x61, 0x68, 0x72, 0x70, 0x75, 0x6C, 0x74 };
    attr.setData(data);

    /*unsigned char data[] = { 0x00, 0x01, 0x02, 0x03 };
    int send = socket.send(data, sizeof(data));
    if(send) {
        cout << "Data sent." << endl;
    } else {
        cout << "Data not sent." << endl;
        return 0;
    }

    cout << "Everything was successful!" << endl;*/

    return 0;
}
