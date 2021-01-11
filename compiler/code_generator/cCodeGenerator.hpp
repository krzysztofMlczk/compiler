#ifndef CCG_HPP
#define CCG_HPP
#include <string>
#include <vector>
#include "../symbol_table/cSymbolTable.hpp"
#include "../interfaces/iCommand.hpp"
#include <iostream>

using namespace std;

typedef unsigned long long ull;

/*
*   Code Generator Class
*   (Wrapper Class for management of code generation using getCode() methods)
*/
class CodeGenerator {
    public:
        SymbolTable symbolTable;
        CodeGenerator(); // constructor

        //add Array variable to symbolTable
        void addSymbol(const char* pid, ull num1, ull num2);

        //add single variable to symbolTable
        void addSymbol(const char* pid);

        vector<string> generateCode(vector<Command*>* cmds);
};

#endif