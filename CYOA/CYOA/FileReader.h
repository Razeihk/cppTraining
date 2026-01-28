#pragma once

#include <string>
#include <vector>

struct Paragraph
{
	int id = -1;
	std::string text = "";
	std::vector<int> outputs;
};

class FileReader
{
public:
	static void ReadCSV(int number);

	static bool IsEndParagraph(std::string currentLine);	// Probably needs to be moved in another class
	static void DisplayText(std::string textToDisplay);		// Probably needs to be moved in another class
	static void PlayerInput(Paragraph& currentPar);			// Probably needs to be moved in another class

	static void ReadOutputs(std::string outputLine, Paragraph& currentPar);

private:

};