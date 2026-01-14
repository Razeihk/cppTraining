#include "Garage.h"
#include <iostream>

using namespace std;

Garage::Garage()
{
}

Garage::Garage(std::vector<Vehicle*> StoredVehicles)
	:m_StoredVehicles(StoredVehicles)
{
}

int Garage::GetBudget() const
{
	return m_Budget;
}

void Garage::BuyVehicle(Vehicle* VehicleToBuy)
{
	if (m_Budget >= VehicleToBuy->GetPrice())
	{
		m_StoredVehicles.push_back(VehicleToBuy);
		m_Budget -= VehicleToBuy->GetPrice();
		cout << "A " << VehicleToBuy->GetType() << " has been bought. The budget is now " << m_Budget << " euros." << endl;
	}
}

void Garage::SellVehicle(Vehicle* VehicleToSell)
{
	m_Budget += VehicleToSell->GetPrice();
	cout << "A " << VehicleToSell->GetType() << " has been sold. The budget is now of " << m_Budget << " euros." << endl;
	m_StoredVehicles.erase(remove(m_StoredVehicles.begin(), m_StoredVehicles.end(), VehicleToSell), m_StoredVehicles.end());
	delete VehicleToSell;
}

std::vector<Vehicle*> Garage::GetStoredVehicles() const
{
	return m_StoredVehicles;
}

Garage::~Garage()
{
	for (Vehicle* v : m_StoredVehicles)
	{
		delete v;
		v = nullptr;
	}
}

