#ifndef CEXPSUB_HPP
#define CEXPSUB_HPP
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Expression "-" CLASS
*/
class ExpSub: public Expression {
    public:
        ExpSub(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif