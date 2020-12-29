#ifndef CEXPMULT_HPP
#define CEXPMULT_HPP
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Expression "*" CLASS
*/
class ExpMult: public Expression {
    public:
        ExpMult(Value* v1, Value* v2);
        virtual string getCode();
    protected:
    private:
};

#endif