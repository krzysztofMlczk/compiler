#include "cConstant.hpp"

Constant::Constant(ull number) {
    this->value = number;
    this->is_variable = false;
}

vector<string> Constant::getCode(SymbolTable* symbolTable) {
    vector<string> code;

    code.push_back("RESET " + this->outcome_reg);
    ull number = this->value;

    unsigned short value_len_in_bits = floor(log2(this->value)) + 1;

    for (int i = value_len_in_bits - 1; i > 0; i--) {
        if (number & 1 << i) {
            code.push_back("INC " + this->outcome_reg);
        }
        code.push_back("SHL " + this->outcome_reg);
    }

    if (number & 1) {
        code.push_back("INC " + this->outcome_reg);
    }

    return code;
}