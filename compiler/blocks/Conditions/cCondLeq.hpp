#ifndef CCONDLEQ_HPP
#define CCONDLEQ_HPP
#include "../../interfaces/iCondition.hpp"
#include <string>

/*
*   Condition "<=" CLASS
*/
class CondLeq: public Condition {
    public:
        CondLeq(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif