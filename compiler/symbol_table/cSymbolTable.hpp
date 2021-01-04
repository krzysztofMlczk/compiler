#ifndef CSYMTAB_HPP
#define CSYMTAB_HPP
#include "cSymbol.hpp"
#include "../exceptions/cException.hpp"
#include <vector>
#include <algorithm>

using namespace std;

/*
*   Symbol table class
*/
class SymbolTable {
    public:
        vector<Symbol*> table;
        ull mem_offset; // keeps track of where new declarations should be placed
        SymbolTable();
        void addSymbol(Symbol* sym);
        void initialize(string pid);
        void rmSymbol(Symbol* sym);
        // returns single var symbol
        Symbol* getSingleVar(string pid, bool check_init);
        // returns arr var symbol
        Symbol* getArrVar(string pid_ext);
};

#endif