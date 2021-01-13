#include "cComIf.hpp"

ComIf::ComIf(Condition* cond, vector<Command*>* cmds) {
    this->condition = cond;
    this->commands = cmds;
}

vector<string> ComIf::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // make a occupied
    regManager->occupy("a");
    code = this->condition->getCode(symbolTable, regManager);

    // free condition register
    regManager->free("a");

    int jump = this->count_instructions(this->commands, symbolTable) + 1;

    code.push_back("JZERO a 2");
    code.push_back("JUMP " + to_string(jump));
    // append cmds to perform when condition output is true
    this->concat(&code, this->commands, symbolTable);

    return code;
}