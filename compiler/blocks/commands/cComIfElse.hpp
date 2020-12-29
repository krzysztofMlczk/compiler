#ifndef CCOMIFELSE_HPP
#define CCOMIFELSE_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   If Else command CLASS
*/
class ComIfElse: public Command {
    public:
        virtual string getCode();
};

#endif