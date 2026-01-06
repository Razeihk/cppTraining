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
void PlayerMove();
void MoveRight();
void MoveLeft();
void MoveUp();
void MoveDown();
void UpdateEmptySlots();
int RandomInt(int Min, int Max);
bool CheckAvailableMove();


// VARIABLES

int Grid[TFEConst::c_NumberOfColumns][TFEConst::c_NumberOfRows];
int RandomSeed = 0;
std::vector<std::pair<int, int>> EmptySlots; // std::pair contains 2 objects tbd (first and second)

bool bMoveRightPossible;
bool bMoveLeftPossible;
bool bMoveUpPossible;
bool bMoveDownPossible;

bool isRunning = true;
