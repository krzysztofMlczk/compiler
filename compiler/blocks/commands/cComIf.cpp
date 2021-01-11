#include "cComIf.hpp"

ComIf::ComIf(Condition* cond, vector<Command*>* cmds) {
    this->condition = cond;
    this->commands = cmds;
}

vector<string> ComIf::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    vector<string> occupied_registers{"a"};

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // every condition requires clobbers, then assign them
    cout << this->condition->clobber_counter << endl;
    this->condition->clobbers = this->getClobbers(&occupied_registers, this->condition->clobber_counter);
    code = this->condition->getCode(symbolTable);

    int jump = this->count_instructions(this->commands, symbolTable) + 1;

    code.push_back("JZERO a 2");
    code.push_back("JUMP " + to_string(jump));
    // append cmds to perform when condition output is true
    this->concat(&code, this->commands, symbolTable);

    return code;
}