#include "cVariable.hpp"

Variable::Variable(string pid) {
    this->pid = pid;
}

Variable::Variable(string pid_ext, string pid_int) {
    this->pid_ext = pid_ext;
    this->pid_int = pid_int;
}

Variable::Variable(string pid, ull index) {
    this->pid = pid;
    this->index = index;
}

std::string Variable::getCode() {
    return "";
}
