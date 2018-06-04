#ifndef KURSACH_FIELD_H
#define KURSACH_FIELD_H

#include <string>
#include "../exceptions/UnableToCastModelFieldException.hpp"

class Field {
public:
    Field() {}
    Field(std::string const& string) : value_(string) {}
    virtual ~Field() = default;

    template <typename T>
    T get();

    template <typename T>
    void set(T value);

private:
    std::string value_;
};

template <>
inline int Field::get<int>() {
    return stoi(value_);
}

template <>
inline void Field::set<int>(int value) {
    value_ = std::to_string(value);
}

template <>
inline bool Field::get<bool>() {
    return value_ == "1";
}

template <>
inline void Field::set<bool>(bool value) {
    value_ = value ? "1" : "0";
}

template <>
inline std::string Field::get<std::string>() {
    return value_;
}

template <>
inline void Field::set<std::string>(std::string value) {
    value_ = value;
}

template <>
inline void Field::set<const char*>(const char* value) {
    value_ = value;
}

#endif //KURSACH_FIELD_H