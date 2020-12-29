#ifndef CVARIABLE_HPP
#define CVARIABLE_HPP
#include "../../interfaces/iValue.hpp"
#include <string>

/*
*   Variables CLASS
*   inherits from iValue
*/
class Variable: public Value {
    public:
        string pid;
        string pid_ext;
        string pid_int;
        ull index;

        // Single Variable Constructor
        Variable(string pid);
        // Array cell Constructor (refered to by variable)
        Variable(string pid_ext, string pid_int);
        // Array cell Constructor (refered to by index)
        Variable(string pid, ull index);

        string getCode();
    protected:
    private:
};

#endif