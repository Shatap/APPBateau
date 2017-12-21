#ifndef TESTSERVER_H
#define TESTSERVER_H

#include "make-sockaddr.h"
#include "SendData.h"

#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>

const int MAX_DATA = 10;

class TestServer
{
private:
    char* m_serviceBeacon, *m_serviceClient;
    void addData(SendData data);
public:
    TestServer(char* service_beacon, char* service_client);
    void listenClient();
    void listenBeacon();
};

#endif // TESTSERVER_H
