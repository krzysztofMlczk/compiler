#ifndef CCOMFOR_HPP
#define CCOMFOR_HPP
#include "../../interfaces/iCommand.hpp"
#include "../identifiers/cIdentifierSingle.hpp"
#include "../../interfaces/iIdentifier.hpp"
#include "../../interfaces/iValue.hpp"
#include "../values/cVariableValue.hpp"

/*
*   For command CLASS
*/
class ComFor: public Command {
    public:
        Value* from;
        Value* to;
        vector<Command*>* commands;
        string iter_name;
        ComFor(string pid, Value* from, Value* to, vector<Command*>* cmds);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif