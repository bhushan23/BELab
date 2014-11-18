%{
#include <stdio.h>
#include <ctype.h>
#include "y.tab.h"
%}

NUM [0-9]+
WHITESPACE \t

%%
{NUM}|({NUM}"."{NUM}) { yylval.d = atof(yytext); return NUM;}
\n {return NL;}
"+"|"-"|"*"|"/"|"^"|"("|")" {return yytext[0];}
"sin" {return SINE;}
"log" {return LOG;}
{WHITESPACE}
%%