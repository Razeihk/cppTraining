#include <iostream>
#include <fstream> // Library allowing to communicate between files (fstream = file stream)
#include <string>
#include <filesystem>

#include "CYOA.h"

using namespace std;

int main()
{
    cout << filesystem::current_path() << endl;
    ReadStream(0);
}

void ReadStreamOneFile(int Number)
{
    string Paragraph = to_string(Number);
    ifstream MyStream("C:/Users/cesar/Documents/GitHub/cppTraining/CYOA/Texts/Test.txt");   // Warning: do not forget to use / or \\

    if (MyStream)
    {
        string Line;

        while (getline(MyStream, Line))
        {
            cout << Line << endl;
        }
    }
    else
    {
        cout << "ERROR: Can't open the file" << endl;
    }
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

    ReadStream(Number);
}