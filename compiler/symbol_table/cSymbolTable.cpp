#include "cSymbolTable.hpp"

SymbolTable::SymbolTable() {
    //constructor
}

void SymbolTable::addSymbol(Symbol* sym) {
    this->table.push_back(sym);
}

Symbol* SymbolTable::getSingleVar(string pid) {

    vector<Symbol*>::iterator it = this->table.begin();

    for (; it != table.end(); ++it) {
        if ((*it)->name == pid) {
            if ((*it)->is_array) {
                throw Exception("Invalid reference to array type: " + pid);
            }
            return (*it);
        }
    }
    throw Exception("Undeclared variable: " + pid);
}

Symbol* SymbolTable::getArrVar(string pid_ext) {

    vector<Symbol*>::iterator it = this->table.begin();

    for (; it != table.end(); ++it) {
        if ((*it)->name == pid_ext) {
            if (!(*it)->is_array) {
                throw Exception("Invalid reference to single variable: " + pid_ext);
            }
            return (*it);
        }
    }
    throw Exception("Undeclared variable: " + pid_ext);
}