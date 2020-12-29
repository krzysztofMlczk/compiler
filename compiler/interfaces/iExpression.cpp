#include "iExpression.hpp"

Expression::Expression(Value* v1) {
    this->val1 = v1;
}

Expression::Expression(Value* v1, Value* v2) {
    this->val1 = v1;
    this->val2 = v2;
}