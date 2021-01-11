#ifndef CCONSTANT_HPP
#define CCONSTANT_HPP
#include <tgmath.h>
#include "../../interfaces/iValue.hpp"

/*
*   Constant Values CLASS
*   inherits from iValue
*/
class Constant: public Value {
    public:
        ull value;
        Constant(ull num);

        virtual vector<string> getCode(SymbolTable* symbolTable);

};

#endif