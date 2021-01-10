#ifndef CCOMFORDOWNTO_HPP
#define CCOMFORDOWNTO_HPP
#include "../../interfaces/iCommand.hpp"
#include "../identifiers/cIdentifierSingle.hpp"
#include "../../interfaces/iIdentifier.hpp"
#include "../../interfaces/iValue.hpp"
#include "../values/cVariableValue.hpp"

/*
*   For Downto command CLASS
*/
class ComForDownto: public Command {
    public:
        Value* from;
        Value* downto;
        string iter_name;
        vector<Command*>* commands;
        ComForDownto(string pid, Value* from, Value* downto, vector<Command*>* cmds);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif