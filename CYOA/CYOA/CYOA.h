#pragma once

struct Paragraph
{
	int id = -1;
	std::string text = "";
};


void ReadStreamOneFile(int Number);
void ReadStream(int Number);
void ReadStreamCSV(int number);

bool IsEndParagraph(std::string line);
void DisplayText(std::string textToDisplay);
void AskNumber();