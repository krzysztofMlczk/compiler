#ifndef CCONSTANT_HPP
#define CCONSTANT_HPP
#include "../../interfaces/iValue.hpp"
#include <string>

/*
*   Constant Values CLASS
*   inherits from iValue
*/
class Constant: public Value {
    public:
        ull value;
        Constant(ull num);

        virtual string getCode();

};

#endif