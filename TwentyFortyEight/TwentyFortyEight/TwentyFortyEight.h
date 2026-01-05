#pragma once
#include <vector>

namespace TFEConst
{
	constexpr int c_NumberOfColumns = 4;
	constexpr int c_NumberOfRows = 4;
}


//FUNCTIONS

void InitialiseGrid();
void DisplayGrid();
void GenerateNewNumbers();
void UpdateEmptySlots();
int RandomInt(int Min, int Max);


// VARIABLES

int Grid[TFEConst::c_NumberOfColumns][TFEConst::c_NumberOfRows];
int RandomSeed = 0;
std::vector<std::pair<int, int>> EmptySlots; // std::pair contains 2 objects tbd (first and second)
