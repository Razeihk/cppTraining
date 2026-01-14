#pragma once

#include "Character.h"
#include "Warrior.h"
#include "Magician.h"

std::string WeaponNames[4]
{
	"Rusty sword",
	"Great sword",
	"Double axe",
	"Spear"

};

std::string ArmourNames[3]
{
	"Light armour",
	"Medium armour",
	"Heavy armour"
};


Warrior Hero("Hero", WeaponNames[1], ArmourNames[2]);
Character Enemy("Enemy", WeaponNames[0]);
Character Enemy2(Enemy);