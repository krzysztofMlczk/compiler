#include "cComAssign.hpp"

ComAssign::ComAssign(Value* id, Expression* exp) {
    this->ident = id;
    this->expression = exp;
}

string ComAssign::getCode() {
    return "";
}