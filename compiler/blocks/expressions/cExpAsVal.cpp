#include "cExpAsVal.hpp"

ExpAsVal::ExpAsVal(Value* val1):Expression(val1) {
    //constructor
}

vector<string> ExpAsVal::getCode(SymbolTable* symbolTable) {
    this->val1->outcome_reg = this->outcome_reg;
    return this->val1->getCode(symbolTable);
}