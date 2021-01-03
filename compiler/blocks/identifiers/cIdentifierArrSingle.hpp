#ifndef CIDENTARRSINGLE_HPP
#define CIDENTARRSINGLE_HPP
#include "../../interfaces/iIdentifier.hpp"
#include "cIdentifierSingle.hpp"
#include "../values/cVariableValue.hpp"

/*
* class of an Identifier for a pidentifier(pidentifier) "type" variable
*/
class IdentifierArrSingle: public Identifier {
    public:
        string pid_ext;
        string pid_int;
        const ull clobber_counter = 1;
        // Arr[pid] identifier constructor
        IdentifierArrSingle(string pid_ext, string pid_int);

        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif