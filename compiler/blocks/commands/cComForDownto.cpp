#include "cComForDownto.hpp"

ComForDownto::ComForDownto(string pid, Value* from, Value* downto, vector<Command*>* cmds) {
    this->iter_name = pid;
    this->from = from;
    this->downto = downto;
    this->commands = cmds;
}

vector<string> ComForDownto::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // create symbol for iterator
    Symbol* iterator = new Symbol(this->iter_name, symbolTable->mem_offset);
    // add iterator to symbol table
    symbolTable->addSymbol(iterator);

    IdentifierSingle iter_ident(this->iter_name);
    symbolTable->initialize(iter_ident.pid); // we have to initialize iterator
    // set register where address of iterator will appear
    // this ident doesn't need clobbers because it is single
    iter_ident.outcome_reg = "a";
    // this code puts addres of iterator in register a
    vector<string> get_iter_address = iter_ident.getCode(symbolTable, regManager); 

    // create VariableValue object for iterator, so we can easily get current iterator value in specific register
    VariableValue iter_value(&iter_ident);
    iter_value.outcome_reg = "b";
    // this code puts value of the iterator in register b
    vector<string> get_iter_value = iter_value.getCode(symbolTable, regManager);

    // set register where iterator starting value will appear
    this->from->outcome_reg = "b";
    // make register b occupied
    regManager->occupy("b");
    // this code puts starting iterator value in register b
    vector<string> get_iter_starting_val = this->from->getCode(symbolTable, regManager);

    // set register where ending iterator value will appear
    this->downto->outcome_reg = "c";
    // make register a occupied
    regManager->occupy("c");
    vector<string> get_iter_ending_val = this->downto->getCode(symbolTable, regManager);

    // free b and c
    regManager->free("b");
    regManager->free("c");

    int get_iter_ending_val_len = get_iter_ending_val.size();
    int get_iter_value_len = get_iter_value.size();
    int get_iter_address_len = get_iter_address.size();
    int commands_len = this->count_instructions(this->commands, symbolTable, regManager);
    int start = 1 + 1 + 1 + get_iter_value_len + get_iter_address_len + commands_len + 1 + 1 + 1 + get_iter_ending_val_len;
    int end = commands_len + get_iter_address_len + get_iter_value_len + 1 + 1 + 1 + 1 + 1;


    // code structure

    // put iter address in reg a
    code.insert(code.end(), get_iter_address.begin(), get_iter_address.end());

    // put iter starting value in reg b
    code.insert(code.end(), get_iter_starting_val.begin(), get_iter_starting_val.end());

    // store starting value of iterator
    code.push_back("STORE b a");

    // this will be done before each iteration
    // put iter ending value in reg c
    code.insert(code.end(), get_iter_ending_val.begin(), get_iter_ending_val.end());

    // perform:  iterator_ending_value - current_iterator_value
    code.push_back("SUB c b");
    // if we get 0 in c, then current_iterator_value => iterator_ending_value
    // so we execute code from commands
    code.push_back("JZERO c 2");

    // otherwise end the loop
    code.push_back("JUMP " + to_string(end));

    // commands inside loop
    this->concat(&code, this->commands, symbolTable, regManager);

    // end of each loop
    // put iter addres in reg a
    code.insert(code.end(), get_iter_address.begin(), get_iter_address.end());

    // put iter value in reg b
    code.insert(code.end(), get_iter_value.begin(), get_iter_value.end());

    // check if iterator is already 0
    code.push_back("JZERO b 4");

    // decrement iterator
    code.push_back("DEC b");

    // save decremented value of iterator
    code.push_back("STORE b a");
    
    // go to start of the loop to check if loop should still go
    code.push_back("JUMP -" + to_string(start));

    symbolTable->rmSymbol(iterator); // delete iterator from symbol table

    return code;
}