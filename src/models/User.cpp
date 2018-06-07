#include "User.h"

template <>
string Model<User>::getTableName() {
    return "users";
}

template <>
vector<string> Model<User>::getRequiredFieldsList() {
    return {
        "login", "password", "isAdmin"
    };
}

string User::getRoleDisplayName() {
    return get<bool>("isAdmin") ? "Адміністратор" : "Користувач";
}
