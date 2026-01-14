#include "Main.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "The budget of the garage is " << MyGarage.GetBudget() << " euros." << endl << endl;
	MyGarage.BuyVehicle(new Car(1500, 2005, 3));
	MyGarage.BuyVehicle(new Truck(10000, 2020, 1000));
	MyGarage.BuyVehicle(new Bike(5000, 2022, 200));

	cout << endl;

	for (Vehicle* v : MyGarage.GetStoredVehicles())
	{
		v->DisplayVehicle();
	}

	MyGarage.SellVehicle(MyGarage.GetStoredVehicles()[1]);

	cout << endl;

	for (Vehicle* v : MyGarage.GetStoredVehicles())
	{
		v->DisplayVehicle();
	}
}
