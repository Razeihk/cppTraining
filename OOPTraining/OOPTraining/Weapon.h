#pragma once

#include <string>

class Weapon
{
public:

	Weapon();
	Weapon(std::string name, int damage);
	void changeWeapon(std::string name, int damage);
	void display() const;

	// GETTERS
	int getDamage()const;
	std::string getName()const;

private:

	std::string m_name;
	int m_damage;

};