#include "MainMenu.h"
#include "../../Instance.h"
#include "auth-options/LogOutOption.h"
#include "../MenuItem.h"
#include "../DummyItem.h"
#include "items-options/ItemsListOption.h"
#include "../../utils/console.h"
#include "../CategorizerItem.h"
#include "auth-options/LoginOption.h"
#include "auth-options/RegisterOption.h"
#include "items-options/AddItemOption.h"

using namespace std;

vector<MenuItem*> MainMenu::getItems() {
    vector<MenuItem*> options;

    options.emplace_back(new CategorizerItem("ТОВАРИ"));
    options.emplace_back(new ItemsListOption);
    if(Instance::getInstance()->isLoggedIn() && Instance::getInstance()->getUser()->get<bool>("isAdmin")) {
        options.emplace_back(new AddItemOption);
    }

    options.emplace_back(new CategorizerItem("АВТОРИЗАЦІЯ"));
    if(! Instance::getInstance()->isLoggedIn()) {
        options.emplace_back(new LoginOption);
        options.emplace_back(new RegisterOption);
    } else {
        options.emplace_back(new LogOutOption);
    }

    return options;
}