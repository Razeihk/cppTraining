
#pragma region libraries
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include "oopTraining.h"
#include "Character.h"
#pragma endregion



using namespace std;

int main()
{
	rpgFight();
}

void rpgFight()
{
	Character hero;
	Character enemy;

	hero.attack(enemy);
	enemy.drinkHealthPotion(100);
	enemy.attack(hero);
	hero.attack(enemy);

	enemy.changeWeapon("Double axe", 30);
	enemy.attack(hero);

}