#ifndef CEXPMOD_HPP
#define CEXPMOD_HPP
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Expression "%" CLASS
*/
class ExpMod: public Expression {
    public:
        ExpMod(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif