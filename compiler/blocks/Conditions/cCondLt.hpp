#ifndef CCONDLT_HPP
#define CCONDLT_HPP
#include "../../interfaces/iCondition.hpp"
#include <string>

/*
*   Condition "<" CLASS
*/
class CondLt: public Condition {
    public:
        CondLt(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif