#include "cSymbolTable.hpp"

SymbolTable::SymbolTable() {
    //constructor
}

void SymbolTable::addSymbol(Symbol* sym) {
    // check for redeclaration
    if (this->checkIfAlreadyDeclared(sym->name)) {
        throw Exception("Redeclaration of variable: " + sym->name);
        return;
    }
    // when someone tries to declare array for example: arr(100:5)
    if (sym->is_array && sym->array_start > sym->array_end) {
        throw Exception("Invalid range for array variable: " + sym->name);
        return;
    }
    // otherwise just declare new symbol
    this->table.push_back(sym);
    this->mem_offset += sym->size;
}

bool SymbolTable::checkIfAlreadyDeclared(string pid) {
    vector<Symbol*>::iterator it = this->table.begin();

    for (; it != table.end(); ++it) {
        if((*it)->name == pid)
            return true;
    }
    return false;
}

void SymbolTable::initialize(string pid) {
    vector<Symbol*>::iterator it = this->table.begin();

    for (; it != table.end(); ++it) {
        if ((*it)->name == pid) {
            (*it)->initialized = true;
        }
    }
}

void SymbolTable::rmSymbol(Symbol* sym) {
    vector<Symbol*>::iterator position = find(this->table.begin(), this->table.end(), sym);
    if (position != this->table.end()) // == myVector.end() means the element was not found
        this->table.erase(position);
    this->mem_offset -= sym->size;

    delete sym;
}

Symbol* SymbolTable::getSingleVar(string pid, bool check_init) {

    vector<Symbol*>::iterator it = this->table.begin();

    for (; it != table.end(); ++it) {
        if ((*it)->name == pid) {
            if ((*it)->is_array) {
                throw Exception("Invalid reference to array type: " + pid);
            }
            if (!(*it)->initialized && check_init) {
                throw Exception("Uninitialized variable: "+ pid);
            }
            // when variable is iterator and check_init is set to false
            // check_init will only be false when ASSIGN or READ into variable
            // it means that someone tries to modify value of iterator - ILLEGAL
            if ((*it)->is_iterator && !check_init) {
                throw Exception("Iterator can't be modified inside loop: " + pid);
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