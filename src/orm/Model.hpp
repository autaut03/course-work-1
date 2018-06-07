#ifndef KURSACH_MODEL_H
#define KURSACH_MODEL_H

#define ROW_FIELDS_SEPARATOR "\uE01F"
#define ROW_FIELD_NAME_VALUE_SEPARATOR "\uE01E"

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <memory>
//#include <w32api/synchapi.h>
#include "../utils/strings.h"
#include "../utils/files.h"
#include "Field.hpp"
#include "../exceptions/ModelFieldNotFoundException.hpp"

using namespace std;

template <typename T>
class Model {
private:
    static string getTableName(); // ABSTRACT
    static vector<string> getRequiredFieldsList(); // ABSTRACT

    Field* getField(std::string const& field);
    string toRow();
    static void putFileStream(fstream& file);
    static unordered_map<string, Field> rowToFields(string row);
    static int getLastID();

public:

    unordered_map<string, Field> fields;

    int id = -1; // -1 значить, що модель НЕ записана в базу

    Model(unordered_map<string, string> const& data);
    Model(unordered_map<string, Field> data);
    Model();

    static vector<T*> all();
    void save();

    template <typename S>
    void set(std::string const& field, S value);

    template <typename S>
    S get(std::string const& field);
};


#endif //KURSACH_MODEL_H

template <typename T>
vector<T*> Model<T>::all() {
    fstream file;
    putFileStream(file);

    vector<T*> result;

    string line;
    while(getline(file, line)) {
        if(line.length() == 0)
            continue;

        //T* model = new T(rowToFields(line));
        auto model = new T(rowToFields(line));
        //auto model = new T();
        //model->fields = rowToFields(line);
        result.emplace_back(model);
    }

    file.close();

    return result;
}

template <typename T>
int Model<T>::getLastID() {
    fstream file;
    putFileStream(file);
    string lastLine = getLastLineFromFile(file);
    file.close();

    if(lastLine.length() == 0) {
        return -1;
    }

    return rowToFields(lastLine).at("id").get<int>();
}

template <typename T>
void Model<T>::save() {
    fstream file;
    putFileStream(file);

    if(id == -1) {
        id = getLastID() + 1;
        file << toRow() << endl;
        file.close();
        return;
    }

    string newFilename = getTableName() + "_new";
    fstream newFile;
    openFile(newFilename, newFile);

    string line;
    while(getline(file, line)) {
        if(line.length() == 0)
            continue;

        unordered_map<string, Field> fields = rowToFields(line);

        // Якщо це не та строка, яка нам потрібна, ми просто записуємо її в новий файл
        if(fields.at("id").get<int>() != id) {
            newFile << line << endl;
            continue;
        }

        // Якщо та, яку потрібно замінити, тоді замість цього ми виводимо строку з новими даними
        newFile << toRow() << endl;

        break;
    }

    file.close();
    newFile.close();

    const char *oldFilename = wrapFilename(getTableName()).c_str();

    remove(oldFilename);
    rename(wrapFilename(newFilename).c_str(), oldFilename);
}

template<typename T>
void Model<T>::putFileStream(fstream &file) {
    openFile(getTableName(), file);
}

template <typename T>
string Model<T>::toRow() {
    vector<string> keyValuePairs;

    for(auto pair : fields) {
        keyValuePairs.emplace_back(pair.first + ROW_FIELD_NAME_VALUE_SEPARATOR + pair.second.get<string>());
    }

    return implodeString(keyValuePairs, ROW_FIELDS_SEPARATOR);
}

template <typename T>
unordered_map<string, Field> Model<T>::rowToFields(string row) {
    unordered_map<string, Field> result;

    for(auto keyValue : explodeString(row, ROW_FIELDS_SEPARATOR)) {
        vector<string> keyValueVector = explodeString(keyValue, ROW_FIELD_NAME_VALUE_SEPARATOR);

        result[keyValueVector[0]] = Field(keyValueVector[1]);
    }

    return result;
}

template<typename T>
template<typename S>
void Model<T>::set(std::string const &field, S value) {
    /*if(fields.count(field) == 0) {
        fields.emplace(field, Field>());
    }*/

    return fields[field].set<S>(value);
}

template<typename T>
template<typename S>
S Model<T>::get(std::string const &field) {
    auto iterator = fields.find(field);

    if(iterator == fields.end()) {
        throw ModelFieldNotFoundException(field);
    }

    return iterator->second.get<S>();
}

template<typename T>
Model<T>::Model(unordered_map<string, string> const &data) {
    for(auto const& pair : data) {
        set<string>(pair.first, pair.second);
    }
}

template<typename T>
Model<T>::Model(unordered_map<string, Field> data) {
    fields = data;
}

template<typename T>
Model<T>::Model() {}
