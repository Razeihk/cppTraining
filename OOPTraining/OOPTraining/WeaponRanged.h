#pragma once

#include <string>

class WeaponRanged
{
public:
	WeaponRanged();
	WeaponRanged(std::string name, int damage, int range);

	void changeWeapon(WeaponRanged newWeaponRanged);
	void display() const;

	//GETTERS
	std::string getName() const;
	int getDamage() const;
	int getRange() const;

private:
	std::string m_Name;
	int m_Damage;
	int m_Range;
};

