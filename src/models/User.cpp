#include "User.h"

template <>
string Model<User>::getTableName() {
    return "users";
}

string User::getRoleDisplayName() {
    return get<bool>("isAdmin") ? "Адміністратор" : "Користувач";
}

User::User(const unordered_map<string, string> &data) : Model(data) {}
