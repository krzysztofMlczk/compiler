#ifndef CCOMWHILE_HPP
#define CCOMWHILE_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iCondition.hpp"

/*
*   While command CLASS
*/
class ComWhile: public Command {
    public:
        Condition* condition;
        vector<Command*>* commands;
        ComWhile(Condition* cond, vector<Command*>* cmds);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif