#pragma once
#include "Vehicle.h"
class Car :
    public Vehicle
{
public:
    Car();
    Car(int Price, int Year, int NumberOfDoors);

    virtual void DisplayVehicle() const;

    virtual ~Car();

private:
    int m_NumberOfDoors = 0;

};

