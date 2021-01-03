#ifndef CCONDLT_HPP
#define CCONDLT_HPP
#include "../../interfaces/iCondition.hpp"

/*
*   Condition "<" CLASS
*/
class CondLt: public Condition {
    public:
        const ull clobber_counter = 1;
        CondLt(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif