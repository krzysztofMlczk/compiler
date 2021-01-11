#include "cCondNeq.hpp"

CondNeq::CondNeq(Value* val1, Value* val2):Condition(val1, val2) {
    this->clobber_counter = 2;
}

vector<string> CondNeq::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    this->val1->outcome_reg = this->outcome_reg;
    code = this->val1->getCode(symbolTable);

    this->val2->outcome_reg = this->clobbers.at(0);
    vector<string> code1 = this->val2->getCode(symbolTable);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("RESET " + this->clobbers.at(1));
    code.push_back("ADD " + this->clobbers.at(1) + " " + this->outcome_reg);
    code.push_back("SUB " + this->outcome_reg + " " + this->clobbers.at(0));
    code.push_back("JZERO " + this->outcome_reg + " 3");
    code.push_back("RESET " + this->outcome_reg);
    code.push_back("JUMP 5");
    code.push_back("SUB " + this->clobbers.at(0) + " " + this->clobbers.at(1));
    code.push_back("JZERO " + this->clobbers.at(0) + " 2");
    code.push_back("JUMP 2");
    code.push_back("INC " + this->outcome_reg);

    return code;
}