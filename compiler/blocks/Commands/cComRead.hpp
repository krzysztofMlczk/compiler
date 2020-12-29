#ifndef CCOMREAD_HPP
#define CCOMREAD_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   Read command CLASS
*/
class ComRead: public Command {
    public:
        string getCode();
};

#endif