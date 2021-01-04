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
        vector<string> getClobbers(vector<string>* occupied, ull amount);
    protected:
    private:
};

#endif