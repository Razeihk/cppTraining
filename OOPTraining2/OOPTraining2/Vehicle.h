#pragma once

#include <vector>
#include <string>

class Vehicle
{
public:
	Vehicle();
	Vehicle(int Price, int Year);

	virtual void DisplayVehicle() const;
	virtual void DisplayYear() const;
	virtual void DisplayWheels() const;

	int GetNumberOfWheels() const;
	// virtual int GetWheels() const = 0;	// This is a pure virtual method
											// It turns the class into an Abstract Class
											// Abstract Classes can't be created as they have a method that cannot be called
											// Any class inheriting from an Abstract Class must have its own version of the pure virtual method
											// otherwise it becomes an abstract class as well
	int GetPrice() const;
	std::string GetType() const;

	virtual ~Vehicle();

protected:
	int m_Price = 0; 
	int m_NumberOfWheels = 0;
	int m_Year = 0;
	std::string m_Type = "";
};

