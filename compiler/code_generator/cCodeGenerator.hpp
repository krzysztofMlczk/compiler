#ifndef CCG_HPP
#define CCG_HPP
#include <string>
#include "../symbol_table/cSymbolTable.hpp"

typedef unsigned long long ull;

/*
*   Code Generator Class
*   (Wrapper Class for management of code generation using getCode() methods)
*/
class CodeGenerator {
    public:
    SymbolTable symbolTable;
    ull mem_offset; // keeps track of where new declarations should be placed
    CodeGenerator();
    void addSymbol(const char* pid, ull num1, ull num2);
    void addSymbol(const char* pid);
};

#endif