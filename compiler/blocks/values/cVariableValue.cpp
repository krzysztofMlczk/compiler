#include "cVariableValue.hpp"

VariableValue::VariableValue(Identifier* ident) {
    this->ident = ident;
}

vector<string> VariableValue::getCode(SymbolTable* symbolTable) {
    return vector<string>();
}