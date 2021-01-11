#ifndef CCONDNEQ_HPP
#define CCONDNEQ_HPP
#include "../../interfaces/iCondition.hpp"

/*
*   Condition "!=" CLASS
*/
class CondNeq: public Condition {
    public:
        CondNeq(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif