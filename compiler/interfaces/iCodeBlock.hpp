#ifndef ICODEBLOCK_HPP
#define ICODEBLOCK_HPP
#include <string>
#include <vector>
#include "../symbol_table/cSymbolTable.hpp"
typedef unsigned long long ull;

using namespace std;

/*
*   CodeBlock INTERFACE
*/
class CodeBlock {
    public:
        const ull clobber_counter = 0;
        vector<string> clobbers;
        // Virtual method - generates code for specific block of code
        virtual vector<string> getCode(SymbolTable* symbolTable) = 0;
    
    protected:
    private:
};

#endif 
