#ifndef CCOMASSIGN_HPP
#define CCOMASSIGN_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iExpression.hpp"
#include <string>

/*
*   Assign command CLASS
*/
class ComAssign: public Command {
    public:
        Value* ident;
        Expression* expression;
        ComAssign(Value* id, Expression* exp);
        virtual string getCode();
};

#endif