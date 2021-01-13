#include "iCommand.hpp"

void Command::concat(vector<string>* code, vector<Command*>* cmds, SymbolTable* symbolTable) {
    vector<Command*>::iterator it = cmds->begin();

    for (; it != cmds->end(); ++it) {
        vector<string> code1 = (*it)->getCode(symbolTable);
        code->insert(code->end(), code1.begin(), code1.end());
    }
}

int Command::count_instructions(vector<Command*>* cmds, SymbolTable* symbolTable) {
    vector<Command*>::iterator it = cmds->begin();
    int instructions_counter = 0;

    for (; it != cmds->end(); ++it) {
        vector<string> code = (*it)->getCode(symbolTable);
        instructions_counter += code.size();
    }
    return instructions_counter;
}