#ifndef CCOMIFELSE_HPP
#define CCOMIFELSE_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iCondition.hpp"

/*
*   If Else command CLASS
*/
class ComIfElse: public Command {
    public:
        Condition* condition;
        vector<Command*>* cmds_when_true;
        vector<Command*>* cmds_when_false;
        ComIfElse(Condition* cond, vector<Command*>* cmds1, vector<Command*>* cmds2);
        virtual vector<string> getCode(SymbolTable* SymbolTable);
};

#endif