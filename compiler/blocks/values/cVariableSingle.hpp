#ifndef CVARSINGLE_HPP
#define CVARSINGLE_HPP
#include "../../interfaces/iValue.hpp"
#include <string>

/*
* Single Variable class
*/
class VariableSingle: public Value {
    public:
        string pid;
        // Single Variable Constructor
        VariableSingle(string pid);

        virtual string getCode();
};

#endif