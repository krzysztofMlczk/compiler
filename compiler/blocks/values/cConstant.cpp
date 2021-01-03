#include "cConstant.hpp"

Constant::Constant(ull number) {
    this->value = number;
}

vector<string> Constant::getCode(SymbolTable* symbolTable) {
    return vector<string>();
}