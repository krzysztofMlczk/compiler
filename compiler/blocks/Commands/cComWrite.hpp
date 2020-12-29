#ifndef CCOMWRITE_HPP
#define CCOMWRITE_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   Write command CLASS
*/
class ComWrite: public Command {
    public:
        string getCode();
};

#endif