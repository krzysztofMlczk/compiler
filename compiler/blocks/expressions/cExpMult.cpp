#include "cExpMult.hpp"

ExpMult::ExpMult(Value* val1, Value* val2):Expression(val1, val2) {
    this->clobber_counter = 2;
}

vector<string> ExpMult::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;
    
    // this expression needs additional register
    this->clobbers = regManager->getClobbers(this->clobber_counter);

    // set outcome reg for val1
    this->val1->outcome_reg = this->clobbers.at(0);

    // set out reg for val2
    this->val2->outcome_reg = this->clobbers.at(1);

    // put val1 and val2 in their registers
    // make clobber(0) occupied
    regManager->occupy(this->clobbers.at(0));
    code = this->val1->getCode(symbolTable, regManager);
    // make clobber(1) occupied
    regManager->occupy(this->clobbers.at(1));
    vector<string> code1 = this->val2->getCode(symbolTable, regManager);
    code.insert(code.end(), code1.begin(), code1.end());
    
    // reset out reg
    code.push_back("RESET " + this->outcome_reg);

    // check if val2 is already 0
    // if it is, then exit the loop
    code.push_back("JZERO " + this->clobbers.at(1) + " " + to_string(7));
    // check if val2 is odd
    code.push_back("JODD " + this->clobbers.at(1) + " 2");
    // if it is not odd, then just go to shifting values
    code.push_back("JUMP 2");
    // if it is odd, then add current val1 to out_reg
    code.push_back("ADD " + this->outcome_reg + " " + this->clobbers.at(0));
    // double val1 and halve val2
    code.push_back("SHL " + this->clobbers.at(0));
    code.push_back("SHR " + this->clobbers.at(1));
    // jump to start to check loop condition
    code.push_back("JUMP -" + to_string(6));

    // free registers
    regManager->free(this->clobbers.at(0));
    regManager->free(this->clobbers.at(1));

    return code;
}