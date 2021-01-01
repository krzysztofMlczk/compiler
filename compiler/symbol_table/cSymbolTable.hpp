#ifndef CSYMTAB_HPP
#define CSYMTAB_HPP
#include "cSymbol.hpp"
#include <vector>

/*
*   Symbol table class
*/
class SymbolTable {
    public:
        std::vector<Symbol *> table;
        SymbolTable();
        void addSymbol(Symbol* sym);
        void rmSymbol(Symbol* sym);
};

#endif