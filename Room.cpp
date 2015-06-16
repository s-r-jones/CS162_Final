//
//  Sam Jones
//

#include <stddef.h>
#include "Room.h"



Room::Room() {}
Room::~Room() {}

std::string Room::getIntroText()
{
    return onEnterText;
}

Room* Room::getRoomTo(Direction direction)
{
    switch(direction)
    {
        case NORTH:
            return this->north;
        case EAST:
            return this->east;
        case SOUTH:
            return this->south;
        case WEST:
            return this->west;
        default:
            return NULL;
    }
}

void Room::setNorthRoom(Room * north)
{
    this->north = north;
}

void Room::setEastRoom(Room * east)
{
    this->east = east;
}

void Room::setSouthRoom(Room * south)
{
    this ->south = south;
}

void Room::setWestRoom(Room * west)
{
    this->west = west;
}

bool Room::GetInvestigatable()
{
    return canInvestigate;
}

void Room::Investigate(Player& player)
{
}