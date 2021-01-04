#include "cComRead.hpp"

ComRead::ComRead(Identifier* id) {
    this->ident = id;
}

vector<string> ComRead::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    vector<string> occupied_registers{"a"};

    // assign out_reg for ident
    this->ident->outcome_reg = "a";
    // we are initializing ident, so set check_init to false and make it initialized
    this->ident->check_init = false;
    symbolTable->initialize(this->ident->pid);
    // if ident requires clobbers, then assign them
    this->ident->clobbers = this->getClobbers(&occupied_registers, this->ident->clobber_counter);
    code = this->ident->getCode(symbolTable);

    code.push_back("GET a");

    return code;
}