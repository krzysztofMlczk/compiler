#ifndef CCOMFOR_HPP
#define CCOMFOR_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>
#include <vector>

/*
*   For command CLASS
*/
class ComFor: public Command {
    public:
        Value* from;
        Value* to;
        vector<Command*> commands;
        ComFor(Value* from, Value* to, vector<Command*> cmds);
        virtual string getCode();
};

#endif