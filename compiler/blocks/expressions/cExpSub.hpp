#ifndef CEXPSUB_HPP
#define CEXPSUB_HPP
#include "../../interfaces/iExpression.hpp"

/*
*   Expression "-" CLASS
*/
class ExpSub: public Expression {
    public:
        ExpSub(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif