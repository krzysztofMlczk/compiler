#ifndef CEXPASVAL_HPP
#define CEXPASVAL_HPP
#include "../../interfaces/iExpression.hpp"

/*
*   Expression as "value" CLASS
*/
class ExpAsVal: public Expression {
    public:
        ExpAsVal(Value* v1);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif