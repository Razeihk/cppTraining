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
int MoveRight();
int MoveLeft();
int MoveUp();
int MoveDown();
void UpdateEmptySlots();
int RandomInt(int Min, int Max);
bool CheckAvailableMove();
bool CheckVictory(int& newScore);


// VARIABLES

int Grid[TFEConst::c_NumberOfColumns][TFEConst::c_NumberOfRows];
std::vector<std::pair<int, int>> EmptySlots; // std::pair contains 2 objects tbd (first and second)

bool bMoveRightPossible;
bool bMoveLeftPossible;
bool bMoveUpPossible;
bool bMoveDownPossible;

bool bIsRunning = true;
