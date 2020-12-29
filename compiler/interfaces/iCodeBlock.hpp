#ifndef ICODEBLOCK_HPP
#define ICODEBLOCK_HPP
#include <string>
typedef unsigned long long ull;

using namespace std;

/*
*   CodeBlock INTERFACE
*/
class CodeBlock {
    public:
        // Virtual method - generates code for specific block of code
        virtual std::string getCode() = 0;
    
    protected:
    private:
};

#endif 
