#pragma once
#include <string>

class Spell
{

public:
	Spell(std::string name, int manaCost, int damage);
	std::string getName() const;
	int getManaCost() const;
	int getDamage() const;
	void display() const;

private:
	
	std::string m_name;
	int m_manaCost;
	int m_damage;
};