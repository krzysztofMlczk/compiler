#include "cIdentifierSingle.hpp"

IdentifierSingle::IdentifierSingle(string pid) {
    this->pid = pid;
}

vector<string> IdentifierSingle::getCode(SymbolTable* symbolTable) {
    Symbol* sym = symbolTable->getSingleVar(this->pid);
    ull offset = sym->offset;
    Constant constant(offset);
    constant.outcome_reg = this->outcome_reg;
    return constant.getCode(symbolTable);
}