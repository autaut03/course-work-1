#include <iostream>
#include "SubMenu.h"
#include "BackOption.h"

using namespace std;

void SubMenu::addAdditionalOptions(vector<Option*> &options) {
    options.emplace_back(new BackOption(this));
}