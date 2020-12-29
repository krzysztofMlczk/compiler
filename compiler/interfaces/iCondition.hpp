#ifndef ICONDITION_HPP
#define ICONDITION_HPP
#include "iCodeBlock.hpp"
#include "iValue.hpp"
#include <string>

/*
*   Condition INTERFACE
*/
class Condition: public CodeBlock {
    public:
        Value* val1;
        Value* val2;
        Condition(Value* v1, Value* v2);
        /*
        *   Target REG in which we will get result for this condition
        *   REG contains 0 when => TRUE
        *   REG contains [^0] when => FALSE
        */
        std::string outcome_reg;
    
    protected:
    private:
};

#endif