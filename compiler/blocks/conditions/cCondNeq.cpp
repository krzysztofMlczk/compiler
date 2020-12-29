#include "cCondNeq.hpp"

CondNeq::CondNeq(Value* val1, Value* val2):Condition(val1, val2) {
    
}

string CondNeq::getCode() {
    return "";
}