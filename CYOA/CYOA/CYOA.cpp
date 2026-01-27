#include <iostream>
#include <fstream> // Library allowing to communicate between files (fstream = file stream)
#include <string>
#include <filesystem>

#include "CYOA.h"


int main()
{
    ReadStreamCSV(87);
    return EXIT_SUCCESS;
}

void ReadStreamOneFile(int Number)
{
    std::string Paragraph = std::to_string(Number);   // Turns the number into a string
    std::ifstream MyStream("../Texts/Test.xml");   // Opens the file

    if (MyStream)
    {
        MyStream.seekg(0, std::ios::beg);    // Positions the cursor at the beginning of the file
        int CursorPosition = MyStream.tellg();  // Save the current position of the cursor
        bool keepReading = true;    // Used to know when to stop reading the file
        std::string Line;    // Variable to store the text

        while (keepReading)
        {
            getline(MyStream, Line);    // Reads the first line of the file
            
            if (Line == "<Paragraph=" + Paragraph + ">")
            {
                while (getline(MyStream, Line))
                {
                    if (Line == "<\\Paragraph>")
                    {
                        keepReading = false;
                        break;
                    }
                    Line.erase(remove(Line.begin(), Line.end(), '\t'), Line.end());
                    std::cout << Line << std::endl;
                }
            }
        }
    }
    else
    {
        std::cout << "ERROR: Can't open the file" << std::endl;
    }

    AskNumber();
}

// Reads a file based on the paragraph number requested by the player
void ReadStream(int Number)
{
    std::string Paragraph = std::to_string(Number);   // Turns the number into a string
    std::string Path = "../Texts/" + Paragraph + ".txt"; // Gets the path of the requested file
    std::ifstream MyStream(Path);    // Opens the file

    if (MyStream)
    {
        std::string Line;

        while (getline(MyStream,Line))  // Reads the whole file stored in MyStream and stores each line in Line
        {
            std::cout << Line << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Can't open the file" << std::endl;
    }

    AskNumber();
}

void ReadStreamCSV(int number)
{
    std::string paragraphId = std::to_string(number);          // Turns the number into a string
    std::ifstream myStream("../Texts/CYOA - Story.csv");     // Opens the file

    if (myStream)
    {
        std::string line;    // Variable to store the text
        //getline(MyStream, Line, '\n');
        //MyStream.seekg(Line.size(), std::ios::beg); // Positions the cursor at the beginning of the file
        //int CursorPosition = MyStream.tellg();      // Save the current position of the cursor
        bool keepReading = true;                    // Used to know when to stop reading the file

        Paragraph newPar;

        while (getline(myStream, line, '\n'))
        {
            if (line.find(paragraphId) == 0) // 1 - Find our paragraph number
            {
                newPar.id = number;
                line.erase(0, paragraphId.size() + 2);
                newPar.text += (line + "\n");

                while (getline(myStream, line)) // 2 - parse the paragraph's text
                {
                    if (!IsEndParagraph(line)) // new line of current paragraph
                    {
                        newPar.text += (line + "\n");
                    }
                    else  // new paragraph, stop reading
                    {
                        int startPos = line.find("'\t");
                        line.erase(startPos, line.size());
                        newPar.text += (line + "\n");
                        break;
                    }
                }
                DisplayText(newPar.text);
                break;
            }
        }
    }
    else
    {
        std::cout << "ERROR: Can't open the file" << std::endl;
    }

    AskNumber();
}

void AskNumber()
{
    int number;

    std::cin >> number;
    std::cout << "\n";
    ReadStreamCSV(number);
}

void DisplayText(std::string textToDisplay)
{
    std::cout << textToDisplay << "\n";
}

bool IsEndParagraph(std::string currentLine)
{
    std::string endPar = "'\t";
    return currentLine.find(endPar) != currentLine.npos;
}
