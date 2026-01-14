#include "Character.h"
#include <iostream>

using namespace std;

// CONSTRUCTORS

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

void Character::BasicAttack(Character& Target)
{
	Target.ReceiveDamage(m_Weapon->GetDamage());
}

void Character::ReceiveDamage(int Damage)
{
	m_Health -= Damage;
	if (m_Health < 0)
	{
		m_Health = 0;
	}
}


// DISPLAY

void Character::DisplayCharacter() const
{
	cout << "Name: " << GetName() << endl;
	cout << "Health: " << GetHealth() << endl;
	m_Weapon->DisplayWeapon();
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


// OPERATORS

Character& Character::operator=(Character const& CharacterToCopy)
{
	if (this != &CharacterToCopy)	// Adding & in front of the variable returns its adress
									// Important to check if we're not copying the same object (especially since we delete the weapon before assigning the copy)
	{
		m_Health = CharacterToCopy.m_Health;
		m_Name = CharacterToCopy.m_Name;

		delete m_Weapon;	// Deletes the weapon object. As the pointer will change its address, 
							// there wouldn't be any way to find the old weapon object
		m_Weapon = new Weapon(*CharacterToCopy.m_Weapon); // Creates a new Weapon object and assigns its address to the pointer
	}

	return *this;
}


// DESTRUCTOR

Character::~Character()
{
	delete m_Weapon; // Need to delete weapon, as it's a pointer and it would create a memory leak
}