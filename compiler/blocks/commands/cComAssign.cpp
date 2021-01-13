#include "cComAssign.hpp"

ComAssign::ComAssign(Identifier* id, Expression* exp) {
    this->ident = id;
    this->expression = exp;
}

vector<string> ComAssign::getCode(SymbolTable* symbolTable) {
    
    vector<string> code;
    // for ident clobbers we can get anything besides reg "a"(out_reg) and "b" because in b we will save
    // outcome of expression!
    vector<string> occupied_for_ident{"a, b"};
    vector<string> occupied_for_exp{"b"}; // for exp clobbers we can get anything besides reg "b"(out_reg)

    // we have to perform exp code first, because maximal amount of registers used is 6
    // so if we perform ident code first we might override what is inside ident out_register! (reg "a"), but we need this value!
    // assign out_reg for expression
    this->expression->outcome_reg = "b";
    // if expression requires clobbers, then assign them
    this->expression->clobbers = this->getClobbers(&occupied_for_exp, this->expression->clobber_counter);
    code = this->expression->getCode(symbolTable);

    // assign out_reg for ident
    this->ident->outcome_reg = "a";
    // we are initializing ident, so set check_init to false and make it initialized
    this->ident->check_init = false;
    symbolTable->initialize(this->ident->pid);
    // if ident requires clobbers, then assign them
    this->ident->clobbers = this->getClobbers(&occupied_for_ident, this->ident->clobber_counter);
    vector<string> code1 = this->ident->getCode(symbolTable);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("STORE b a");

    return code;
}