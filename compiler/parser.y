%{
  #include <iostream>
  #include <string>

  // #include "Paraphraser.h"

  extern int yylex();
  extern int yylineno;
  extern FILE* yyin;

  // Paraphraser paraphraser;

  void yyerror (const char *str);

  using namespace std;
%}

%union {
  unsigned long long numberVal;
  const char* stringVal;
}

%type<numberVal> NUMBER
%type<stringVal> PIDENTIFIER

/* TOKENS */
%token DECLARE
%token BEGIN_T
%token END
%token IF
%token THEN
%token ELSE
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token REPEAT
%token UNTIL
%token FOR
%token FROM
%token TO
%token ENDFOR
%token DOWNTO
%token READ
%token WRITE

%token NEQ
%token LEQ
%token GEQ
%token ASSIGN

%token NUMBER
%token PIDENTIFIER

%% /* The grammar follows. */

program:
   DECLARE declarations BEGIN_T commands END
 | BEGIN_T commands END
 ;

declarations:
  declarations ',' PIDENTIFIER
| declarations ',' PIDENTIFIER '(' NUMBER ':' NUMBER ')'
| PIDENTIFIER
| PIDENTIFIER '(' NUMBER ':' NUMBER ')'
;

commands:
  commands command
| command
;

command:
  identifier ASSIGN expression ';'
| IF condition THEN commands ELSE commands ENDIF
| IF condition THEN commands ENDIF
| WHILE condition DO commands ENDWHILE
| REPEAT commands UNTIL condition ';'
| FOR PIDENTIFIER FROM value TO value DO commands ENDFOR
| FOR PIDENTIFIER FROM value DOWNTO value DO commands ENDFOR
| READ identifier ';'
| WRITE value ';'
;

expression:
  value
| value '+' value
| value '-' value
| value '*' value
| value '/' value
| value '%' value
;

condition:
  value '=' value
| value NEQ value
| value '<' value
| value '>' value
| value LEQ value
| value GEQ value
;

value:
  NUMBER
| identifier
;

identifier:
  PIDENTIFIER
| PIDENTIFIER '(' PIDENTIFIER ')'
| PIDENTIFIER '(' NUMBER ')'
;

%%

int main(int argc, char** argv){

  // skip program name from given params
  argc--;
  argv++;

  if (argc != 2){
    printf("Invalid amount of parameters\n");
    printf("Program usage: \n");
    printf("compiler <input file> <output file>\n");

    return 0;
  }

  FILE* input_file = fopen(argv[0], "r");

  if (input_file == NULL){
    printf("Unable to open file: %s\n", argv[0]);

    return 0;
  }

  yyin = input_file;

  if(yyparse() != 0) {
    fclose(input_file);
    printf("Parsing failed\n");

    return 0;
  }

  fclose(input_file);

  return 0;
}


void yyerror (char const *err_msg)
{
  printf("Parsing error at line %d: %s\n", yylineno, err_msg);
}