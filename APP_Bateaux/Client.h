#ifndef CLIENT_H
#define CLIENT_H

#include "make-sockaddr.h"
#include "SendData.h"

#include <unistd.h>
#include <iostream>
#include <thread>

class Client
{
private:
    char* m_hostname;
    char* m_service;
public:
    Client(char *hostname, char *service);
    void makeRequestToServer();
};

#endif // CLIENT_H
