#ifndef KURSACH_FILES_H
#define KURSACH_FILES_H

#include <string>
#include <fstream>

using namespace std;

void openFile(string name, fstream& file);
string wrapFilename(string name);
string getLastLineFromFile(fstream& file);

#endif //KURSACH_FILES_H
