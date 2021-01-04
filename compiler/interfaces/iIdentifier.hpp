#ifndef IIDENT_HPP
#define IIDENT_HPP
#include "iCodeBlock.hpp"
#include <string>

/*
*   Identifier INTERFACE
*/
class Identifier: public CodeBlock {
    public:
        string pid;
        Identifier(string pid);
        bool check_init; //tells if we should check if var is initialized
        string outcome_reg;
};

#endif