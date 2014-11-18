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
"if" {return IF;}

"while" {return WHILE;}
{letter}({letter}|{digit})* { strcpy(yylval.ICG.label, yytext); return ID;}
"==" {return EQ;}
","|";"|"="|"+"|"-"|"*"|"/"|"("|")"|"{"|"}"|"<" {return yytext[0];}

\n
%%