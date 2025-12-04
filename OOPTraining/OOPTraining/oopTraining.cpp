
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include "oopTraining.h"
#include "Character.h"

using namespace std;


int main()
{
	rpgFight();
}

void rpgFight()
{
	Character hero;
	Character enemy;
	Character characterCopy(enemy); // Creates another character, a copy of enemy, with its attributes
	

	hero.attack(enemy);
	cout << "Hero attacked enemy" << endl << endl;
	cout << "Hero" << endl;
	hero.displayState();
	cout << "Enemy" << endl;
	enemy.displayState();

	cout << endl;
	enemy.drinkHealthPotion(100);
	cout << "Enemy drinks health potion" << endl;

	enemy.attack(hero);
	cout << "Enemy attacked hero" << endl;
	hero.attack(enemy);
	cout << "Hero attacked enemy" << endl << endl;
	cout << "Hero" << endl;
	hero.displayState();
	cout << "Enemy" << endl;
	enemy.displayState();

	cout << endl;
	enemy.changeWeapon("Double axe", 30);
	cout << "Enemy has changed weapon" << endl << endl;
	cout << "Enemy" << endl;
	enemy.displayState();

	cout << endl;
	enemy.attack(hero);
	cout << "Enemy attacked hero" << endl << endl;
	cout << "Hero" << endl;
	hero.displayState();
	cout << "Enemy" << endl;
	enemy.displayState();

}

void createAndDisplay()
{
	Character hero;
	hero.displayState();
}