//
//  Sam Jones
//
#include <iostream>

#include "Room.h"
#include "BattleRoom.h"
#include "BlueMen.h"
#include "ReptilePeople.h"


BattleRoom::BattleRoom(std::string name, std::string enterText, int battleRoomNumber, Room* north, Room* east, Room* south, Room* west)
{
    this->roomName = name;
    this->onEnterText = enterText;
    this->canInvestigate = true;

    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;

    this->battleRoomNumber = battleRoomNumber;

    creature = new ReptilePeople("Lizard man");
    creatureDefeated = false;
    keyPickedUp = false;
}

BattleRoom::~BattleRoom()
{
    delete this->creature;
}


void BattleRoom::Investigate(Player& player)
{
    if(this->creatureDefeated)
    {
        player.SetKeyObtained(this->battleRoomNumber);
        SetKeyPickedUp();
        std::cout << "You found a key. This key will work in the warp room directly across the hall." << std::endl;
        return;
    }

    std::cout << "There is a " << this->creature->GetName() << " in the room!" << std::endl;
    std::cout << "It lunges out of the shadows claws first. Get ready to fight!" << std::endl;
 
    Character *fightSkills;
    fightSkills = new BlueMen("Blue Man");
    

    this->Battle(fightSkills);

    delete fightSkills;
}

void BattleRoom::Battle(Character *fightSkills)
{
    while (fightSkills->IsAlive() && this->creature->IsAlive())
    {
        if(fightSkills->IsAlive())
        {
            fightSkills->Attack(this->creature);
        }

        if (this->creature->IsAlive())
        {
            this->creature->Attack(fightSkills);
        }
    }

    if(fightSkills->IsAlive())
    {
        std::cout << "You killed the lizard." << std::endl;
        this->SetDefeated();

    }
    else
    {
        std::cout << "Youre going to lose this fight. You retreat to the shadows of the room... " << std::endl;

    }
}

void BattleRoom::SetDefeated()
{
    this->onEnterText = "Theres a dead lizard man in the room. Examine the corpse for anything helpful";
    creatureDefeated = true;
}

void BattleRoom::SetKeyPickedUp()
{
    this->onEnterText = "There is nothing else in this room.";
    keyPickedUp = true;
}

bool BattleRoom::GetInvestigatable()
{
    if(!creatureDefeated || !keyPickedUp)
        return true;

    return false;

}