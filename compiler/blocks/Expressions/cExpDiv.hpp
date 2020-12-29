#ifndef CEXPDIV_HPP
#define CEXPDIV_HPP
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Expression "/" CLASS
*/
class ExpDiv: public Expression {
    public:
        ExpDiv(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif