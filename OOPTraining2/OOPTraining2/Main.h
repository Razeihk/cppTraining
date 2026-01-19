#pragma once


#pragma region Includes RPG
#include "Character.h"
#include "Warrior.h"
#include "Magician.h"
#pragma endregion

#pragma region Includes Garage
#include "Garage.h"
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"
#pragma endregion

#include "Fraction.h"

// FUNCTIONS

void GarageExercise();
void OOPPart2Exercise();


// VARIABLES

#pragma region RPG
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
#pragma endregion

#pragma region Garage

Garage MyGarage;

#pragma endregion


