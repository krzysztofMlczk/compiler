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
        
    protected:
    private:
};

#endif
