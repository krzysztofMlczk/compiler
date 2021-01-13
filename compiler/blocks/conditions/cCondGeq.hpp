#ifndef CCONDGEQ_HPP
#define CCONDGEQ_HPP
#include "../../interfaces/iCondition.hpp"
#include <string>

/*
*   Condition ">=" CLASS
*/
class CondGeq: public Condition {
    public:
        CondGeq(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif