#include "cComFor.hpp"

ComFor::ComFor(string pid, Value* from, Value* to, vector<Command*>* cmds) {
    this->iter_name = pid;
    this->from = from;
    this-> to = to;
    this->commands = cmds;
}

vector<string> ComFor::getCode(SymbolTable* symbolTable) {
    vector<string> code;

    // create symbol for iterator
    Symbol* iterator = new Symbol(this->iter_name, symbolTable->mem_offset);
    // add iterator to symbol table
    symbolTable->addSymbol(iterator);

    Identifier* iter_ident = new IdentifierSingle(this->iter_name);
    // set register where address of iterator will appear
    // this ident doesn't need clobbers because it is single
    iter_ident->outcome_reg = "a";
    // this code puts addres of iterator in register a
    vector<string> get_iter_address = iter_ident->getCode(symbolTable); 

    // create VariableValue object for iterator, so we can easily get current iterator value in specific register
    Value* iter_value = new VariableValue(iter_ident);
    iter_value->outcome_reg = "b";
    // this code puts value of the iterator in register b
    vector<string> get_iter_value = iter_value->getCode(symbolTable);

    // set register where iterator starting value will appear
    this->from->outcome_reg = "b";
    // this code puts starting iterator value in register b
    vector<string> get_iter_starting_val = this->from->getCode(symbolTable);

    // set register where ending iterator value will appear
    this->to->outcome_reg = "c";
    vector<string> get_iter_ending_val = this->to->getCode(symbolTable);


    int get_iter_ending_val = get_iter_ending_val.size();
    int get_iter_value_len = get_iter_value.size();
    int get_iter_address_len = get_iter_address.size();
    int commands_len = this->commands->size();
    int start = 1 + 1 + get_iter_value_len + get_iter_address_len + commands_len + 1 + 1 + 1;
    int end = commands_len + get_iter_address_len + get_iter_value_len + 1 + 1 + 1 + 1;


    // code structure

    // put iter addres in reg a
    code.insert(code.end(), get_iter_address.begin(), get_iter_address.end());

    // put iter starting value in reg b
    code.insert(code.end(), get_iter_starting_val.begin(), get_iter_starting_val.end());

    // store starting value of iterator
    code.push_back("STORE b a");

    // put iter ending value in reg c
    code.insert(code.end(), get_iter_ending_val.begin(), get_iter_ending_val.end());

    // this will be done before each iteration
    // perform: current_iterator_value - iterator_ending_value
    code.push_back("SUB b c");
    // if we get 0 in b, then current_iterator_value <= iterator_ending_value
    // so we execute code from commands
    code.push_back("JZERO b 2");

    // otherwise end the loop
    code.push_back("JUMP " + to_string(end));

    // commands inside loop
    code.insert(code.end(), this->commands->begin(), this->commands->end());

    // end of each loop
    // put iter addres in reg a
    code.insert(code.end(), get_iter_address.begin(), get_iter_address.end());

    // put iter value in reg b
    code.insert(code.end(), get_iter_value.begin(), get_iter_value.end());

    // increment iterator
    code.push_back("INC b");

    // save incremented value of iterator
    code.push_back("STORE b a");
    
    // go to start of the loop to check if loop should still go
    code.push_back("JUMP -" + to_string(start));

    symbolTable->rmSymbol(iterator); // delete iterator from symbol table

    return code;
}