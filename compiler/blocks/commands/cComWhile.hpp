#ifndef CCOMWHILE_HPP
#define CCOMWHILE_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iCondition.hpp"
#include <string>
#include <vector>

/*
*   While command CLASS
*/
class ComWhile: public Command {
    public:
        Condition* condition;
        vector<Command*>* commands;
        ComWhile(Condition* cond, vector<Command*>* cmds);
        virtual string getCode();
};

#endif