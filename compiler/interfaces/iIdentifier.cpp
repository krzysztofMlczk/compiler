#include "iIdentifier.hpp"

Identifier::Identifier(string pid, int line) {
    this->pid = pid;
    this->line = line;
}

Identifier::Identifier(string pid) {
    this->pid = pid;
}