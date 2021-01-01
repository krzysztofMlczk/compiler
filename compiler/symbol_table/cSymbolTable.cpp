#include "cSymbolTable.hpp"

SymbolTable::SymbolTable() {
    //constructor
}

void SymbolTable::addSymbol(Symbol* sym) {
    this->table.push_back(sym);
}