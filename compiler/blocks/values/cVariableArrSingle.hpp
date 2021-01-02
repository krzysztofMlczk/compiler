#ifndef CVARARRSINGLE_HPP
#define CVARARRSINGLE_HPP
#include "../../interfaces/iValue.hpp"
#include <string>

/*
* Arr[pidentifier] variable class
*/
class VariableArrSingle: public Value {
    public:
        string pid_ext;
        string pid_int;
        // Arr[pidentifier] variable class
        VariableArrSingle(string pid_ext, string pid_int);

        virtual string getCode();
};

#endif