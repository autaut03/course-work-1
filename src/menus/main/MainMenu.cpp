#include "MainMenu.h"
#include "../login/AuthMenu.h"
#include "AuthMenuOption.h"

using namespace std;

vector<Option*> MainMenu::getOptions() {
    return {
            new AuthMenuOption
    };
}