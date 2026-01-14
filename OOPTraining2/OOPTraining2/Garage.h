#pragma once

#include <vector>
#include "Vehicle.h"

class Garage
{
public:
	Garage();
	Garage(std::vector<Vehicle*> StoredVehicles);

	int GetBudget() const;

	void BuyVehicle(Vehicle* VehicleToBuy);
	void SellVehicle(Vehicle* VehicleToSell);

	std::vector<Vehicle*> GetStoredVehicles() const;

	~Garage();

private:
	int m_Budget = 50000;
	std::vector<Vehicle*> m_StoredVehicles;
};


