#ifndef CEXPMULT_HPP
#define CEXPMULT_HPP
#include "../../interfaces/iExpression.hpp"

/*
*   Expression "*" CLASS
*/
class ExpMult: public Expression {
    public:
        ExpMult(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif