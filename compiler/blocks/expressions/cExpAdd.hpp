#ifndef CEXPADD_HPP
#define CEXPADD_HPP
#include "../../interfaces/iExpression.hpp"

/*
*   Expression "+" CLASS
*/
class ExpAdd: public Expression {
    public:
        ExpAdd(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif