#include "cConstant.hpp"

Constant::Constant(ull number) {
    this->value = number;
    this->is_variable = false;
}

vector<string> Constant::getCode(SymbolTable* symbolTable) {
    vector<string> code;

    code.push_back("RESET " + this->outcome_reg);
    ull number = this->value;

    while (number != 0) {
        // if last bit of number is equal to 1, then add INC instruction
        if (number & 1)
            code.push_back("INC " + this->outcome_reg);
        // if last bit of number is equal to 0, then we don't need to increment
        // but in both cases we have to shift left
        code.push_back("SHL " + this->outcome_reg);

        // bit shift number to the right
        number >>= 1; // number = number >> 1
    }
    
    return code;
}