all: compiler

parser.tab.h parser.tab.c: parser.y
	bison -v -d -t parser.y

lex.yy.c: lexer.l
	flex lexer.l

compiler: parser.tab.h parser.tab.c lex.yy.c
	g++ -std=c++11 parser.tab.c lex.yy.c -o compiler

clean:
	rm -f compiler parser.tab.h parser.tab.c lex.yy.c parser.output