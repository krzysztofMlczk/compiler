#include "cVariableValue.hpp"

VariableValue::VariableValue(Identifier* ident) {
    this->ident = ident;
}

string VariableValue::getCode() {
    return "";
}