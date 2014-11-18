%{
#include <stdio.h>
#include "y.tab.h"
%}


letter [a-zA-Z]
digit [0-9]

%%
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
{letter}({letter}|{digit})* { yylval.label = yytext; return ID;}
","|";" {return yytext[0];}
\n
%%
