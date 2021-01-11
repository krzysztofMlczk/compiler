#include "iCommand.hpp"

/*
* Method for getting registers as globbers
*/
vector<string> Command::getClobbers(vector<string>* occupied, ull amount) {
    vector<string> outcome;
    string registers[] = {"a", "b", "c", "d", "e", "f"};
    ull counter = 0;
    cout << amount + 10 << endl;
    int i = 0;
    while (counter != amount && i < 6) {
        cout << "Asigning clobbers" << endl;
        if (find(occupied->begin(), occupied->end(), registers[i]) == occupied->end()) {
            cout << registers[i] << endl;
            outcome.push_back(registers[i]);
            occupied->push_back(registers[i]);
            counter++;
        }
        i++;
    }

    return outcome;
}

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