
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include "oopTraining.h"
#include "Character.h"
#include "Duration.h"

#include <vector>

using namespace std;

int main()
{
	durationExercise();
	
}

void rpgFight()
{
#pragma region objects
	Weapon greatSword("Great sword", 20);
	Weapon spear("Spear", 10);
	Weapon doubleAxe("Double Axe", 30);

	WeaponRanged simpleBow("Simple Bow", 5, 5);
	WeaponRanged longbow("Longbow", 10, 15);
	WeaponRanged crossbow("Crossbow", 20, 30);

	Armour lightArmour("Light Armour", 1);
	Armour mediumArmour("Medium Armour", 3);
	Armour heavyArmour("Heavy Armour", 5);

	Spell fireball("Fireball", 20, 40);
	Spell acidball("Acidball", 40, 50);

	HealthPotion lowHealthPotion("Small");
	HealthPotion mediumHealthPotion("Medium");
	HealthPotion bigHealthPotion("Big");

	Character hero("Hero", 0, greatSword, fireball, mediumArmour);
	Character enemy("Enemy", 0, spear, simpleBow);
	Character enemy2("Enemy2", 15, spear, simpleBow);
#pragma endregion


	hero.displayState();
	enemy.displayState();
	enemy2.displayState();


	// FIGHT

	hero.attack(enemy);
	enemy.attack(hero);
	hero.throwSpell(enemy2);
	enemy2.drinkHealthPotion(lowHealthPotion);
	
	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();

	hero.changeWeapon(doubleAxe);
	enemy.attack(hero);
	hero.attack(enemy);
	enemy2.attackRanged(hero);

	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();

	hero.attack(enemy);
	enemy.drinkHealthPotion(lowHealthPotion);
	hero.attack(enemy);
	enemy2.changeWeaponRanged(crossbow);

	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();

	hero.attack(enemy);
	enemy2.attackRanged(hero);
	hero.move(hero.getSpeed(), enemy2);

	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();

	hero.attack(enemy2);
	enemy2.attack(hero);
	hero.attack(enemy2);

	cout << endl;
	hero.displayState();
	enemy.displayState();
	enemy2.displayState();
}

void createAndDisplay(Character character)
{
	character.displayState();
}

void durationExercise()
{
	Duration duration01(1, 0, 0);
	Duration duration02(1, 0, 0);
	Duration duration03;

	/*int tempSeconds = (duration01.getHours() * 3600) + (duration01.getMinutes() * 60) + duration01.getSeconds();

	cout << tempSeconds << endl;*/
	

	//duration01.displayTime();
	//duration02.displayTime();

	duration03 = duration01 - duration02;
	cout << (duration01 == duration02);
	/*duration03.displayTime();

	duration03 += 100;

	duration03.displayTime();*/


	/*cout << (duration01 == duration02) << endl;
	cout << (duration01 != duration02) << endl;
	cout << (duration01 < duration02) << endl;
	cout << (duration01 > duration02) << endl;
	cout << (duration01 <= duration02) << endl;
	cout << (duration01 >= duration02) << endl;*/
}