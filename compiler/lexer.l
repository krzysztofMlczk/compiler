%option noyywrap
%option yylineno

%{
    #include <string>

    #define TOKEN(token) (yylval.token = token)
%}

PIDENTIFIER [_a-z]+
NUMBER [0-9]+
NEQ !=
LEQ <=
GEQ >=
ASSIGN :=
COMMENT_START \[
COMMENT_END \]
OTHER [^\,\(\)\:\;\+\-\*\/\%\=\<\>]
/* , | ( | ) | : | ; | + | - | * | / | % | = | < | > those will be passed to the parser by default rule */

%x COMMENT

%%

{COMMENT_START} { BEGIN(COMMENT); }
<COMMENT>{
    [^\]]   ; /* ignore every character except escaped "]" */
    {COMMENT_END}   BEGIN(INITIAL);
}

\n              ;
\r              ;
[ \t]           ;
{PIDENTIFIER}   { yylval.stringVal = new std::string(yytext, yyleng); return PIDENTIFIER; }
{NUMBER}        { yylval.numberVal = atoll(yytext); return NUMBER; }
DECLARE         { return TOKEN(DECLARE);    }
BEGIN           { return TOKEN(BEGIN);      }
END             { return TOKEN(END);        }
IF              { return TOKEN(IF);         }
THEN            { return TOKEN(THEN);       }
ELSE            { return TOKEN(ELSE);       }
ENDIF           { return TOKEN(ENDIF);      }
WHILE           { return TOKEN(WHILE);      }
DO              { return TOKEN(DO);         }
ENDWHILE        { return TOKEN(ENDWHILE);   }
REPEAT          { return TOKEN(REPEAT);     }
UNTIL           { return TOKEN(UNTIL);      }
FOR             { return TOKEN(FOR);        }
FROM            { return TOKEN(FROM);       }
TO              { return TOKEN(TO);         }
ENDFOR          { return TOKEN(ENDFOR);     }
DOWNTO          { return TOKEN(DOWNTO);     }
READ            { return TOKEN(READ);       }
WRITE           { return TOKEN(WRITE);      }
{NEQ}           { return TOKEN(NEQ);        }
{LEQ}           { return TOKEN(LEQ);        }
{GEQ}           { return TOKEN(GEQ);        }
{ASSIGN}        { return TOKEN(ASSIGN);     }
{OTHER}         { return TOKEN(ERROR);  }/* Any other besides: , | ( | ) | : | ; | + | - | * | / | % | = | < | > indicates an error*/
%%