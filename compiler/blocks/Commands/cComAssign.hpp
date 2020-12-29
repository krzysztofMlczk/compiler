#ifndef CCOMASSIGN_HPP
#define CCOMASSIGN_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>

/*
*   Assign command CLASS
*/
class ComAssign: public Command {
    public:
        string getCode();
};

#endif