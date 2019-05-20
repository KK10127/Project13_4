/*
 * CHAPTER 13, PROJECT 4
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 *
 * PROBLEM STATEMENT: Write a program that asks the user for the name of a text file. The program
 *  The program should display the last 10 lines of the file on the screen (the "tail" of the file). If the file has
 *  less than 10 lines, the entire file is displayed, with a message that the entire file has been displayed.
 *  with a message that the entire file has been displayed. The program should do this by seeking to the end of the file
 *  and then backing up to the tenth line from the end.
 *
 */
#include <iostream>
#include <fstream>
using namespace std;
int main() {

    // create string to hold the file name
    string fileName, line;
    int numLines = 0;

    // PROMPT the user for the name of the text file
    cout << "Welcome to the demo of project 4!" << endl;
    cout << "Please enter the name of an existing text file: ";

    // user input
    cin >> fileName;

    // create infile stream objes
    ifstream file;

    // open the file
    file.open(fileName, ios::in);

    if (!file) {
        cout << "Error opening file!";
        return 0;
    }


    // read to the end of the file to determine how many lines are in the file
    while (getline(file, line))
        numLines++;

    if (numLines < 10) {
        // tell the user the file is less than 10 lines
        cout << "\t\n\tThis file is less than 10 lines!" << endl << endl;

        // print all the file contents
        // seek to beginning
        file.clear();
        file.seekg(0, ios::beg);

        // print each line
        while (!file.eof()) {
            getline(file, line);
            cout << "\t\t" << line << endl;
        }

        // done
        return 0;
    }

    // seek to the 10th to last line of the file
    // eg. seek to line (numLines - 10)
    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; i <= (numLines - 10); i++)
        getline(file, line);

    cout << "\t\t" << line << endl;
    while (!file.eof()) {
        getline(file, line);
        cout << "\t\t" << line << endl;
    }

    file.close();
    return 0;
}