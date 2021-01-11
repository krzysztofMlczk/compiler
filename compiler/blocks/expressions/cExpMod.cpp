#include "cExpMod.hpp"

ExpMod::ExpMod(Value* val1, Value* val2):Expression(val1, val2) {
    this->clobber_counter = 10;
}

vector<string> ExpMod::getCode(SymbolTable* symbolTable) {
    vector<string> code;

    return code;
}