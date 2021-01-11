#include "cCondGeq.hpp"

CondGeq::CondGeq(Value* val1, Value* val2):Condition(val1, val2){
    this->clobber_counter = 1;
}

vector<string> CondGeq::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    this->val2->outcome_reg = this->outcome_reg;
    code = this->val2->getCode(symbolTable);

    this->val1->outcome_reg = this->clobbers.at(0);
    vector<string> code1 = this->val1->getCode(symbolTable);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("SUB " + this->outcome_reg + " " + this->clobbers.at(0));

    return code;
}
