#ifndef CVARVAL_HPP
#define CVARVAL_HPP
#include "../../interfaces/iValue.hpp"
#include "../../interfaces/iIdentifier.hpp"
#include <string>

class VariableValue: public Value {
    public:
        Identifier* ident;
        VariableValue(Identifier* ident);

        virtual string getCode();
};

#endif