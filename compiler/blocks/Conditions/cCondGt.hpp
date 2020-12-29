#ifndef CCONDGT_HPP
#define CCONDGT_HPP
#include "../../interfaces/iCondition.hpp"
#include <string>

/*
*   Condition ">" CLASS
*/
class CondGt: public Condition {
    public:
        CondGt(Value* v1, Value* v2);
        string getCode();
    protected:
    private:
};

#endif