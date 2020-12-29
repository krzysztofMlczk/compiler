#ifndef CCOMFOR_HPP
#define CCOMFOR_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   For command CLASS
*/
class ComFor: public Command {
    public:
        virtual string getCode();
};

#endif