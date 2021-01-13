#ifndef CCOMWRITE_HPP
#define CCOMWRITE_HPP
#include "../../interfaces/iCommand.hpp"
#include "../../interfaces/iExpression.hpp"
#include "../../interfaces/iIdentifier.hpp"
#include "../values/cVariableValue.hpp"
#include "../values/cConstant.hpp"
#include "../identifiers/cIdentifierSingle.hpp"
#include "../expressions/cExpAsVal.hpp"
#include "cComAssign.hpp"

/*
*   Write command CLASS
*/
class ComWrite: public Command {
    public:
        VariableValue* val_var;
        Constant* val_const;

        ComWrite(Value* val);
        virtual vector<string> getCode(SymbolTable* symbolTable, RegManager* regManager);
};

#endif