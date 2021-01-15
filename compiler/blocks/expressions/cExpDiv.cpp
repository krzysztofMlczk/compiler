#include "cExpDiv.hpp"

ExpDiv::ExpDiv(Value* val1, Value* val2):Expression(val1, val2) {
    this->clobber_counter = 4;
}

vector<string> ExpDiv::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // this expression needs additional register
    this->clobbers = regManager->getClobbers(this->clobber_counter);

    // set out reg for val1 (numerator)
    this->val1->outcome_reg = this->clobbers.at(1);

    // set out reg for val2 (denominator)
    this->val2->outcome_reg = this->clobbers.at(0);

    // put values in their registers
    // make clobbers(1) occupied
    regManager->occupy(this->clobbers.at(1));
    code = this->val1->getCode(symbolTable, regManager);
    // make clobbers(0) occupied
    regManager->occupy(this->clobbers.at(0));
    vector<string> code1 = this->val2->getCode(symbolTable, regManager);
    code.insert(code.end(), code1.begin(), code1.end());


    // reset register where we will get result of division
    code.push_back("RESET " + this->outcome_reg);
    // if value2 == 0, then jump to end
    code.push_back("JZERO " + this->clobbers.at(0) + " 28");

    // copy to clobbers.at(2) val1
    code.push_back("RESET " + this->clobbers.at(2));
    code.push_back("ADD " + this->clobbers.at(2) + " " + this->clobbers.at(1));

    // count number of bits in val1 and save in out_reg
    code.push_back("JZERO " + this->clobbers.at(2) + " 4");
    code.push_back("SHR " + this->clobbers.at(2));
    code.push_back("INC " + this->outcome_reg);
    code.push_back("JUMP -3");

    // remember number of val1 bits in clobbers.at(2)
    code.push_back("ADD " + this->clobbers.at(2) + " " + this->outcome_reg);

    // shift left denominator as many times as bits in numerator
    // and save shifted denumerator in clobbers.at(0)
    code.push_back("JZERO " + this->outcome_reg + " 4");
    code.push_back("SHL " + this->clobbers.at(0));
    code.push_back("DEC " + this->outcome_reg);
    code.push_back("JUMP -3");

    // for each bit in val1 bits
    code.push_back("JZERO " + this->clobbers.at(2) + " 16");
    // shift left partial remainder
    code.push_back("SHL " + this->clobbers.at(1));
    // save shifted partial remainder in clobbers.at(3)
    code.push_back("RESET " + this->clobbers.at(3));
    code.push_back("ADD " + this->clobbers.at(3) + " " + this->clobbers.at(1));
    // check if partial remainder - shifted denumerator >= 0
    code.push_back("INC " + this->clobbers.at(1));
    code.push_back("SUB " + this->clobbers.at(1) + " " + this->clobbers.at(0));

    code.push_back("JZERO " + this->clobbers.at(1) + " 2");
    code.push_back("JUMP 4");
    // if partial remainder - shifted denumerator > 0
    // add result bit = 0 and new partial remainder is restored shifted earlier remainder
    code.push_back("SHL " + this->outcome_reg);
    code.push_back("ADD " + this->clobbers.at(1) + " " + this->clobbers.at(3));
    code.push_back("JUMP 4");
    // if partial remainder - shifted denumerator >= 0
    // add result bit = 1
    code.push_back("DEC " + this->clobbers.at(1));
    code.push_back("SHL " + this->outcome_reg);
    code.push_back("INC " + this->outcome_reg);
    // decrement number of bits (move on the bits)
    code.push_back("DEC " + this->clobbers.at(2));
    // go to the begining of the loop
    code.push_back("JUMP -15");

    // free clobber.at(0)
    regManager->free(this->clobbers.at(0));
    regManager->free(this->clobbers.at(1));

    return code;
}