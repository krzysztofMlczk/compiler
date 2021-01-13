#include "cComIfElse.hpp"

ComIfElse::ComIfElse(Condition* cond, vector<Command*>* cmds1, vector<Command*>* cmds2) {
    this->condition = cond;
    this->cmds_when_true = cmds1;
    this->cmds_when_false = cmds2;
}

vector<string> ComIfElse::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // make a occupied
    regManager->occupy("a");
    code = this->condition->getCode(symbolTable, regManager);

    // free a
    regManager->free("a");

    int jump = this->count_instructions(this->cmds_when_false, symbolTable, regManager) + 1 + 1;
    int end = this->count_instructions(this->cmds_when_true, symbolTable, regManager) + 1;

    code.push_back("JZERO a" + to_string(jump)); // jump to true block of commands

    // append cmds_when_false to code
    this->concat(&code, this->cmds_when_false, symbolTable, regManager);
    code.push_back("JUMP " + to_string(end));

    // append cmds_when_true to code
    this->concat(&code, this->cmds_when_true, symbolTable, regManager);

    return code;
}