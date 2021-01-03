#ifndef CCONDEQ_HPP
#define CCONDEQ_HPP
#include "../../interfaces/iCondition.hpp"

/*
*   Condition "=" CLASS
*/
class CondEq: public Condition {
    public:
        const ull clobber_counter = 2;
        CondEq(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif