#ifndef CCOMIF_HPP
#define CCOMIF_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   If command CLASS
*/
class ComIf: public Command {
    public:
        string getCode();
};

#endif