#ifndef CCOMFORDOWNTO_HPP
#define CCOMFORDOWNTO_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   For Downto command CLASS
*/
class ComForDownto: public Command {
    public:
        string getCode();
};

#endif