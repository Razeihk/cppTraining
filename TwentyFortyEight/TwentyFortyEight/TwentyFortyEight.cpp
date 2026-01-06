#include <iostream>
#include <ctime>
#include <random>

#include "TwentyFortyEight.h"

using namespace std;


// TO DO
// CHANGER MES MOVE CHECKS
// RETRAVAILLER AFFICHAGE DE LA GRILLE (4 CHARACTERS DE LONG)

int main()
{
	InitialiseGrid();

	while (isRunning)
	{
		PlayerMove();
	}
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
	
	for (int i = 0; i < 2; i++)
	{
		GenerateNewNumbers();
	}

	DisplayGrid();
}

void DisplayGrid()
{
	cout << endl;

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

	cout << endl;
}

void GenerateNewNumbers()
{
	UpdateEmptySlots();

	//if (EmptySlots.empty()) // Check if there's a slot available
	//{
	//	cout << "You lost you loser" << endl; // Call losing function instead
	//	return;
	//}

	int SelectedSlot = RandomInt(0, (int)EmptySlots.size() - 1);
	
	int tempRow = EmptySlots[SelectedSlot].first;
	int tempColumn = EmptySlots[SelectedSlot].second;

	//cout << tempRow << " and " << tempColumn << endl;

	Grid[tempRow][tempColumn] = 2;

	RandomSeed++;
}

void PlayerMove()
{
	if (!CheckAvailableMove())
	{
		cout << "You lost, you loser!" << endl;
		return;
	}

	char Direction;

	cin >> Direction;

	if (Direction == 'd' && bMoveRightPossible)
	{
		MoveRight();
	}
	else if (Direction == 'a' && bMoveLeftPossible)
	{
		MoveLeft();
	}
	else if (Direction == 'w' && bMoveUpPossible)
	{
		MoveUp();
	}
	else if (Direction == 's' && bMoveDownPossible)
	{
		MoveDown();
	}
	else
	{
		cout << "Choose another move" << endl << endl;
		return;
	}
	
	GenerateNewNumbers();

	DisplayGrid();
}

void MoveRight()
{
	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = TFEConst::c_NumberOfColumns - 2; u >= 0; u--)
		{
			if (Grid[i][u] != 0 && Grid[i][u + 1] == 0)
			{
				Grid[i][u + 1] = Grid[i][u];
				Grid[i][u] = 0;
				u = TFEConst::c_NumberOfColumns - 1;
			}
			else if (Grid[i][u] != 0 && Grid[i][u + 1] == Grid[i][u])
			{
				Grid[i][u + 1] *= 2;
				Grid[i][u] = 0;
			}
		}
	}
}

void MoveLeft()
{
	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 1; u < TFEConst::c_NumberOfColumns; u++)
		{
			if (Grid[i][u] != 0 && Grid[i][u - 1] == 0)
			{
				Grid[i][u - 1] = Grid[i][u];
				Grid[i][u] = 0;
				u = 0;
			}
			else if (Grid[i][u] != 0 && Grid[i][u - 1] == Grid[i][u])
			{
				Grid[i][u - 1] *= 2;
				Grid[i][u] = 0;
			}
		}
	}
}

void MoveDown()
{
	for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
	{
		for (int i = TFEConst::c_NumberOfRows - 2; i >= 0; i--)
		{
			if (Grid[i][u] != 0 && Grid[i + 1][u] == 0)
			{
				Grid[i + 1][u] = Grid[i][u];
				Grid[i][u] = 0;
				i = TFEConst::c_NumberOfRows - 1;
			}
			else if (Grid[i][u] != 0 && Grid[i + 1][u] == Grid[i][u])
			{
				Grid[i + 1][u] *= 2;
				Grid[i][u] = 0;
			}
		}
	}
}

void MoveUp()
{
	for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
	{
		for (int i = 1; i < TFEConst::c_NumberOfRows; i++)
		{
			if (Grid[i][u] != 0 && Grid[i - 1][u] == 0)
			{
				Grid[i - 1][u] = Grid[i][u];
				Grid[i][u] = 0;
				i = 0;
			}
			else if (Grid[i][u] != 0 && Grid[i - 1][u] == Grid[i][u])
			{
				Grid[i - 1][u] *= 2;
				Grid[i][u] = 0;
			}
		}
	}
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
}

bool CheckAvailableMove()
{
	bMoveRightPossible = false;
	bMoveLeftPossible = false;
	bMoveUpPossible = false;
	bMoveDownPossible = false;

	// RIGHT
	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		if (bMoveRightPossible)
		{
			break;
		}

		for (int u = TFEConst::c_NumberOfColumns - 1; u > 0; u--)
		{
			if (Grid[i][u] == 0 || Grid[i][u - 1] == Grid[i][u])
			{
				bMoveRightPossible = true;
				break;
			}
		}
	}

	// LEFT
	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 0; u < TFEConst::c_NumberOfColumns - 2; u++)
		{
			if (Grid[i][u] == 0 || Grid[i][u + 1] == Grid[i][u])
			{
				bMoveLeftPossible = true;
			}
		}
	}

	// DOWN
	for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
	{
		for (int i = TFEConst::c_NumberOfRows - 1; i > 0; i--)
		{
			if (Grid[i][u] == 0 || Grid[i - 1][u] == Grid[i][u])
			{
				bMoveDownPossible = true;
			}
		}
	}

	// UP
	for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
	{
		for (int i = 0; i < TFEConst::c_NumberOfRows - 2; i++)
		{
			if (Grid[i][u] == 0 || Grid[i + 1][u] == Grid[i][u])
			{
				bMoveUpPossible = true;
			}
		}
	}

	cout << "Right Move: " << bMoveRightPossible << endl;
	cout << "Left Move: " << bMoveLeftPossible << endl;
	cout << "Up Move: " << bMoveUpPossible << endl;
	cout << "Down Move: " << bMoveDownPossible << endl;

	cout << endl;

	return (bMoveRightPossible || bMoveLeftPossible || bMoveUpPossible || bMoveDownPossible);
}