#include "cComAssign.hpp"

ComAssign::ComAssign(Identifier* id, Expression* exp) {
    this->ident = id;
    this->expression = exp;
}

vector<string> ComAssign::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;
    
    // assign out_reg for expression
    this->expression->outcome_reg = "b";
    // make register b occupied - we dont want it to be overriden by ident, so keep it occupied
    regManager->occupy("b");
    code = this->expression->getCode(symbolTable, regManager);

    // assign out_reg for ident
    this->ident->outcome_reg = "a";
    // make register a occupied
    regManager->occupy("a");
    // we are initializing ident, so set check_init to false and make it initialized
    this->ident->check_init = false;
    symbolTable->initialize(this->ident->pid);
    vector<string> code1 = this->ident->getCode(symbolTable, regManager);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("STORE b a");

    // free registers
    regManager->free("a");
    regManager->free("b");

    return code;
}