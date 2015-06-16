
#pragma once
#ifndef _CS162_FINAL_WORLD_H_
#define _CS162_FINAL_WORLD_H_

#include "Room.h"
#include <vector>

const int NUM_TURNS = 50;

class World
{
private:
    std::vector<Room*> rooms;
    Room* currentRoom;
    Room* entryPoint;
    int numTurns;

public:
    World();
    ~World();

    void addRoom(Room*);
    Room* getCurrentRoom();
    Room* getStart();
    void setCurrentRoom(Room*);
    void setStart(Room*);
    void turnOver();
    int getTurns();

};


#endif
