#include "cComRepeat.hpp"

ComRepeat::ComRepeat(vector<Command*>* cmds, Condition* cond) {
    this->commands = cmds;
    this->condition = cond;
}

vector<string> ComRepeat::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // make a occupied
    regManager->occupy("a");
    vector<string> cond_code = this->condition->getCode(symbolTable, regManager);

    // free a
    regManager->free("a");

    int cond_code_len = cond_code.size();
    int cmds_len = this->count_instructions(this->commands, symbolTable);

    // append commands to code
    this->concat(&code, this->commands, symbolTable);

    // append condition code
    code.insert(code.end(), cond_code.begin(), cond_code.end());
    
    code.push_back("JZERO a 2");
    code.push_back("JUMP -" + to_string(cmds_len + cond_code_len + 1));

    return code;
}