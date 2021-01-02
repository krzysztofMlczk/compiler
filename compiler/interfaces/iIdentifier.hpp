#ifndef IIDENT_HPP
#define IIDENT_HPP
#include "iCodeBlock.hpp"
#include <string>

/*
*   Identifier INTERFACE
*/
class Identifier: public CodeBlock {
    public:
        string outcome_reg;
};

#endif