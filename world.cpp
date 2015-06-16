

#include "world.h"

World::World()
{
    numTurns = NUM_TURNS;
}
World::~World()
{
    int numRooms = rooms.size();

    for(int i = 0; i < numRooms; i++)
    {
        Room* tmpRoom = this->rooms.back();
        this->rooms.pop_back();
        delete tmpRoom;
    }
}

void World::addRoom(Room* room)
{
    this->rooms.push_back(room);
}

Room* World::getCurrentRoom()
{
    return this->currentRoom;
}

Room* World::getStart()
{
    return this->entryPoint;
}

void World::setStart(Room* start)
{
    this->entryPoint = start;
}

void World::setCurrentRoom(Room* current)
{
    this->currentRoom = current;
}

void World::turnOver()
{
    numTurns--;
}

int World::getTurns()
{
    return numTurns;
}

