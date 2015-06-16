#include <string>
#include <iostream>
#include "world.h"
#include "Player.h"
#include "BattleRoom.h"
#include "CoreRoom.h"
#include "StandardRoom.h"
#include "Bridge.h"
using std:: string;
using std:: cout;


World* createWorld()
{
    World* gameWorld = new World;
  

    //Room 1 (Startpoint)
    string room1Name = "Start";
    string room1Text = "You wake up alone and sleepy eyed in your room.\n"
                            "The floor is rumbling and You hear the monotone voice of the computer... 'Hull breach core meltdown imminent...'";
    Room* Room1 = new StandardRoom(room1Name, room1Text, NULL, NULL, NULL, NULL);
    gameWorld->addRoom(Room1);
    gameWorld->setStart(Room1);

    //Room 2 (Hallway 1)
    string room2Name = "Hallway 1";
    string room2Text = "There is a long hallway with a door to the east and the west.\n"
                            "Damn it, the lizard men must have finally found us.\n Someone must of set the core to explode while the lizards are still on board.\n You remember something abou the warp core... it can be shut down\n"
                            "via a sequence of three keys and a command at the bridge.\n"
                            "Great now I have to search for these keys... you look up as you hear a loud banging from the room to the west...";

    Room* Room2 = new StandardRoom(room2Name, room2Text, NULL, NULL, Room1, NULL);
    Room1->setNorthRoom(Room2);
    gameWorld->addRoom(Room2);

    //Room 3 (Hallway1 - West Room)
    string room3Name = "Battle Room 1";
    string room3Text = "You hear something in the corner but cant see it in the shadows...";
    Room* Room3 = new BattleRoom(room3Name, room3Text, 1, NULL, Room2, NULL, NULL);
    Room2->setWestRoom(Room3);
    gameWorld->addRoom(Room3);

    //Room 4 (Hallway 1 - East Room)
    string room4Name = "Core Room 1";
    string room4Text = "The core is still active but overheating... there is a lit slot for a key on the control panel...";
    Room* Room4 = new CoreRoom(room4Name, room4Text, 1, NULL, NULL, NULL, Room2);
    Room2->setEastRoom(Room4);
    gameWorld->addRoom(Room4);

    //Room 5 (Hallway 2)
    string room5Name = "Hallway 2";
    string room5Text = "You're in a long hallway. You here hear a loud smashes to the west...";
    Room* Room5 = new StandardRoom(room5Name, room5Text, NULL, NULL, Room2, NULL);
    Room2->setNorthRoom(Room5);
    gameWorld->addRoom(Room5);

    //Room 6  (Hallway2 - West Room)
    string room6Name = "Battle Room 2";
    string room6Text = "You hear a stack of boxes fall in the corner...";
    Room* Room6 = new BattleRoom(room6Name, room6Text, 2, NULL, Room5, NULL, NULL);
    Room5->setWestRoom(Room6);
    gameWorld->addRoom(Room6);

    //Room 7  (Hallway2 - East Room)
    string room7Name = "Core Room 2";
    string room7Text = "The core is still active but overheating... there is a lit slot for a key on the control panel...";
    Room* Room7 = new CoreRoom(room7Name, room7Text, 2, NULL, NULL, NULL, Room5);
    Room5->setEastRoom(Room7);
    gameWorld->addRoom(Room7);

    //Room 8 (Hallway 3)
    string room8Name = "Hallway 3";
    string room8Text = "You are at the end of the long hallway. The ships bridge is straight ahead.\n"
                            "Again, you hear a loud banging to the west...";
    Room* Room8 = new StandardRoom(room8Name, room8Text, NULL, NULL, Room5, NULL);
    Room5->setNorthRoom(Room8);
    gameWorld->addRoom(Room8);

    //Room 9 (Hallway2 - West Room)
    string room9Name = "Battle Room 2";
    string room9Text = "You hear something lurking in the corner...";
    Room* Room9 = new BattleRoom(room9Name, room9Text, 3, NULL, Room8, NULL, NULL);
    Room8->setWestRoom(Room9);
    gameWorld->addRoom(Room9);

    //Room 10 (Hallway2 - East Room)
    string room10Name = "Core Room 2";
    string room10Text = "The core is still active but overheating... there is a lit slot for a key on the control panel...";
    Room* Room10 = new CoreRoom(room10Name, room10Text, 3, NULL, NULL, NULL, Room8);
    Room8->setEastRoom(Room10);
    gameWorld->addRoom(Room10);

    //Bridge
    string bridgeName = "Bridge";
    string bridgeText = "The computer opens the bridge doors. You step in a quickly look around.y\nIts odly quite, No ones here. You see the core controls in the  "
                                "center of the room.";
    Room* bridge = new Bridge(bridgeName, bridgeText, NULL, NULL, Room8, NULL);
    Room8->setNorthRoom(bridge);
    gameWorld->addRoom(bridge);


    return gameWorld;
}

