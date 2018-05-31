#ifndef KURSACH_CUSTOMEXCEPTIONBASE_H
#define KURSACH_CUSTOMEXCEPTIONBASE_H

#include <exception>
#include <string>

class CustomExceptionBase : public std::exception {
public:
    CustomExceptionBase(std::string msg) : msg_(msg) {}

    std::string str() const noexcept {
        return msg_;
    }

private:
    std::string msg_;
};

#endif //KURSACH_CUSTOMEXCEPTIONBASE_H
