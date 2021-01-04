#include "cIdentifierArrNum.hpp"

IdentifierArrNum::IdentifierArrNum(string pid_ext, ull index):Identifier(pid_ext) {
    this->index = index;
    this->check_init = false;
}

vector<string> IdentifierArrNum::getCode(SymbolTable* symbolTable) {
    Symbol* sym = symbolTable->getArrVar(this->pid);
    ull offset = sym->offset;
    ull start = sym->array_start;
    Constant constant(offset + (this->index - start));
    constant.outcome_reg = this->outcome_reg;
    return constant.getCode(symbolTable);
}