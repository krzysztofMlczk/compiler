#include "cComFor.hpp"

ComFor::ComFor(string pid, Value* from, Value* to, vector<Command*>* cmds) {
    this->iter_name = pid;
    this->from = from;
    this-> to = to;
    this->commands = cmds;
}

vector<string> ComFor::getCode(SymbolTable* symbolTable, RegManager* regManager) {
    vector<string> code;

    // set register where "from" value will appear
    this->from->outcome_reg = "b";
    // make register b occupied
    regManager->occupy("b");
    // this code puts starting iterator value in register b
    vector<string> get_from_val = this->from->getCode(symbolTable, regManager);

    // set register where "to" value will appear
    this->to->outcome_reg = "c";
    // make register a occupied
    regManager->occupy("c");
    vector<string> get_to_val = this->to->getCode(symbolTable, regManager);

    // free b and c
    regManager->free("b");
    regManager->free("c");

    // *******************************************************************************************************************************

    // create symbol for iterator (holds current value of iterator)
    Symbol* iterator = new Symbol(this->iter_name, symbolTable->mem_offset);
    iterator->is_iterator = true;
    // add iterator to symbol table
    symbolTable->addSymbol(iterator);

    IdentifierSingle iter_ident(this->iter_name);
    symbolTable->initialize(iter_ident.pid); // we have to initialize iterator
    // set register where address of iterator will appear
    // this ident doesn't need clobbers, so we dont have to lock this register because it is single
    iter_ident.outcome_reg = "a";
    // this code puts address of iterator in register a
    vector<string> get_iter_address = iter_ident.getCode(symbolTable, regManager);

    // create VariableValue object for iterator, so we can easily get current iterator value in specific register
    VariableValue iter_value(&iter_ident);
    iter_value.outcome_reg = "b";
    // this code puts value of the iterator in register b
    vector<string> get_iter_value = iter_value.getCode(symbolTable, regManager);

    // *******************************************************************************************************************************

    //create symbol for !iterator (holds ending value of iterator)
    Symbol* _iterator = new Symbol("!" + this->iter_name, symbolTable->mem_offset);
    // add !iterator to symbol table
    symbolTable->addSymbol(_iterator);

    IdentifierSingle end_iter_ident("!" + this->iter_name);
    //make initialized so symbolTable doesn't throw error when performing getCode()
    symbolTable->initialize(end_iter_ident.pid); 
    end_iter_ident.outcome_reg = "a";
    // this code puts address of !iterator in register a
    vector<string> get_end_iter_address = end_iter_ident.getCode(symbolTable, regManager);

    // create VariableValue object for !iterator, so we can easily get iterator ending value in specific register
    VariableValue end_iter_value(&end_iter_ident);
    end_iter_value.outcome_reg = "c";
    // this code puts ending value of iterator in register c
    vector<string> get_end_iter_value = end_iter_value.getCode(symbolTable, regManager);

    // ********************************************************************************************************************************

    

    // lengths calculations
    int commands_len = this->count_instructions(this->commands, symbolTable, regManager);
    int get_iter_address_len = get_iter_address.size();
    int get_iter_value_len = get_iter_value.size();
    int get_end_iter_value_len = get_end_iter_value.size();
    int end = commands_len + get_iter_address_len + get_iter_value_len + 1 + 1 + get_end_iter_value_len + 1 + 1;
    int start = get_end_iter_value_len + 1 + 1 + get_iter_value_len + get_iter_address_len + commands_len + 1 + 1 + 1;


    // code structure

    // put "from" value in reg b
    code.insert(code.end(), get_from_val.begin(), get_from_val.end());

    // put iterator address in reg a
    code.insert(code.end(), get_iter_address.begin(), get_iter_address.end());

    // store starting value of iterator
    code.push_back("STORE b a");

    // put "to" value in reg c
    code.insert(code.end(), get_to_val.begin(), get_to_val.end());

    // put !iterator address in reg a
    code.insert(code.end(), get_end_iter_address.begin(), get_end_iter_address.end());

    // store ending value of iterator
    code.push_back("STORE c a");

    // this will be done before each iteration
    // perform: current_iterator_value - iterator_ending_value
    code.push_back("SUB b c");
    // if we get 0 in b, then current_iterator_value <= iterator_ending_value
    // so we execute code from commands
    code.push_back("JZERO b 2");

    // otherwise end the loop
    code.push_back("JUMP " + to_string(end));

    // commands inside loop
    this->concat(&code, this->commands, symbolTable, regManager);

    // end of each loop
    // put iterator address in reg a
    code.insert(code.end(), get_iter_address.begin(), get_iter_address.end());

    // put iterator value in reg b
    code.insert(code.end(), get_iter_value.begin(), get_iter_value.end());

    // increment iterator
    code.push_back("INC b");

    // save incremented value of iterator
    code.push_back("STORE b a");

    // put !iterator value in c
    code.insert(code.end(), get_end_iter_value.begin(), get_end_iter_value.end());

    // go to start of the loop to check if loop should still go
    code.push_back("JUMP -" + to_string(start));


    // we won't need these symbols anymore
    symbolTable->rmSymbol(iterator);
    symbolTable->rmSymbol(_iterator);

    return code;
}