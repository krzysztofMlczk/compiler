#ifndef CEXPMULT_HPP
#define CEXPMULT_HPP
#include "../../interfaces/iExpression.hpp"

/*
*   Expression "*" CLASS
*/
class ExpMult: public Expression {
    public:
        const ull clobber_counter = 0;
        ExpMult(Value* v1, Value* v2);
        virtual vector<string> getCode(SymbolTable* symbolTable);
};

#endif