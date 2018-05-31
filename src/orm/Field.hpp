#ifndef KURSACH_FIELD_H
#define KURSACH_FIELD_H

#include <string>
#include "../exceptions/UnableToCastModelFieldException.hpp"

class Field {
public:
    Field(std::string const& string) : value_(string) {}
    virtual ~Field() = default;

    template <typename T>
    T get();

    template <typename T>
    void set(T value);

private:
    std::string value_;
};

#endif //KURSACH_FIELD_H

template <typename T>
T Field::get() {
    throw UnableToCastModelFieldException(__PRETTY_FUNCTION__);
}

template <typename T>
void Field::set(T value) {
    throw UnableToCastModelFieldException(__PRETTY_FUNCTION__);
}

template <>
int Field::get<int>() {
    return stoi(value_);
}

template <>
void Field::set<int>(int value) {
    value_ = std::to_string(value);
}

template <>
bool Field::get<bool>() {
    return value_ == "1";
}

template <>
void Field::set<bool>(bool value) {
    value_ = value ? "1" : "0";
}

template <>
std::string Field::get<std::string>() {
    return value_;
}

template <>
void Field::set<std::string>(std::string value) {
    value_ = value;
}

template <>
void Field::set<const char*>(const char* value) {
    value_ = value;
}