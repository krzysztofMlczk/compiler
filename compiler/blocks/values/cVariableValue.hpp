#ifndef CVARVAL_HPP
#define CVARVAL_HPP
#include "../../interfaces/iValue.hpp"
#include "../../interfaces/iIdentifier.hpp"

class VariableValue: public Value {
    public:
        Identifier* ident;
        VariableValue(Identifier* ident);

        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif