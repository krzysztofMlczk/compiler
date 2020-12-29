#ifndef CEXPADD_HPP
#define CEXPADD_HPP
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Expression "+" CLASS
*/
class ExpAdd: public Expression {
    public:
        ExpAdd(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif