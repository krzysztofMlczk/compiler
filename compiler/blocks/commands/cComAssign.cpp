#include "cComAssign.hpp"

ComAssign::ComAssign(Identifier* id, Expression* exp) {
    this->ident = id;
    this->expression = exp;
}

vector<string> ComAssign::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    // reserve two registers (for ident and for expression)
    vector<string> occupied_registers{"a", "b"};

    // assign out_reg for ident
    this->ident->outcome_reg = "a";
    // if ident requires clobbers, then assign them
    this->ident->clobbers = this->getClobbers(&occupied_registers, this->ident->clobber_counter);
    code = this->ident->getCode(symbolTable);

    // assign out_reg for expression
    this->expression->outcome_reg = "b";
    // if expression requires clobbers, then assign them
    this->expression->clobbers = this->getClobbers(&occupied_registers, this->expression->clobber_counter);
    vector<string> code1 = this->expression->getCode(symbolTable);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("STORE b a");

    return code;
}