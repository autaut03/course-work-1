#include "User.h"

User::User(string login, string password, bool isAdmin) : login(login), password(password), isAdmin(isAdmin) {}

template <>
string Model<User>::getTableName() {
    return "users";
}

template <>
User *Model<User>::createFromRow(vector<string> rowData) {
    return new User(rowData.at(0), rowData.at(1), rowData.at(2) == "1");
}

vector<string> User::toRowData() {
    return { login, password, isAdmin ? "1" : "0" };
}