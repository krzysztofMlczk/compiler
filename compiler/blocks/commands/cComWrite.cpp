#include "cComWrite.hpp"

ComWrite::ComWrite(Value* val) {
    if (val->is_variable) {
        this->val_var = (VariableValue*) val;
        this->val_const = nullptr;
    } else {
        this->val_var = nullptr;
        this->val_const = (Constant*) val;
    }
}

vector<string> ComWrite::getCode(SymbolTable* symbolTable) {
    vector<string> code;
    vector<string> occupied_registers{"a"};

    if (this->val_var) {
        // do the following if value to print is instance of VariableValue

        // assign out_reg for condition
        this->val_var->ident->outcome_reg = "a";
        // if ident requires clobbers, then assign them
        this->val_var->ident->clobbers = this->getClobbers(&occupied_registers, this->val_var->ident->clobber_counter);
        code = this->val_var->ident->getCode(symbolTable);

    } else if (this->val_const){
        // do the following if value to print is instance of Constant
        Symbol* new_symbol = new Symbol(to_string(val_const->value), symbolTable->mem_offset);
        // we have to declare new variable in symbol table
        symbolTable->addSymbol(new_symbol);

        Identifier* ident = new IdentifierSingle(to_string(val_const->value));
        Expression* exp = new ExpAsVal(this->val_const);

        // after doig this operation in register "a" there will be address
        // to memory cell where val_const.value is placed so we can simply use PUT
        ComAssign* com_assign = new ComAssign(ident, exp);
        code = com_assign->getCode(symbolTable);

        // remove new symbol from symbol table (we won't need it anymore)
        symbolTable->rmSymbol(new_symbol);
    }

    code.push_back("PUT a");

    return code;

    // UWAGA: tutaj potrzebuje w rejestrze otrzymac gdzie w pamieci znajduje sie dana wartosc
    // bo PUT x wypisze na ekran P[rx] - czyli w x musi się znajdować adres!!!

    // Jeśli value jest VariableValue, to ma pole ident => robiąc varVal.ident.getCode(), to dostaniemy w ident.outcome_reg adres varVal
    // Jeśli value jest Constant, to musimy wygenerować tą stałą, a następnie umieścić ją w pamięci, żeby móc ją wyświetlić!
}