void gameLoop(World* gameWorld)
{
    Player player;

    cout << "*********** Get ready to play! ************" << std::endl << std::endl;
    gameWorld->setCurrentRoom(gameWorld->getStart());

    do
    {

        char command;


        cout << gameWorld->getCurrentRoom()->getIntroText() << std::endl;
        cout << "Computer: You have " << gameWorld->getTurns() << " turns before complete core meltdown." << std::endl;

        cout << "Which way do you want to go?" << std::endl << "You can ";
        if(gameWorld->getCurrentRoom()->getRoomTo(NORTH))
            cout << " Move (n)orth, ";
        if(gameWorld->getCurrentRoom()->getRoomTo(EAST))
            cout << " Move (e)ast, ";
        if(gameWorld->getCurrentRoom()->getRoomTo(SOUTH))
            cout << " Move (s)outh, ";
        if(gameWorld->getCurrentRoom()->getRoomTo(WEST))
            cout << " Move (w)est, ";
        if(gameWorld->getCurrentRoom()->GetInvestigatable())
            cout << " (i)nspect, ";

        cout << " e(x)it" << std::endl << std::endl;

        cout << "Enter your move: ";
        command = std::getchar();
        std::cin.ignore(1000, '\n');

        switch(tolower(command))
        {
            case 'n':
            {
                Room *tmpRoom = gameWorld->getCurrentRoom()->getRoomTo(NORTH);
                if (tmpRoom == NULL)
                    cout << "You can't go that way." << std::endl;
                else
                {
                    cout << "Moving one room to the north." << std::endl << std::endl;
                    gameWorld->turnOver();
                    gameWorld->setCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'e':
            {
                Room *tmpRoom = gameWorld->getCurrentRoom()->getRoomTo(EAST);
                if (tmpRoom == NULL)
                    cout << "You can't go that way." << std::endl;
                else
                {
                    cout << "Moving one room to the east." << std::endl << std::endl;
                    gameWorld->turnOver();
                    gameWorld->setCurrentRoom(tmpRoom);
                }

                break;
            }
            case 's':
            {
                Room *tmpRoom = gameWorld->getCurrentRoom()->getRoomTo(SOUTH);
                if (tmpRoom == NULL)
                    cout << "You can't go that way." << std::endl;
                else
                {
                    cout << "Moving one room to the south." << std::endl << std::endl;
                    gameWorld->turnOver();
                    gameWorld->setCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'w':
            {
                Room *tmpRoom = gameWorld->getCurrentRoom()->getRoomTo(WEST);
                if (tmpRoom == NULL)
                    cout << "You can't go that way." << std::endl;
                else
                {
                    cout << "Moving one room to the west." << std::endl << std::endl;
                    gameWorld->turnOver();
                    gameWorld->setCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'i':
            {
                gameWorld->getCurrentRoom()->Investigate(player);
                gameWorld->turnOver();
                break;
            }
            case 'x':
            {
                cout << "Thanks for playing :]" << std::endl;
                delete gameWorld;
                exit(0);
            }
            default:
            {
                cout << "You cant do that!" << std::endl;
            }
        }
    } while(!player.GetPlayerWon() && gameWorld->getTurns() > 0);

    if(player.GetPlayerWon())
    {
        cout << "You've stopped the ship from being destroyed!" << std::endl;
    }
    else
    {
        cout << "You are out of time... The ship starts to shake even harder. You turn around and instantly feel the heat; \n you see the fireball engulfing the hallway  Darkness overtakes you." << std::endl;
    }

    delete gameWorld;

}

int main()
{
    srand(time(NULL));

    char hint;
    do
    {
        cout << "Do you want some hints (y/n): ";
        hint = std::getchar();
        std::cin.ignore(1000, '\n');

        if(hint == 'y')
        {
            cout << "1. Your first move is north.\n"
                         "-  Then go west first/east second for each segment of hallway\n"

                         "-  Each key works on the core in the room across from it...\n";
            break;
        }
        else if(hint == 'n')
            break;
        else
            continue;
    }
    while(true);

    
    World* gameWorld = createWorld();

    gameLoop(gameWorld);

    return 0;
}