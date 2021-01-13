#include "cVariableValue.hpp"

VariableValue::VariableValue(Identifier* ident) {
    this->ident = ident;
    this->is_variable = true;
    this->clobber_counter = 0; // VariableValue doesn't need additional registers
}

vector<string> VariableValue::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    this->ident->outcome_reg = this->outcome_reg;
    code = this->ident->getCode(symbolTable, regManager);
    code.push_back("LOAD " + this->outcome_reg + " " + this->outcome_reg);

    return code;
}