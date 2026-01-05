// TwentyFortyEight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TwentyFortyEight.h"

using namespace std;

namespace twentyFortyEightConst
{
	constexpr int c_numberOfRows = 4;
	constexpr int c_numberOfColumns = 4;
}


int main()
{
	twentyFortyEight();
}

void twentyFortyEight()
{
	int grid[twentyFortyEightConst::c_numberOfRows][twentyFortyEightConst::c_numberOfColumns];

	for (size_t i = 0; i < twentyFortyEightConst::c_numberOfColumns; i++)
	{
		for (size_t u = 0; u < twentyFortyEightConst::c_numberOfRows; u++)
		{
			grid[i][u] = 0;

			if (u < twentyFortyEightConst::c_numberOfRows - 1)
			{
				cout << grid[i][u] << " | ";
			}
			else
			{
				cout << grid[i][u] << endl;
			}
		}
	}

	//grid[rand()][rand()] = 2;
}