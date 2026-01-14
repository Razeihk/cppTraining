#pragma once
#include "Vehicle.h"
class Bike :
    public Vehicle
{
public:
    Bike();
    Bike(int Price, int Year, int Speed);

    virtual void DisplayVehicle() const;

    virtual ~Bike();

private:
    int m_MaxSpeed = 0;
};

