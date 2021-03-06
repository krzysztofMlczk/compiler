#include "cIdentifierArrSingle.hpp"

IdentifierArrSingle::IdentifierArrSingle(string pid_ext, string pid_int, int line):Identifier(pid_ext, line) {
    this->pid_int = pid_int;
    this->check_init = false;
    this->clobber_counter = 1;
}

vector<string> IdentifierArrSingle::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // this type of identifier needs additional clobber, so get it from register manager
    this->clobbers = regManager->getClobbers(this->clobber_counter);

    IdentifierSingle id(this->pid_int, this->line);
    VariableValue varVal(&id);
    varVal.outcome_reg = this->clobbers.at(0);
    code = varVal.getCode(symbolTable, regManager);

    Symbol* sym = symbolTable->getArrVar(this->pid, this->line);
    ull offset = sym->offset;
    ull start = sym->array_start;

    Constant const_start(start);
    const_start.outcome_reg = this->outcome_reg;
    vector<string> code1 = const_start.getCode(symbolTable, regManager);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());
    // append SUB instruction
    code.push_back("SUB " + this->clobbers.at(0) + " " + this->outcome_reg);


    Constant const_arrOffset(offset);
    const_arrOffset.outcome_reg = this->outcome_reg;
    vector<string> code2 = const_arrOffset.getCode(symbolTable, regManager);

    // append code2 to code
    code.insert(code.end(), code2.begin(), code2.end());
    // append ADD instruction
    code.push_back("ADD " + this->outcome_reg + " " + this->clobbers.at(0));

    return code;
}