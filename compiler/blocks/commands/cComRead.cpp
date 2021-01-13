#include "cComRead.hpp"

ComRead::ComRead(Identifier* id) {
    this->ident = id;
}

vector<string> ComRead::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // assign out_reg for ident
    this->ident->outcome_reg = "a";
    // make a occupied
    regManager->occupy("a");
    // we are initializing ident, so set check_init to false and make it initialized
    this->ident->check_init = false;
    symbolTable->initialize(this->ident->pid);

    code = this->ident->getCode(symbolTable, regManager);

    // free a
    regManager->free("a");

    code.push_back("GET a");

    return code;
}