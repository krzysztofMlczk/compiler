#ifndef CCOMREPEAT_HPP
#define CCOMAREPEAT_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   Repeat command CLASS
*/
class ComRepeat: public Command {
    public:
        string getCode();
};

#endif