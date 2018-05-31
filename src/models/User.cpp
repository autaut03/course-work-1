#include "User.h"

template <>
string Model<User>::getTableName() {
    return "users";
}

string User::getRoleDisplayName() {
    return get<bool>("isAdmin") ? "Адміністратор" : "Користувач";
}
