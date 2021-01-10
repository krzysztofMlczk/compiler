#ifndef IVALUE_HPP
#define IVALUE_HPP
#include "iCodeBlock.hpp"
#include <string>

/*
*   Value INTERFACE
*/
class Value: public CodeBlock {
    public:
        /*
        *   Target REG in which we will get this value
        */
        std::string outcome_reg;
        // indicates if object is instance of class VariableValue ()
        // super useful for write command
        bool is_variable; 
    protected:
    private:
};

#endif
