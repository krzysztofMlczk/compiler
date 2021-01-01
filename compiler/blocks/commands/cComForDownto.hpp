#ifndef CCOMFORDOWNTO_HPP
#define CCOMFORDOWNTO_HPP
#include "../../interfaces/iCommand.hpp"
#include <string>
#include <vector>

/*
*   For Downto command CLASS
*/
class ComForDownto: public Command {
    public:
        Value* from;
        Value* downto;
        vector<Command*> commands;
        ComForDownto(Value* from, Value* downto, vector<Command*> cmds);
        virtual string getCode();
};

#endif