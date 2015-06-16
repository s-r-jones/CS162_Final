//
// 
//
#pragma once
#ifndef _CS162_FINAL_ROOM_H_
#define _CS162_FINAL_ROOM_H_

#include <string>
#include "Player.h"

enum Direction { NORTH, EAST, SOUTH, WEST };

class Room {

protected:
    Room* north;
    Room* east;
    Room* south;
    Room* west;

    std::string roomName;
    std::string onEnterText;
    bool canInvestigate;

public:
    Room();
    virtual ~Room() = 0;

    virtual Room* getRoomTo(Direction);
    virtual std::string getIntroText();

    virtual void setNorthRoom(Room*);
    virtual void setEastRoom(Room*);
    virtual void setSouthRoom(Room*);
    virtual void setWestRoom(Room*);

    virtual void Investigate(Player&);

    virtual bool GetInvestigatable();

};


#endif //_CS162_FINAL_ROOM_H_
