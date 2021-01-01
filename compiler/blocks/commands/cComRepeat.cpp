#include "cComRepeat.hpp"

ComRepeat::ComRepeat(vector<Command*>* cmds, Condition* cond) {
    this->commands = cmds;
    this->condition = cond;
}

string ComRepeat::getCode() {
    return "";
}