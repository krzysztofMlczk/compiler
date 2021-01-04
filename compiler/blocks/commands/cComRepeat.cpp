#include "cComRepeat.hpp"

ComRepeat::ComRepeat(vector<Command*>* cmds, Condition* cond) {
    this->commands = cmds;
    this->condition = cond;
}

vector<string> ComRepeat::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    vector<string> occupied_registers{"a"};

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // every condition requires clobbers, then assign them
    this->condition->clobbers = this->getClobbers(&occupied_registers, this->condition->clobber_counter);
    vector<string> cond_code = this->condition->getCode(symbolTable);

    int cond_code_len = cond_code.size();
    int cmds_len = this->commands->size();

    // append commands to code
    code.insert(code.end(), this->commands->begin(), this->commands->end());
    // append condition code
    code.insert(code.end(), cond_code.begin(), cond_code.end());

    code.push_back("JZERO a 2");
    code.push_back("JUMP -" + to_string(cmds_len + cond_code_len + 1));

    return code;
}