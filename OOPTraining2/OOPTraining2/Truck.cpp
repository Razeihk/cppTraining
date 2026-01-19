#include <iostream>

#include "Truck.h"

using namespace std;


Truck::Truck()
{
	m_NumberOfWheels = 8;
	m_Type = "Truck";
}

Truck::Truck(int Price, int Year, int MaxWeight)
	:Vehicle(Price, Year), m_MaxWeight(MaxWeight)
{
	m_NumberOfWheels = 8;
	m_Type = "Truck";
}

void Truck::DisplayVehicle() const
{
	cout << "This is a truck, it costs " << m_Price << " euros and it can transport up to " << m_MaxWeight << "kg." << endl;
	Vehicle::DisplayWheels();
	Vehicle::DisplayYear();
	cout << endl;
}

