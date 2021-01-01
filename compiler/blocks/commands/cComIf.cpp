#include "cComIf.hpp"

ComIf::ComIf(Condition* cond, vector<Command*>* cmds) {
    this->condition = cond;
    this->commands = cmds;
}

string ComIf::getCode() {
    return "";
}