#ifndef CVARARRNUM_HPP
#define CVARARRNUM_HPP
#include "../../interfaces/iValue.hpp"
#include <string>

/*
* Arr[number] variable class
*/
class VariableArrNum: public Value {
    public:
        string pid_ext;
        ull index;
        // Arr[number] variable constructor
        VariableArrNum(string pid_ext, ull index);

        virtual string getCode();
};

#endif