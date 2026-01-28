#include <iostream>
#include <fstream> // Library allowing to communicate between files (fstream = file stream)
#include <string>
#include <filesystem>

#include "CYOA.h"
#include "FileReader.h"


int main()
{
    FileReader::ReadCSV(0);
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

    //AskNumber();
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

    //AskNumber();
}

