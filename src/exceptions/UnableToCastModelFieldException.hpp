#ifndef KURSACH_UNABLETOCASTMODELFIELDEXCEPTION_H
#define KURSACH_UNABLETOCASTMODELFIELDEXCEPTION_H

#include "CustomExceptionBase.hpp"

class UnableToCastModelFieldException : public CustomExceptionBase {
public:
    UnableToCastModelFieldException(std::string funcSig) : CustomExceptionBase("Unable to cast model field: " + funcSig) {}
};

#endif //KURSACH_UNABLETOCASTMODELFIELDEXCEPTION_H
