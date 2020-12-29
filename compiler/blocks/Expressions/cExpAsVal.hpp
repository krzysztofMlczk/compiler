#ifndef CEXPASVAL_HPP
#define CEXPASVAL_HPP
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Expression as "value" CLASS
*/
class ExpAsVal: public Expression {
    public:
        ExpAsVal(Value* v1);
        string getCode();
    protected:
    private:
};

#endif