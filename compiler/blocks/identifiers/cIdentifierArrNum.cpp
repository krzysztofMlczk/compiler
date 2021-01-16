#include "cIdentifierArrNum.hpp"

IdentifierArrNum::IdentifierArrNum(string pid_ext, ull index, int line):Identifier(pid_ext, line) {
    this->index = index;
    this->check_init = false;
}

vector<string> IdentifierArrNum::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    Symbol* sym = symbolTable->getArrVar(this->pid, this->line);
    ull offset = sym->offset;
    ull start = sym->array_start;
    Constant constant(offset + (this->index - start));
    constant.outcome_reg = this->outcome_reg;
    return constant.getCode(symbolTable, regManager);
}