/******************************************************************************
 * Sam Jones jonesamu
 * Date: 5/1/2015
 * Description: Header file for character Dice class
 ******************************************************************************/
#pragma once
#ifndef __fantasyBattleRoyal__Dice__
#define __fantasyBattleRoyal__Dice__

class Dice
{
protected:
    int numSides;
    
public:
    Dice(int numSides);
    virtual int rollDice();
};

#endif
