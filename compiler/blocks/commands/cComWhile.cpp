#include "cComWhile.hpp"

ComWhile::ComWhile(Condition* cond, vector<Command*>* cmds) {
    this->condition = cond;
    this-> commands = cmds;
}

vector<string> ComWhile::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // assign out_reg for condition
    this->condition->outcome_reg = "a";
    // make a occupied
    regManager->occupy("a");
    code = this->condition->getCode(symbolTable, regManager);

    // free a
    regManager->free("a");

    // before each loop iteration condition has to be checked
    int cond_check_len = code.size();
    int commands_len = this->count_instructions(this->commands, symbolTable);

    // condition checking
    code.push_back("JZERO a 2"); // go to commands
    code.push_back("JUMP " + to_string(commands_len + 2)); // go to end
    // append commands to code
    this->concat(&code, this->commands, symbolTable);
    
    // jump to begining of condition checking
    code.push_back("JUMP -" + to_string(cond_check_len + 2 + commands_len));

    return code;
}