#include "Vehicle.h"
#include <iostream>
#include <string>

using namespace std;

int Vehicle::VehiclesCount = 0;

Vehicle::Vehicle()
{
	++VehiclesCount;	// Each time an object is created, increases the count
}

Vehicle::Vehicle(int Price, int Year)
	:m_Price(Price), m_Year(Year)
{
	++VehiclesCount;
}

void Vehicle::DisplayVehicle() const
{
	cout << "This is a vehicle and it costs " << m_Price << " euros." << endl;
}

void Vehicle::DisplayYear() const
{
	cout << "It has been produced in " << m_Year << "." << endl;
}

void Vehicle::DisplayWheels() const
{
	cout << "It has " << m_NumberOfWheels << " wheels." << endl;
}

int Vehicle::GetNumberOfWheels() const
{
	return m_NumberOfWheels;
}

int Vehicle::GetPrice() const
{
	return m_Price;
}

string Vehicle::GetType() const
{
	return m_Type;
}

int Vehicle::NumberOfVehicles()
{
	return VehiclesCount;
}

Vehicle::~Vehicle()
{
	--VehiclesCount; // Each time an object is created, decreases the count
}
