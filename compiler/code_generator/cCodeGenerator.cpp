#include "cCodeGenerator.hpp"

CodeGenerator::CodeGenerator() {
    //constructor
}

/*
* Method for adding new array declarations to the symbol table
*/
void CodeGenerator::addSymbol(const char* pid, ull num1, ull num2) {
    Symbol* new_symbol = new Symbol(std::string(pid), this->symbolTable.mem_offset, num1, num2);
    this->symbolTable.addSymbol(new_symbol);
}

/*
* Method for adding new variable declarations to the symbol table
*/
void CodeGenerator::addSymbol(const char* pid) {
    Symbol* new_symbol = new Symbol(std::string(pid), this->symbolTable.mem_offset);
    this->symbolTable.addSymbol(new_symbol);
}

/*
* Method for generating code "recursively"
*/
vector<string> CodeGenerator::generateCode(vector<Command*>* cmds) {
    vector<string> code;
    vector<string> outcome;
    vector<Command*>::iterator it = cmds->begin();
    
    for (; it != cmds->end(); ++it) {
        outcome = (*it)->getCode(&symbolTable, &regManager); // get output from getCode() method
        // append outcome to code vector
        code.insert(code.end(), outcome.begin(), outcome.end());
    }

    code.push_back("HALT");

    return code;
}