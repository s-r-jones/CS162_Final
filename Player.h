//
//  Sam Jones
//
#pragma once
#ifndef _CS162_FINAL_PLAYER_H_
#define _CS162_FINAL_PLAYER_H_


class Player
{
private:

    bool key1Obtained;
    bool key2Obtained;
    bool key3Obtained;

    bool core1Verification;
    bool core2Verification;
    bool core3Verification;

    bool won;

public:
    Player();
    ~Player();
    void SetKeyObtained(int);
    bool GetKeyObtained(int);

    void SetCoreVerificationObtained(int);
    bool GetCoreVerificationObtained(int);

    void SetPlayerWon();
    bool GetPlayerWon();

};


#endif //_CS162_FINAL_PLAYER_H_
