#include "cVariableValue.hpp"

VariableValue::VariableValue(Identifier* ident) {
    this->ident = ident;
}

vector<string> VariableValue::getCode(SymbolTable* symbolTable) {
    vector<string> code;

    this->ident->outcome_reg = this->outcome_reg;
    code = this->ident->getCode(symbolTable);
    code.push_back("LOAD " + this->outcome_reg + " " + this->outcome_reg);

    return code;
}