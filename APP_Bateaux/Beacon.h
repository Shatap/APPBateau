#ifndef BEACON_H
#define BEACON_H

#include "make-sockaddr.h"
#include "SendData.h"
#include <unistd.h>
#include <string>
#include <iostream>

class Beacon
{
private :
    char* m_hostname;
    char* m_service;

    int m_id, m_x,m_y, m_speed; // coordinates
    Heading m_heading;
    std::string m_name; // ship name

public:
    Beacon(std::string name, int id, int x, int y, int speed, Heading heading, char* hostname, char* service);
    void update();
    void sendToServer();
};

#endif // BEACON_H
