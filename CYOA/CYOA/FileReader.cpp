#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <sstream>

void FileReader::ReadCSV(int number)
{
    std::string paragraphId = std::to_string(number);          // Turns the number into a string
    std::ifstream myStream("../Texts/CYOA - Story.csv");     // Opens the file
    Paragraph newPar;

    if (myStream)
    {
        std::string line;    // Variable to store the text

        while (getline(myStream, line, '\n'))
        {
            if (line.find(paragraphId) == 0) // 1 - Find our paragraph number
            {
                newPar.id = number;
                line.erase(0, paragraphId.size() + 2);  // Removes the paragraph number, the tab and the ' char from the string
                newPar.text += (line + "\n");

                while (getline(myStream, line)) // 2 - parse the paragraph's text
                {
                    if (!FileReader::IsEndParagraph(line)) // new line of current paragraph
                    {
                        newPar.text += (line + "\n");
                    }
                    else  // last line of the paragraph
                    {
                        int startPos = line.find("'\t");
                        ReadOutputs(line, newPar);
                        line.erase(startPos, line.size());  // Removes the ' char and the outputs from the string
                        newPar.text += (line + "\n");
                        break;
                    }
                }
                FileReader::DisplayText(newPar.text);
                break;
            }
        }
    }
    else
    {
        std::cout << "ERROR: Can't open the file" << std::endl;
    }

    FileReader::PlayerInput(newPar);
}

bool FileReader::IsEndParagraph(std::string currentLine)
{
    std::string endPar = "'\t";
    return currentLine.find(endPar) != currentLine.npos;    // Returns if it finds the '\t in the string
}

void FileReader::DisplayText(std::string textToDisplay)
{
    std::cout << textToDisplay << "\n";
}

void FileReader::PlayerInput(Paragraph& currentPar)
{
    int number;

    while (std::cin >> number)
    {
        for (int n : currentPar.outputs)
        {
            if (number == n)
            {
                std::cout << "\n";
                FileReader::ReadCSV(number);
                return;
            }
        }

        std::cout << "\nInvalid number. Enter new number.\n\n";
    }
}

void FileReader::ReadOutputs(std::string outputLine, Paragraph& currentPar)
{
    std::stringstream outputString(outputLine);
    std::string foundOutput;

    while (getline(outputString, foundOutput, '\t'))
    {
        if(isdigit(foundOutput[0]))
            currentPar.outputs.push_back(stoi(foundOutput));
    }
}