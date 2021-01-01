%{
  #include <iostream>
  #include <string>

  extern int yylex();
  extern int yylineno;
  extern FILE* yyin;

  void yyerror (const char *str);

  using namespace std;
%}

%code requires {
  #include <vector>
  #include "blocks_fwd.hpp"
}

%union {
  unsigned long long numberVal;
  const char* stringVal;
  Value* val;
  Condition* cond;
  Expression* exp;
  Command* com;
}

%type<numberVal> NUMBER
%type<stringVal> PIDENTIFIER

%type<val> identifier
%type<val> value
%type<cond> condition
%type<exp> expression
%type<com> command

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
  value                             { $$ = new ExpAsVal($1);      }
| value '+' value                   { $$ = new ExpAdd($1, $3);    }
| value '-' value                   { $$ = new ExpSub($1, $3);    }     
| value '*' value                   { $$ = new ExpMult($1, $3);   }
| value '/' value                   { $$ = new ExpDiv($1, $3);    }
| value '%' value                   { $$ = new ExpMod($1, $3);    }
;

condition:
  value '=' value                   { $$ = new CondEq($1, $3);    }
| value NEQ value                   { $$ = new CondNeq($1, $3);   }
| value '<' value                   { $$ = new CondLt($1, $3);    }
| value '>' value                   { $$ = new CondGt($1, $3);    }
| value LEQ value                   { $$ = new CondLeq($1, $3);   }
| value GEQ value                   { $$ = new CondGeq($1, $3);   }
;

value:                
  NUMBER                            { $$ = new Constant($1);      }
| identifier                        { $$ = $1;                    }
;

identifier:
  PIDENTIFIER                       { $$ = new Variable(std::string($1));                   }
| PIDENTIFIER '(' PIDENTIFIER ')'   { $$ = new Variable(std::string($1), std::string($3));  }
| PIDENTIFIER '(' NUMBER ')'        { $$ = new Variable(std::string($1), $3);               }
;

%%

int main(int argc, char** argv){

  // skip program name from given params
  argc--;
  argv++;

  if (argc != 2){
    printf("Invalid amount of parameters\n");
    printf("Program usage: \n");
    printf("kompilator <input file> <output file>\n");

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