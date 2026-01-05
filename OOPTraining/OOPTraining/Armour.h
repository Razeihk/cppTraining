#pragma once
#include <string>

class Armour
{
public:
	
	Armour();
	Armour(std::string name, int damageReduction);

	void changeArmour(Armour newArmour);

	void display() const;

	// GETTERS
	std::string getName() const;
	int getDamageReduction() const;

private:
	std::string m_Name;
	int m_damageReduction;

};

