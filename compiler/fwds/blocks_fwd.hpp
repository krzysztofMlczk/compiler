/*
* ===============================
*              BLOCK
*           INTERFACES
* ===============================
*/
#include "../interfaces/iCodeBlock.hpp"
#include "../interfaces/iCommand.hpp"
#include "../interfaces/iCondition.hpp"
#include "../interfaces/iExpression.hpp"
#include "../interfaces/iValue.hpp"
#include "../interfaces/iIdentifier.hpp"

/*
* ===============================
*              BLOCK
*             CLASSES
* ===============================
*/
#include "../blocks/identifiers/cIdentifierSingle.hpp"
#include "../blocks/identifiers/cIdentifierArrSingle.hpp"
#include "../blocks/identifiers/cIdentifierArrNum.hpp"

#include "../blocks/values/cConstant.hpp"
#include "../blocks/values/cVariableValue.hpp"

#include "../blocks/expressions/cExpAdd.hpp"
#include "../blocks/expressions/cExpAsVal.hpp"
#include "../blocks/expressions/cExpDiv.hpp"
#include "../blocks/expressions/cExpMod.hpp"
#include "../blocks/expressions/cExpMult.hpp"
#include "../blocks/expressions/cExpSub.hpp"

#include "../blocks/conditions/cCondEq.hpp"
#include "../blocks/conditions/cCondGeq.hpp"
#include "../blocks/conditions/cCondGt.hpp"
#include "../blocks/conditions/cCondLeq.hpp"
#include "../blocks/conditions/cCondLt.hpp"
#include "../blocks/conditions/cCondNeq.hpp"

#include "../blocks/commands/cComAssign.hpp"
#include "../blocks/commands/cComFor.hpp"
#include "../blocks/commands/cComForDownto.hpp"
#include "../blocks/commands/cComIf.hpp"
#include "../blocks/commands/cComIfElse.hpp"
#include "../blocks/commands/cComRead.hpp"
#include "../blocks/commands/cComRepeat.hpp"
#include "../blocks/commands/cComWhile.hpp"
#include "../blocks/commands/cComWrite.hpp"

