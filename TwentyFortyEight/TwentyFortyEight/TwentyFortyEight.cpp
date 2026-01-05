#include <iostream>
#include <ctime>
#include <random>

#include "TwentyFortyEight.h"

using namespace std;


int main()
{
	InitialiseGrid();
}

void InitialiseGrid()
{
	RandomSeed = (int)time(0);	// (int) asks to cast the variable as an int before returning it
								// This initialises the randomSeed with a different number each time the app starts

	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
		{
			Grid[i][u] = 0;
		}
	}
	
	for (int i = 0; i < 20; i++)
	{
		GenerateNewNumbers();
	}

	DisplayGrid();
}

void DisplayGrid()
{
	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
		{

			if (u < TFEConst::c_NumberOfColumns - 1)
			{
				cout << Grid[i][u] << " | ";
			}
			else
			{
				cout << Grid[i][u] << endl;
			}
		}
	}
}

void GenerateNewNumbers()
{
	UpdateEmptySlots();

	if (EmptySlots.empty()) // Check if there's a slot available
	{
		cout << "You lost you loser" << endl; // Call losing function instead
		return;
	}

	int SelectedSlot = RandomInt(0, (int)EmptySlots.size() - 1);
	
	int tempRow = EmptySlots[SelectedSlot].first;
	int tempColumn = EmptySlots[SelectedSlot].second;

	cout << tempRow << " and " << tempColumn << endl;

	Grid[tempRow][tempColumn] = 2;

	RandomSeed++;
}

void MoveNumbers()
{
	// g peur
}

int RandomInt(int Min, int Max)
{
	// Complicated function from Zazar, no idea how it works (he doesn't know either)
	static random_device RandomDevice;
	static mt19937 Eng(RandomDevice());
	uniform_int_distribution<int> Distribution(Min, Max);


	return Distribution(Eng);
}

void UpdateEmptySlots()
{
	EmptySlots.clear(); // Reset the vector of empty slots

	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
		{
			if (Grid[i][u] == 0)
			{
				EmptySlots.push_back(pair<int, int>(i, u));
			}
		}
	}

	// Display available slots
	/*for (size_t i = 0; i < (int)EmptySlots.size(); i++)
	{
		cout << EmptySlots[i].first << "," << EmptySlots[i].second << endl;
	}*/
}