#pragma once
#include "Vehicle.h"
#include <string>
class Truck :
    public Vehicle
{
public:
    Truck();
    Truck(int Price, int Year, int MaxWeight);

    void DisplayVehicle() const;

private:
    int m_MaxWeight = 0;
};