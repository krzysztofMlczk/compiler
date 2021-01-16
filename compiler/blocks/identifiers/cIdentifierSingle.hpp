#ifndef CIDENTSINGLE_HPP
#define CIDENTSINGLE_HPP
#include "../../interfaces/iIdentifier.hpp"
#include "../../symbol_table/cSymbolTable.hpp"
#include "../values/cConstant.hpp"

/*
* class of an Identifier for a single variable
*/
class IdentifierSingle: public Identifier {
    public:
        // Single Identifier constructor
        IdentifierSingle(string pid, int line);
        IdentifierSingle(string pid);

        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif