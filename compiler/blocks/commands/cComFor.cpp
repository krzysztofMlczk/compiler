#include "cComFor.hpp"

ComFor::ComFor(Value* from, Value* to, vector<Command*>* cmds) {
    this->from = from;
    this-> to = to;
    this->commands = cmds;
}

string ComFor::getCode() {
    return "";
}