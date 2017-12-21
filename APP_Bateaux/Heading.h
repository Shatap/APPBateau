#ifndef HEADING_H
#define HEADING_H

#include <string>

enum Heading {   // =cap
    NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST
};

inline const std::string ToString(Heading heading)
{
    switch(heading)
    {
        case NORTH : return "North";
        case NORTH_EAST : return "North East";
        case EAST : return "East";
        case SOUTH_EAST : return "South East";
        case SOUTH : return "South";
        case SOUTH_WEST : return "South West";
        case WEST : return "West";
        case NORTH_WEST : return "North West";
    }
}

#endif // HEADING_H
