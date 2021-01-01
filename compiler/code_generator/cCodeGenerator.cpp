#include "cCodeGenerator.hpp"

CodeGenerator::CodeGenerator() {

}

void CodeGenerator::addSymbol(const char* pid, ull num1, ull num2) {
    Symbol* new_symbol = new Symbol(std::string(pid), this->mem_offset, num1, num2);
    this->symbolTable.addSymbol(new_symbol);
}

void CodeGenerator::addSymbol(const char* pid) {
    Symbol* new_symbol = new Symbol(std::string(pid), this->mem_offset);
    this->symbolTable.addSymbol(new_symbol);
}