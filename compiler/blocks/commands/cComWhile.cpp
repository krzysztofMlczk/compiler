#include "cComWhile.hpp"

ComWhile::ComWhile(Condition* cond, vector<Command*>* cmds) {
    this->condition = cond;
    this-> commands = cmds;
}

string ComWhile::getCode() {
    return "";
}