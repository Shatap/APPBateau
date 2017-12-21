#ifndef SENDDATA_H
#define SENDDATA_H

#include "Heading.h"
#include <string>

class SendData
{
private :
    int m_id,m_x,m_y,m_speed;
    std::string m_name;
    Heading m_heading;

public:
    SendData() = default;
    //SendData(const SendData& data);
    SendData(int id, int x, int y, int speed, std::string name, Heading heading);
    int getId() const;
    int getX() const;
    int getY() const;
    int getSpeed() const;
    std::string getName() const;
    std::string getStringHeading() const;
    Heading getHeading() const;
};

#endif // SENDDATA_H
