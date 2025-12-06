#pragma once

#include <string>

class HealthPotion
{
public:
	HealthPotion(std::string type);

	// GETTERS
	std::string getPotionType();
	int getPotionHealth();


private:
	std::string m_type;
	int m_health;


};

