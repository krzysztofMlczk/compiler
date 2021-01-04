#include "cComIfElse.hpp"

ComIfElse::ComIfElse(Condition* cond, vector<Command*>* cmds1, vector<Command*>* cmds2) {
    this->condition = cond;
    this->cmds_when_true = cmds1;
    this->cmds_when_false = cmds2;
}

vector<string> ComIfElse::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    vector<string> occupied_registers{"a"};

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // every condition requires clobbers, then assign them
    this->condition->clobbers = this->getClobbers(&occupied_registers, this->condition->clobber_counter);
    code = this->condition->getCode(symbolTable);

    int jump = this->cmds_when_false->size() + 1;

    code.push_back("JZERO " + to_string(jump)); // jump to true block of commands

    // append cmds_when_false to code
    code.insert(code.end(), this->cmds_when_false->begin(), this->cmds_when_false->end());

    // append cmds_when_true to code
    code.insert(code.end(), this->cmds_when_true->begin(), this->cmds_when_true->end());

    return code;
}