#include <iostream>
#include <fstream> // Library allowing to communicate between files (fstream = file stream)
#include <string>
#include <filesystem>

#include "CYOA.h"

using namespace std;

int main()
{
    ReadStreamOneFile(0);
}

void ReadStreamOneFile(int Number)
{
    string Paragraph = to_string(Number);   // Turns the number into a string
    ifstream MyStream("../Texts/Test.xml");   // Opens the file

    if (MyStream)
    {
        MyStream.seekg(0, ios::beg);    // Positions the cursor at the beginning of the file
        int CursorPosition = MyStream.tellg();  // Save the current position of the cursor
        bool keepReading = true;    // Used to know when to stop reading the file
        string Line;    // Variable to store the text

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
                    cout << Line << endl;
                }
            }
        }
    }
    else
    {
        cout << "ERROR: Can't open the file" << endl;
    }

    AskNumber();
}

// Reads a file based on the paragraph number requested by the player
void ReadStream(int Number)
{
    string Paragraph = to_string(Number);   // Turns the number into a string
    string Path = "../Texts/" + Paragraph + ".txt"; // Gets the path of the requested file
    ifstream MyStream(Path);    // Opens the file

    if (MyStream)
    {
        string Line;

        while (getline(MyStream,Line))  // Reads the whole file stored in MyStream and stores each line in Line
        {
            cout << Line << endl;
        }
    }
    else
    {
        cout << "ERROR: Can't open the file" << endl;
    }

    AskNumber();
}

void AskNumber()
{
    int Number;

    cin >> Number;

    ReadStreamOneFile(Number);
}