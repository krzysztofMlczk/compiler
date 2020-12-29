#ifndef IEXPRESSION_HPP
#define IEXPRESSION_HPP
#include "iCodeBlock.hpp"
#include "iValue.hpp"
#include <string>

/*
*   Expression INTERFACE
*/
class Expression: public CodeBlock {
    public:
        Value* val1;
        Value* val2;
        // Expression can be a single value
        Expression(Value* v1);
        // Expression evaluated from two values
        Expression(Value* v1, Value* v2);
        /*
        *   Target REG in which we will get evaluated value
        *   of this expression
        */
        std::string outcome_reg;

    protected:
    private:
};

#endif