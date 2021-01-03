#ifndef CIDENTARRNUM_HPP
#define CIDENTARRNUM_HPP
#include "../../interfaces/iIdentifier.hpp"
#include "../values/cConstant.hpp"

/*
* class of an Identifier for a pidentifier(number) "type" variable
*/
class IdentifierArrNum: public Identifier {
    public:
        string pid_ext;
        ull index;
        // Arr[number] Identifier constructor
        IdentifierArrNum(string pid_ext, ull index);

        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif