#include "SendData.h"

using namespace std;

SendData::SendData(int id, int x, int y, int speed, std::string name, Heading heading)
    : m_id{id}, m_x{x}, m_y{y}, m_speed{speed}, m_name{name}, m_heading{heading}
{}
/*
SendData::SendData(const SendData &data) : SendData(data.getId(), data.getX(), data.getY(), data.getSpeed(), data.getName(), data.getHeading())
{
}*/



int SendData::getId() const
{
    return m_id;
}

int SendData::getX() const
{
    return m_x;
}

int SendData::getY() const
{
    return m_y;
}

int SendData::getSpeed() const
{
    return m_speed;
}

std::string SendData::getName() const
{
    return m_name;
}

string SendData::getStringHeading() const
{
    return ToString(m_heading);
}

Heading SendData::getHeading() const
{
    return m_heading;
}
