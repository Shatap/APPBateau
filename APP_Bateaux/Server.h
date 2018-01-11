#ifndef SERVER_H
#define SERVER_H

#include "make-sockaddr.h"
#include "SendData.h"

#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>

const int MAX_DATA = 10;

class Server
{
private:
    char* m_serviceBeacon, *m_serviceClient;
    void addData(SendData data);
public:
    Server(char* service_beacon, char* service_client);
    void listenClient();
    void listenBeacon();
};

#endif // SERVER_H
