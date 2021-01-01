#include "cComForDownto.hpp"

ComForDownto::ComForDownto(Value* from, Value* downto, vector<Command*>* cmds) {
    this->from = from;
    this->downto = downto;
    this->commands = cmds;
}

string ComForDownto::getCode() {
    return "";
}