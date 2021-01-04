#ifndef CEXPSUB_HPP
#define CEXPSUB_HPP
#include "../../interfaces/iExpression.hpp"

/*
*   Expression "-" CLASS
*/
class ExpSub: public Expression {
    public:
        const ull clobber_counter = 1;
        ExpSub(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif