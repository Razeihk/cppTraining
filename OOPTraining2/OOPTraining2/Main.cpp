#include "Main.h"
#include <iostream>

using namespace std;


int main()
{
	OOPPart2Exercise();
}

void GarageExercise()
{
	
	cout << "The budget of the garage is " << MyGarage.GetBudget() << " euros." << endl << endl;
	MyGarage.BuyVehicle(new Car(1500, 2005, 3));
	MyGarage.BuyVehicle(new Truck(10000, 2020, 1000));
	MyGarage.BuyVehicle(new Bike(5000, 2022, 200));

	cout << endl;

	cout << "Number of vehicles: " << Vehicle::NumberOfVehicles() << endl << endl;	// Static function can be called without an object

	for (Vehicle* v : MyGarage.GetStoredVehicles())
	{
		v->DisplayVehicle();
	}

	MyGarage.SellVehicle(MyGarage.GetStoredVehicles()[1]);

	cout << endl;

	cout << "Number of vehicles: " << Vehicle::NumberOfVehicles() << endl << endl;

	for (Vehicle* v : MyGarage.GetStoredVehicles())
	{
		v->DisplayVehicle();
	}
}

void OOPPart2Exercise()
{
	Fraction a(4, 5);		//Déclare une fraction valant 4/5
	Fraction b(2);			//Déclare une fraction valant 2/1 (ce qui vaut 2)
	Fraction c;				//Déclare une fractions valant 0

	//c = a * b;			//Calcule 4/5 * 2/1 = 8/5

	//cout << a << " * " << b << " = " << c << endl;

	//if (a == b)
	//	cout << "a est egal a b." << endl;
	//else
	//	cout << "a n’est pas egal a b." << endl;

	//return 0;
}