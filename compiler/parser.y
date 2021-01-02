%{
  #include <iostream>
  #include <string>
  #include <vector>
  #include "code_generator/cCodeGenerator.hpp"
  #include "io_handler/cIoHandler.hpp"

  extern int yylex();
  extern int yylineno;
  extern FILE* yyin;
  CodeGenerator cg;
  vector<string> code;


  void yyerror (const char *str);

  using namespace std;
%}

%code requires {
  #include <vector>
  #include "fwds/blocks_fwd.hpp"
}

%union {
  unsigned long long numberVal;
  const char* stringVal;
  Identifier* ident;
  Value* val;
  Condition* cond;
  Expression* exp;
  Command* cmd;
  vector<Command*>* cmds;
}

%type<numberVal> NUMBER
%type<stringVal> PIDENTIFIER

%type<ident> identifier
%type<val> value
%type<cond> condition
%type<exp> expression
%type<cmd> command
%type<cmds> commands

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
   DECLARE declarations BEGIN_T commands END                  { code = cg.generateCode($4); }
 | BEGIN_T commands END                                       { code = cg.generateCode($2); }                                                            
 ;

declarations:
  declarations ',' PIDENTIFIER                                { cg.addSymbol($3);           }
| declarations ',' PIDENTIFIER '(' NUMBER ':' NUMBER ')'      { cg.addSymbol($3, $5, $7);   }
| PIDENTIFIER                                                 { cg.addSymbol($1);           }
| PIDENTIFIER '(' NUMBER ':' NUMBER ')'                       { cg.addSymbol($1, $3, $5);   }
;

commands:
  commands command                                            { 
                                                                $1->push_back($2);
                                                                $$ = $1;
                                                              }
| command                                                     { 
                                                                vector<Command*>* v = new vector<Command*>;
                                                                v->push_back($1);
                                                                $$ = v;
                                                              }
;

command:
  identifier ASSIGN expression ';'                            { $$ = new ComAssign($1, $3);         }
| IF condition THEN commands ELSE commands ENDIF              { $$ = new ComIfElse($2, $4, $6);     }
| IF condition THEN commands ENDIF                            { $$ = new ComIf($2, $4);             }
| WHILE condition DO commands ENDWHILE                        { $$ = new ComWhile($2, $4);          }
| REPEAT commands UNTIL condition ';'                         { $$ = new ComRepeat($2, $4);         }
| FOR PIDENTIFIER FROM value TO value DO commands ENDFOR      { $$ = new ComFor($4, $6, $8);        }
| FOR PIDENTIFIER FROM value DOWNTO value DO commands ENDFOR  { $$ = new ComForDownto($4, $6, $8);  }
| READ identifier ';'                                         { $$ = new ComRead($2);               }
| WRITE value ';'                                             { $$ = new ComWrite($2);              }
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
| identifier                        { $$ = new VariableValue($1); }
;

identifier:
  PIDENTIFIER                       { $$ = new IdentifierSingle(std::string($1));                     }
| PIDENTIFIER '(' PIDENTIFIER ')'   { $$ = new IdentifierArrSingle(std::string($1), std::string($3)); }
| PIDENTIFIER '(' NUMBER ')'        { $$ = new IdentifierArrNum(std::string($1), $3);                 }
;

%%

int main(int argc, char** argv){

  IOhandler io_handler(argc, argv);

  try {

    yyin = io_handler.read_code();

  } catch (const exception& e) {

    cerr << e.what() << endl;
    return 0;
  }

  if(yyparse() != 0) {
    io_handler.close_input_file();
    cerr << "Parsing failed!" << endl;
    return 0;
  }

  return 0;
}

void yyerror (char const *err_msg)
{
  printf("Parsing error at line %d: %s\n", yylineno, err_msg);
}