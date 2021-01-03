#ifndef CCOMREAD_HPP
#define CCOMREAD_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iIdentifier.hpp"
#include <string>

/*
*   Read command CLASS
*/
class ComRead: public Command {
    public:
        Identifier* ident;
        ComRead(Identifier* id);
        virtual string getCode();
};

#endif