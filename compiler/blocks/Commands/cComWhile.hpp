#ifndef CCOMWHILE_HPP
#define CCOMWHILE_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   While command CLASS
*/
class ComWhile: public Command {
    public:
        string getCode();
};

#endif