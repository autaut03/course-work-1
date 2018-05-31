#ifndef KURSACH_MODEL_H
#define KURSACH_MODEL_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <memory>
#include "../utils/strings.h"
#include "../utils/files.h"
#include "Field.hpp"
#include "../exceptions/ModelFieldNotFoundException.hpp"

using namespace std;

template <typename T>
class Model {
private:
    unordered_map<string, unique_ptr<Field>> fields;

    static string getTableName(); // ABSTRACT
    //static T* createFromRow(vector<string> rowData); // ABSTRACT
    virtual vector<string> toRowData() = 0;

    Field* getField(std::string const& field);
    //string toRow(int idToUse);
    static void putFileStream(fstream& file);
    //static int getIDFromRowData(vector<string> rowData);
    //static vector<string> rowToRowData(string row);
    static int getLastID();

public:
    int id = -1; // -1 значить, що модель НЕ записана в базу

    Model(unordered_map<string, variant<bool, int, string>> const& data); // нету std::variant :(

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

        vector<string> parts = rowToRowData(line);
        // Запишемо айді моделі в змінну і витремо перший елемент вектору для зручності
        int id = getIDFromRowData(parts);
        parts.erase(parts.begin());

        T* model = createFromRow(parts);
        model->id = id;

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

    vector<string> rowData = rowToRowData(lastLine);

    return getIDFromRowData(rowData);
}

template <typename T>
void Model<T>::save() {
    fstream file;
    putFileStream(file);

    if(id == -1) {
        file << toRow(getLastID() + 1) << endl;
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

        vector<string> parts = rowToRowData(line);

        // Якщо це не та строка, яка нам потрібна, ми просто записуємо її в новий файл
        if(getIDFromRowData(parts) != id) {
            newFile << line << endl;
            continue;
        }

        // Якщо та, яку потрібно замінити, тоді замість цього ми виводимо строку з новими даними
        newFile << toRow(id) << endl;

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

/*template <typename T>
string Model<T>::toRow(int idToUse) {
    vector<string> rowData = toRowData();
    rowData.insert(rowData.begin(), to_string(idToUse));

    return implodeString(rowData, "|");
}

template <typename T>
int Model<T>::getIDFromRowData(vector<string> rowData) {
    return stoi(rowData.at(0));;
}

template <typename T>
vector<string> Model<T>::rowToRowData(string row) {
    return explodeString(row, "|");
}*/

template<typename T>
Field *Model<T>::getField(std::string const &field) {
    std::unordered_map<std::string, std::unique_ptr<Field>>::iterator iterator = fields.find(field);

    if (iterator == fields.end()) {
        throw ModelFieldNotFoundException(field);
    }

    return iterator->second.get();
}

template<typename T>
template<typename S>
void Model<T>::set(std::string const &field, S value) {
    getField(field)->set<T>(value);
}

template<typename T>
template<typename S>
S Model<T>::get(std::string const &field) {
    return getField(field)->get<T>();
}
