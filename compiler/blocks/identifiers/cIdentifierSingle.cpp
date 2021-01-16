#include "cIdentifierSingle.hpp"

IdentifierSingle::IdentifierSingle(string pid, int line):Identifier(pid, line) {
    this->check_init = true;
}

IdentifierSingle::IdentifierSingle(string pid):Identifier(pid){
    this->check_init = true;
}

vector<string> IdentifierSingle::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    Symbol* sym = symbolTable->getSingleVar(this->pid, this->check_init, this->line);
    ull offset = sym->offset;
    Constant constant(offset);
    constant.outcome_reg = this->outcome_reg;
    return constant.getCode(symbolTable, regManager);
}