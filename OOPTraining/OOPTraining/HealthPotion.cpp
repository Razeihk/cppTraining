#include "HealthPotion.h"

using namespace std;
namespace HealthPotionConsts
{
	constexpr int lowHealth = 20;
	constexpr int mediumHealth = 50;
	constexpr int bigHealth = 100;
}

HealthPotion::HealthPotion(string potionType):m_type(potionType)
{
	if (potionType == "Small")
	{
		m_health = HealthPotionConsts::lowHealth;
	}
	else if (potionType == "Medium")
	{
		m_health = HealthPotionConsts::mediumHealth;
	}
	else
	{
		m_health = HealthPotionConsts::bigHealth;
	}
}

string HealthPotion::getPotionType()
{
	return m_type;
}

int HealthPotion::getPotionHealth()
{
	return m_health;
}