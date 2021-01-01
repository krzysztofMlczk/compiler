#include "cComIfElse.hpp"

ComIfElse::ComIfElse(Condition* cond, vector<Command*>* cmds1, vector<Command*>* cmds2) {
    this->condition = cond;
    this->cmds_when_true = cmds1;
    this->cmds_when_false = cmds2;
}

string ComIfElse::getCode() {
    return "";
}