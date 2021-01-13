#include "cExpAsVal.hpp"

ExpAsVal::ExpAsVal(Value* val1):Expression(val1) {
    //constructor
    this->clobber_counter = 0; // ExpAsVal doesn't need additional registers
}

vector<string> ExpAsVal::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    this->val1->outcome_reg = this->outcome_reg;
    return this->val1->getCode(symbolTable, regManager);
}