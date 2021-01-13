#include "iCommand.hpp"

void Command::concat(vector<string>* code, vector<Command*>* cmds, SymbolTable* symbolTable, RegManager* RegManager) {
    vector<Command*>::iterator it = cmds->begin();

    for (; it != cmds->end(); ++it) {
        vector<string> code1 = (*it)->getCode(symbolTable, RegManager);
        code->insert(code->end(), code1.begin(), code1.end());
    }
}

int Command::count_instructions(vector<Command*>* cmds, SymbolTable* symbolTable, RegManager* regManager) {
    vector<Command*>::iterator it = cmds->begin();
    int instructions_counter = 0;

    for (; it != cmds->end(); ++it) {
        vector<string> code = (*it)->getCode(symbolTable, regManager);
        instructions_counter += code.size();
    }
    return instructions_counter;
}