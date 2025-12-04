
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include "oopTraining.h"
#include "Character.h"

using namespace std;


int main()
{
	createAndDisplay();
}

void rpgFight()
{
	Character hero("Epee rouillee", 10);
	Character enemy("Epee aiguisee", 20);
	Character characterCopy(enemy); // Creates another character, a copy of enemy, with its attributes
	

	hero.attack(enemy);
	enemy.drinkHealthPotion(100);
	enemy.attack(hero);
	hero.attack(enemy);

	enemy.changeWeapon("Double axe", 30);
	enemy.attack(hero);

}

void createAndDisplay()
{
	Character hero;
	hero.displayState();
}