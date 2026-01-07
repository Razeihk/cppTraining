#include <iostream>
#include <random>

#include "TwentyFortyEight.h"

using namespace std;


int main()
{
	InitialiseGrid();

	while (bIsRunning)
	{
		PlayerMove();
	}
}

void InitialiseGrid()
{
	//RandomSeed = (int)time(0);	// (int) asks to cast the variable as an int before returning it
									// This initialises the randomSeed with a different number each time the app starts

	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
		{
			Grid[i][u] = 0;
		}
	}

	// DEBUG TO WIN
	/*for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int u = 0; u < TFEConst::c_NumberOfColumns; u++)
		{
			if ((i == 1 && u == 1) || (i == 1 && u == 2) || (i == 2 && u == 1))
			{
				Grid[i][u] = 1024;
			}
			else
			{
				Grid[i][u] = 0;
			}
			
		}
	}*/

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
			if (u == 0)
			{
				cout << "|";
			}

			if (Grid[i][u] > 999) // If more than 3 characters
			{
				cout << Grid[i][u] << "|";
			}
			else if (Grid[i][u] > 99) // If more than 2 characters
			{
				cout << Grid[i][u] << " |";
			}
			else if (Grid[i][u] > 9) // If more than 1 character
			{
				cout << Grid[i][u] << "  |";
			}
			else
			{
				cout << Grid[i][u] << "   |"; // If only one character
			}

			if (u == TFEConst::c_NumberOfColumns - 1) // Go to next line if reached the end of the grid
			{
				cout << endl;
			}
		}
	}

	cout << endl;
}

void GenerateNewNumbers()
{
	UpdateEmptySlots(); // Get a list of all the empty slots

	int SelectedSlot = RandomInt(0, (int)EmptySlots.size() - 1); // Pick a random index in the list of empty slots
	
	int tempRow = EmptySlots[SelectedSlot].first; // Get the first number at the index of the list of empty slots
	int tempColumn = EmptySlots[SelectedSlot].second; // Get the second number at the index of the list of empty slots

	Grid[tempRow][tempColumn] = 2;
}

void PlayerMove()
{
	if (!CheckAvailableMove())
	{
		cout << "You lost, you loser!" << endl;
		bIsRunning = false;
		return;
	}

	char Direction;

	cin >> Direction;

	int MergedNumber = 0;

	if (Direction == 'd' && bMoveRightPossible)
	{
		MergedNumber = MoveRight();
	}
	else if (Direction == 'a' && bMoveLeftPossible)
	{
		MergedNumber = MoveLeft();
	}
	else if (Direction == 'w' && bMoveUpPossible)
	{
		MergedNumber = MoveUp();
	}
	else if (Direction == 's' && bMoveDownPossible)
	{
		MergedNumber = MoveDown();
	}
	else
	{
		cout << "Choose another move" << endl << endl;
		return;
	}
	
	GenerateNewNumbers();

	CheckVictory(MergedNumber);

	if (bIsRunning) // Makes sure the grid isn't displayed twice when losing or winning
	{
		DisplayGrid();
	}
	
}

int MoveRight()
{
	int MergedNumber = 0;

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
				MergedNumber = Grid[i][u + 1] * 2;
				Grid[i][u + 1] = MergedNumber;
				Grid[i][u] = 0;
			}
		}
	}

	return MergedNumber;
}

int MoveLeft()
{
	int MergedNumber = 0;

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
				MergedNumber = Grid[i][u - 1] * 2;
				Grid[i][u - 1] = MergedNumber;
				Grid[i][u] = 0;
			}
		}
	}
	
	return MergedNumber;
}

int MoveDown()
{
	int MergedNumber = 0;

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
				MergedNumber = Grid[i][u + 1] * 2;
				Grid[i + 1][u] = MergedNumber;
				Grid[i][u] = 0;
			}
		}
	}

	return MergedNumber;
}

int MoveUp()
{
	int MergedNumber = 0;

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
				MergedNumber = Grid[i - 1][u] * 2;
				Grid[i - 1][u] = MergedNumber;
				Grid[i][u] = 0;
			}
		}
	}

	return MergedNumber;
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


	for (int i = 0; i < TFEConst::c_NumberOfRows; i++)
	{
		for (int j = 0; j < TFEConst::c_NumberOfColumns; j++)
		{
			if (bMoveRightPossible && bMoveLeftPossible && bMoveUpPossible && bMoveDownPossible)
				return true;

			if (Grid[i][j] != 0)
			{
				// RIGHT
				if (j != TFEConst::c_NumberOfColumns - 1 && (Grid[i][j + 1] == 0 || Grid[i][j + 1] == Grid[i][j]))
				{
					bMoveRightPossible = true;
				}

				// LEFT
				if (j != 0 && (Grid[i][j - 1] == 0 || Grid[i][j - 1] == Grid[i][j]))
				{
					bMoveLeftPossible = true;
				}

				//UP
				if (i != 0 && (Grid[i - 1][j] == 0 || Grid[i - 1][j] == Grid[i][j]))
				{
					bMoveUpPossible = true;
				}

				//DOWN
				if (i != TFEConst::c_NumberOfRows - 1 && (Grid[i + 1][j] == 0 || Grid[i + 1][j] == Grid[i][j]))
				{
					bMoveDownPossible = true;
				}
			}
			
		}
	}

	/*cout << "Right Move: " << bMoveRightPossible << endl;
	cout << "Left Move: " << bMoveLeftPossible << endl;
	cout << "Up Move: " << bMoveUpPossible << endl;
	cout << "Down Move: " << bMoveDownPossible << endl;

	cout << endl;*/

	return (bMoveRightPossible || bMoveLeftPossible || bMoveUpPossible || bMoveDownPossible);
}

bool CheckVictory(int& MergedNumber)
{
	if (MergedNumber == 2048)
	{
		DisplayGrid();
		cout << "You reached 2048, congrats!" << endl;
		bIsRunning = false;
	}

	return !bIsRunning;
}