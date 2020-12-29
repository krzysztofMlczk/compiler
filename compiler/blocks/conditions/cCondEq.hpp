#ifndef CCONDEQ_HPP
#define CCONDEQ_HPP
#include "../../interfaces/iCondition.hpp"
#include <string>

/*
*   Condition "=" CLASS
*/
class CondEq: public Condition {
    public:
        CondEq(Value* v1, Value* v2);
        virtual string getCode();
    protected:
    private:
};

#endif