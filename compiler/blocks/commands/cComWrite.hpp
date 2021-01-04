#ifndef CCOMWRITE_HPP
#define CCOMWRITE_HPP
#include "../../interfaces/iCommand.hpp"

/*
*   Write command CLASS
*/
class ComWrite: public Command {
    public:
        Value* value;
        ComWrite(Value* val);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif