all: compiler

parser.tab.h parser.tab.c: parser.y
	bison -v -d -t parser.y

lex.yy.c: lexer.l
	flex lexer.l

compiler: parser.tab.h parser.tab.c lex.yy.c
	g++ -std=c++11 parser.tab.c lex.yy.c \
	./interfaces/iCodeBlock.cpp \
	./interfaces/iCommand.cpp \
	./interfaces/iCondition.cpp \
	./interfaces/iExpression.cpp \
	./interfaces/iValue.cpp \
	./blocks/values/cConstant.cpp \
	./blocks/values/cVariable.cpp \
	./blocks/expressions/cExpAdd.cpp \
	./blocks/expressions/cExpAsVal.cpp \
	./blocks/expressions/cExpDiv.cpp \
	./blocks/expressions/cExpMod.cpp \
	./blocks/expressions/cExpMult.cpp \
	./blocks/expressions/cExpSub.cpp \
	./blocks/conditions/cCondEq.cpp \
	./blocks/conditions/cCondGeq.cpp \
	./blocks/conditions/cCondGt.cpp \
	./blocks/conditions/cCondLeq.cpp \
	./blocks/conditions/cCondLt.cpp \
	./blocks/conditions/cCondNeq.cpp \
	./blocks/commands/cComAssign.cpp \
	./blocks/commands/cComFor.cpp \
	./blocks/commands/cComForDownto.cpp \
	./blocks/commands/cComIf.cpp \
	./blocks/commands/cComIfElse.cpp \
	./blocks/commands/cComRead.cpp \
	./blocks/commands/cComRepeat.cpp \
	./blocks/commands/cComWhile.cpp \
	./blocks/commands/cComWrite.cpp \
	./symbol_table/cSymbolTable.cpp \
	./symbol_table/cSymbol.cpp \
	./code_generator/cCodeGenerator.cpp \
	-o kompilator

clean:
	rm -f kompilator parser.tab.h parser.tab.c lex.yy.c parser.output