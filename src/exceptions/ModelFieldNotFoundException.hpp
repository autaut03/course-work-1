#ifndef KURSACH_MODELFIELDNOTFOUNDEXCEPTION_H
#define KURSACH_MODELFIELDNOTFOUNDEXCEPTION_H

#include "CustomExceptionBase.hpp"

class ModelFieldNotFoundException : public CustomExceptionBase {
public:
    ModelFieldNotFoundException(std::string fieldName) : CustomExceptionBase("Model field '" + fieldName + "' wasn't found.") {}
};

#endif //KURSACH_MODELFIELDNOTFOUNDEXCEPTION_H
