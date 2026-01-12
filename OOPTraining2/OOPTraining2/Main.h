#pragma once

#include "Character.h"

std::string WeaponNames[4]
{
	"Rusty sword",
	"Great Sword",
	"Double Axe",
	"Spear"

};


Character Hero("Hero", WeaponNames[1]);
Character Enemy("Enemy", WeaponNames[0]);
Character Enemy2(Enemy);