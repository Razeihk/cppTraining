#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car()
{
	m_NumberOfWheels = 4;
	m_Type = "Car";
}

Car::Car(int Price, int Year, int NumberOfDoors)
	:Vehicle(Price, Year), m_NumberOfDoors(NumberOfDoors)
{
	m_NumberOfWheels = 4;
	m_Type = "Car";
}

void Car::DisplayVehicle() const
{
	cout << "This is a car, it costs " << m_Price << " euros and it has " << m_NumberOfDoors << " doors." << endl;
	Vehicle::DisplayWheels();
	Vehicle::DisplayYear();
	cout << endl;
}

Car::~Car()
{
}
