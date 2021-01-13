#ifndef CCOMASSIGN_HPP
#define CCOMASSIGN_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iExpression.hpp"
#include "../../interfaces/iIdentifier.hpp"

/*
*   Assign command CLASS
*/
class ComAssign: public Command {
    public:
        Identifier* ident;
        Expression* expression;
        ComAssign(Identifier* id, Expression* exp);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif