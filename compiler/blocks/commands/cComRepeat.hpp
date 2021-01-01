#ifndef CCOMREPEAT_HPP
#define CCOMAREPEAT_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iCondition.hpp"
#include <string>
#include <vector>

/*
*   Repeat command CLASS
*/
class ComRepeat: public Command {
    public:
        vector<Command*> commands;
        Condition* condition;
        ComRepeat(vector<Command*> cmds, Condition* cond);
        virtual string getCode();
};

#endif