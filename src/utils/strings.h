#ifndef KURSACH_STRINGS_H
#define KURSACH_STRINGS_H

#include <string>
#include <vector>

using namespace std;

vector<string> explodeString(const string& str, const string& delim);
string implodeString(vector<string> arr, const string& delim);

#endif //KURSACH_STRINGS_H
