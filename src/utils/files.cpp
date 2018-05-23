#include <iostream>
#include "files.h"

string getLastLineFromFile(fstream& file) {
    file.seekg(EOF); // go to the end of file

    while(true) {
        char ch;
        file.get(ch);                            // Get current byte's data

        if(file.tellg() <= 1) {             // If the data was at or before the 0th byte
            file.seekg(0);                       // The first line is the last line
            break;
        } else if(ch == '\n') {                   // If the data was a newline
            break;
        }
                                         // If the data was neither a newline nor at the 0 byte
        file.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
    }

    string lastLine;
    getline(file, lastLine);                      // Read the current line
    return lastLine;
}

void openFile(string name, fstream& file) {
    string filename = wrapFilename(name);
    file.open(filename, fstream::in | fstream::out | fstream::app);

    if(!file.is_open()) {
        cout << "Неможливо відкрити/створити файл " << filename << "!" << endl;
        throw exception();
    }
}

string wrapFilename(string name) {
    return "D:/" + name + ".txt";
}
