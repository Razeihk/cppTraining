
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
	Weapon greatSword("Great sword", 20);
	Weapon spear("Spear", 10);
	Weapon doubleAxe("Double Axe", 30);

	Spell fireball("Fireball", 20, 40);
	Spell acidball("Acidball", 40, 50);

	Character hero("Hero", greatSword, fireball);
	Character enemy("Enemy", spear);
	Character enemy2(enemy);

	hero.displayState();
	enemy.displayState();
	enemy2.displayState();


	// FIGHT

	hero.attack(enemy);
	enemy.attack(hero);
	hero.throwSpell(enemy2);
	enemy2.drinkHealthPotion(10);
	
	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();

	hero.changeWeapon(doubleAxe);
	enemy.attack(hero);
	hero.attack(enemy2);
	enemy2.attack(hero);

	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();
}

void createAndDisplay(Character character)
{
	character.displayState();
}