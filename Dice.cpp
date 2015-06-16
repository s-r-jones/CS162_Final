/******************************************************************************
 * Sam Jones jonesamu
 * Date: 5/1/2015
 * Description: Implementation file for Dice class
 ******************************************************************************/

#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include "Dice.h"

Dice::Dice(int numSides)
{
    this->numSides = numSides;
}

int Dice::rollDice()
{
    return (rand() % numSides) +1;
}




