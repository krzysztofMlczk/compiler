#ifndef CCOMIF_HPP
#define CCOMIF_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iCondition.hpp"

/*
*   If command CLASS
*/
class ComIf: public Command {
    public:
        Condition* condition;
        vector<Command*>* commands;
        ComIf(Condition* cond, vector<Command*>* cmds);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif