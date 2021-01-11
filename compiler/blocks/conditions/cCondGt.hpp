#ifndef CCONDGT_HPP
#define CCONDGT_HPP
#include "../../interfaces/iCondition.hpp"

/*
*   Condition ">" CLASS
*/
class CondGt: public Condition {
    public:
        CondGt(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif