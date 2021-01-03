#include "cComAssign.hpp"

ComAssign::ComAssign(Identifier* id, Expression* exp) {
    this->ident = id;
    this->expression = exp;
}

string ComAssign::getCode() {
    return "";
}