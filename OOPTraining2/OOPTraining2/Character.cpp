#include "Character.h"
#include <iostream>

using namespace std;

// CONSTRUCTORS

Character::Character()
	:m_Weapon(nullptr)
{

}

Character::Character(string Name, string& WeaponName)
	:m_Name(Name), m_Weapon(new Weapon(WeaponName))
{
	
}

Character::Character(Character const& Character)
	:m_Name(Character.m_Name), m_Health(Character.m_Health)
{
	m_Weapon = new Weapon(*(Character.m_Weapon));
	// m_Weapon is a pointer
	// new Weapon creates a new object, and the pointer points to this new object (so it's a new pointer and a new object)
	// the new Weapon takes all the parameters of the Character's weapon
}


// FUNCTIONS

void Character::Attack(Character& Target)
{
	Target.ReceiveDamage(m_Weapon->GetDamage());
}

void Character::ReceiveDamage(int Damage)
{
	m_Health -= Damage;
}


// DISPLAY

void Character::DisplayCharacter() const
{
	cout << "Name: " << GetName() << endl;
	cout << "Health: " << GetHealth() << endl;
	m_Weapon->DisplayWeapon();
	cout << endl;
}

void Character::DisplayWeaponPointer() const
{
	cout << "Weapon pointer: " << m_Weapon << endl;
}


// GETTERS

string Character::GetName() const
{
	return m_Name;
}

int Character::GetHealth() const
{
	return m_Health;
}


// DESTRUCTOR

Character::~Character()
{
	delete m_Weapon; // Need to delete weapon, as it's a pointer and it would create a memory leak
}