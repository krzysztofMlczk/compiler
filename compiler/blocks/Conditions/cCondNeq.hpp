#ifndef CCONDNEQ_HPP
#define CCONDNEQ_HPP
#include "../../interfaces/iCondition.hpp"
#include <string>

/*
*   Condition "!=" CLASS
*/
class CondNeq: public Condition {
    public:
        CondNeq(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif