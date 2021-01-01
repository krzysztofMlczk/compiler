#ifndef CCOMIF_HPP
#define CCOMIF_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iCondition.hpp"
#include <string>
#include <vector>

/*
*   If command CLASS
*/
class ComIf: public Command {
    public:
        Condition* condition;
        vector<Command*> commands;
        ComIf(Condition* cond, vector<Command*> cmds);
        virtual string getCode();
};

#endif