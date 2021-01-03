#ifndef CCONDLEQ_HPP
#define CCONDLEQ_HPP
#include "../../interfaces/iCondition.hpp"

/*
*   Condition "<=" CLASS
*/
class CondLeq: public Condition {
    public:
        const ull clobber_counter = 1;
        CondLeq(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif