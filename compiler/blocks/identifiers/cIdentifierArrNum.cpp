#include "cIdentifierArrNum.hpp"

IdentifierArrNum::IdentifierArrNum(string pid_ext, ull index) {
    this->pid_ext = pid_ext;
    this->index = index;
}

vector<string> IdentifierArrNum::getCode(SymbolTable* symbolTable) {
    Symbol* sym = symbolTable->getArrVar(this->pid_ext);
    ull offset = sym->offset;
    ull start = sym->array_start;
    Constant constant(offset + (this->index - start));
    constant.outcome_reg = this->outcome_reg;
    return constant.getCode(symbolTable);
}