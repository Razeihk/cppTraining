#include "Bike.h"
#include <iostream>
#include <string>

using namespace std;

Bike::Bike()
{
	m_NumberOfWheels = 2;
	m_Type = "Bike";
}

Bike::Bike(int Price, int Year, int MaxSpeed)
	:Vehicle(Price, Year), m_MaxSpeed(MaxSpeed)
{
	m_NumberOfWheels = 2;
	m_Type = "Bike";
}

void Bike::DisplayVehicle() const
{
	cout << "This is a bike, it costs " << m_Price << " euros and it goes up to " << m_MaxSpeed << " km/h." << endl;
	Vehicle::DisplayWheels();
	Vehicle::DisplayYear();
	cout << endl;
}

Bike::~Bike()
{
}
