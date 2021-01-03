#include "cCondLt.hpp"

CondLt::CondLt(Value* val1, Value* val2):Condition(val1, val2) {
    
}

vector<string> CondLt::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    this->val1->outcome_reg = this->outcome_reg;
    code = this->val1->getCode(symbolTable);

    this->val2->outcome_reg = this->clobbers.at(0);
    vector<string> code1 = this->val2->getCode(symbolTable);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("INC " + this->outcome_reg);
    code.push_back("SUB " + this->outcome_reg + " " + this->clobbers.at(0));

    return code;
}
