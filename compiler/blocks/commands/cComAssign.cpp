#include "cComAssign.hpp"

ComAssign::ComAssign(Identifier* id, Expression* exp) {
    this->ident = id;
    this->expression = exp;
}

vector<string> ComAssign::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    this->ident->outcome_reg = "a";
    code = this->ident->getCode(symbolTable);

    this->expression->outcome_reg = "b";
    vector<string> code1 = this->expression->getCode(symbolTable);

    // append code1 to code
    code.insert(code.end(), code1.begin(), code1.end());

    code.push_back("STORE b a");

    return code;
}