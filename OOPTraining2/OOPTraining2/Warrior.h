#pragma once

#include "Character.h"

class Warrior :
    public Character
{
public:

    //CONSTRUCTORS
    Warrior(std::string Name, std::string WeaponName, std::string ArmourType);


    // DISPLAY
    void DisplayCharacter() const;

private:
    std::string m_ArmourType = "No armour";
    int m_ArmourEfficiency = 0;
};

