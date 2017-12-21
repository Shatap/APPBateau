#include "Beacon.h"

Beacon::Beacon(std::string name, int id, int x, int y, int speed, Heading heading, char* hostname, char* service) :
    m_hostname{hostname}, m_service{service}, m_id{id}, m_x{x}, m_y{y}, m_speed{speed}, m_heading{heading}, m_name{name}
{
}

void Beacon::update()
{
    switch(m_heading)
    {
    case NORTH :
        m_y += m_speed;
        break;
    case NORTH_EAST :
        m_x += m_speed;
        m_y += m_speed;
        break;
    case EAST :
        m_x += m_speed;
        break;
    case SOUTH_EAST :
        m_y -= m_speed;
        m_x += m_speed;
        break;
    case SOUTH :
        m_y -= m_speed;
        break;
    case SOUTH_WEST :
        m_y -= m_speed;
        m_x -= m_speed;
        break;
    case WEST :
        m_x -= m_speed;
        break;
    case NORTH_WEST :
        m_x -= m_speed;
        m_y += m_speed;
        break;
    }
}

void Beacon::sendToServer()
{
    auto server_address = remote_socket_address(m_hostname, SOCK_DGRAM, m_service);
    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    SendData data(m_id, m_x, m_y, m_speed, m_name, m_heading);

    int size = sendto(fd, &data, sizeof data,
                      0,
                      (sockaddr *)&server_address, sizeof server_address);

    if(size == sizeof data)
    {
        std::cout << "Data sent !" << std::endl;
    }
    else
    {
        std::cout << "Data not sent..." << std::endl;
    }

    close(fd);
}
