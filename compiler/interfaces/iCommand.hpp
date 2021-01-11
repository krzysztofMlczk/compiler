#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP
#include "iCodeBlock.hpp"
#include "iValue.hpp"
#include <algorithm>

/*
*   Command INTERFACE
*/
class Command: public CodeBlock {
    public:
        int count_instructions(vector<Command*>* cmds, SymbolTable* symbolTable);
        void concat(vector<string>* code, vector<Command*>* cmds, SymbolTable* symbolTable);
        vector<string> getClobbers(vector<string>* occupied, ull amount);
    protected:
    private:
};

#endif