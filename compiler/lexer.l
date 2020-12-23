%option noyywrap
%option yylineno

%{
    #include "parser.tab.h" /* import tokens from bison file */
    #include <cstring>

%}

PIDENTIFIER [_a-z]+
NUMBER [0-9]+
NEQ !=
LEQ <=
GEQ >=
ASSIGN :=
COMMENT_START \[
COMMENT_END \]

%x COMMENT

%%

{COMMENT_START} { BEGIN(COMMENT); }
<COMMENT>{
    [^\]]           ; /* ignore every character except escaped "]" */
    {COMMENT_END}   BEGIN(INITIAL);
}

\n              ;
\r              ;
[ \t]           ;
{PIDENTIFIER}   { yylval.stringVal = strdup(yytext); return PIDENTIFIER;    }
{NUMBER}        { yylval.numberVal = atoll(yytext); return NUMBER;          }
DECLARE         { return DECLARE;   }
BEGIN           { return BEGIN_T;   }
END             { return END;       }
IF              { return IF;        }
THEN            { return THEN;      }
ELSE            { return ELSE;      }
ENDIF           { return ENDIF;     }
WHILE           { return WHILE;     }
DO              { return DO;        }
ENDWHILE        { return ENDWHILE;  }
REPEAT          { return REPEAT;    }
UNTIL           { return UNTIL;     }
FOR             { return FOR;       }
FROM            { return FROM;      }
TO              { return TO;        }
ENDFOR          { return ENDFOR;    }
DOWNTO          { return DOWNTO;    }
READ            { return READ;      }
WRITE           { return WRITE;     }
{NEQ}           { return NEQ;       }
{LEQ}           { return LEQ;       }
{GEQ}           { return GEQ;       }
{ASSIGN}        { return ASSIGN;    }
.               { return yytext[0]; } /* Any other indicates an Error */
%%