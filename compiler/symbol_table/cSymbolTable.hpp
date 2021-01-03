#ifndef CSYMTAB_HPP
#define CSYMTAB_HPP
#include "cSymbol.hpp"
#include "../exceptions/cException.hpp"
#include <vector>

using namespace std;

/*
*   Symbol table class
*/
class SymbolTable {
    public:
        vector<Symbol*> table;
        SymbolTable();
        void addSymbol(Symbol* sym);
        void rmSymbol(Symbol* sym);
        // returns single var symbol
        Symbol* getSingleVar(string pid);
        // returns arr var symbol
        Symbol* getArrVar(string pid_ext);
};

#endif