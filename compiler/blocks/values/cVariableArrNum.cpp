#include "cVariableArrNum.hpp"

VariableArrNum::VariableArrNum(string pid_ext, ull index) {
    this->pid_ext = pid_ext;
    this->index = index;
}

string VariableArrNum::getCode() {
    return "";
}