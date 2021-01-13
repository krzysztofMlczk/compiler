#ifndef CCONDLEQ_HPP
#define CCONDLEQ_HPP
#include "../../interfaces/iCondition.hpp"

/*
*   Condition "<=" CLASS
*/
class CondLeq: public Condition {
    public:
        CondLeq(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif