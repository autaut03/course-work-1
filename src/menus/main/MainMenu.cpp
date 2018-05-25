#include "MainMenu.h"
#include "../login/AuthMenu.h"
#include "AuthMenuOption.h"
#include "../../Instance.h"

using namespace std;

vector<Option*> MainMenu::getOptions() {
    vector<Option*> options;

    if(! Instance::getInstance()->isLoggedIn()) {
        options.emplace_back(new AuthMenuOption);
    }

    return options;
}