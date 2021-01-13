#ifndef CCOMREAD_HPP
#define CCOMREAD_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iIdentifier.hpp"

/*
*   Read command CLASS
*/
class ComRead: public Command {
    public:
        Identifier* ident;
        ComRead(Identifier* id);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif