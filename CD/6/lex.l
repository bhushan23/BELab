%{
#include <stdio.h>
#include "y.tab.h"
extern int lineno ;
%}


letter [a-zA-Z]
digit [0-9]

%%
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
{letter}({letter}|{digit})* { yylval.SM.label = yytext; return ID;}
","|";"|"="|"+"|"-" {return yytext[0];}
\n {++lineno;}
%%
