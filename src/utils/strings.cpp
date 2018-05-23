#include <string>
#include <vector>
#include <numeric>
#include "strings.h"

using namespace std;

vector<string> explodeString(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

string implodeString(vector<string> arr, const string& delim) {
    if(arr.empty()) {
        return "";
    }

    if(arr.size() == 1) {
        return arr[0];
    }

    string result = arr[0];
    for(auto it = arr.begin() + 1; it != arr.end(); ++it) {
        result += delim + *it;
    }

    return result;
}
