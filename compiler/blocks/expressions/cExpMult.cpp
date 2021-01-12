#include "cExpMult.hpp"

ExpMult::ExpMult(Value* val1, Value* val2):Expression(val1, val2) {
    this->clobber_counter = 4;
}

vector<string> ExpMult::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    
    // set outcome reg for val1
    this->val1->outcome_reg = this->clobbers.at(3);

    // set out reg for val2 (it will be reg where outcome of multiplication will be placed)
    this->val2->outcome_reg = this->outcome_reg;

    // put val1 and val2 in their registers
    code = this->val1->getCode(symbolTable);
    vector<string> code1 = this->val2->getCode(symbolTable);
    code.insert(code.end(), code1.begin(), code1.end());

    // check if val1 is 0
    code.push_back("JUMP " + clobbers.at(3) + " 2");
    // if val1 is not 0, then go and check val2
    code.push_back("JUMP 3");
    // if val1 is 0 set outcome to 0 and go to end
    code.push_back("RESET " + this->outcome_reg);
    code.push_back("JUMP " + 26);
    // check if val2 is 0
    code.push_back("JZERO " + this->outcome_reg + " 2");
    // if val2 is not 0, then go and perform multiplication
    code.push_back("JUMP 2");
    // if val2 is zero, then just jump to end
    code.push_back("JUMP " + 23);

    // here is code for multiplication
    //reset register for counter
    code.push_back("RESET " + this->clobbers.at(2));
    // reset register for highest power of two <= than val1
    code.push_back("RESET " + this->clobbers.at(1));
    code.push_back("INC "+ this->clobbers.at(1));
    // copy val1 to clobbers.at(0)
    code.push_back("RESET " + clobbers.at(0));
    code.push_back("ADD " + this->clobbers.at(0) + " " + this->clobbers.at(3));

    // code for generating counter and highest power of two
    code.push_back("JZERO " + this->clobbers.at(0));
    code.push_back("SHR " + this->clobbers.at(0)); // divide multiplier
    code.push_back("SHL " + this->clobbers.at(1)); // multiply by 2 (in this register we will get highest power of 2 <= val1)
    code.push_back("INC " + this->clobbers.at(2)); // increment number of steps (required so we know how much we should SHL multiplicand)
    code.push_back("JUMP -4");

    code.push_back("SHR " + this->clobbers.at(1)); // we always multiply one time extra so get rid of this
    code.push_back("DEC " + this->clobbers.at(2)); // we always count one step extra so get rid of it

    // code for shifting the multiplicand(val2)
    // shift as much as steps counted
    code.push_back("JZERO " + this->clobbers.at(2));
    code.push_back("SHL " + this->outcome_reg); // shift left val2
    code.push_back("DEC " + this->clobbers.at(2)); // decrement step counter
    code.push_back("JUMP -3");

    // copy to clobbers.at(2) value of val1
    code.push_back("ADD " + this->clobbers.at(2) + " " + this->clobbers.at(3));
    // substract highest power of 2 <= than val1 from val1, so we know
    // how many times we should add val1 to val2, to get the multiplication result
    code.push_back("SUB " + this->clobbers.at(2) + " " + this->clobbers.at(1));

    // code for adding val1 to val2
    code.push_back("JZERO " + this->clobbers.at(2) + " 4");
    code.push_back("ADD " + this->outcome_reg + " " + this->clobbers.at(3));
    code.push_back("DEC " + this->clobbers.at(2));
    code.push_back("JUMP -3");

    return code;
}