#ifndef CCOMFORDOWNTO_HPP
#define CCOMFORDOWNTO_HPP
#include "../../interfaces/iCommand.hpp"

/*
*   For Downto command CLASS
*/
class ComForDownto: public Command {
    public:
        Value* from;
        Value* downto;
        vector<Command*>* commands;
        ComForDownto(Value* from, Value* downto, vector<Command*>* cmds);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif