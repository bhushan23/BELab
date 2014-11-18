%{
#include <stdio.h>
#include "y.tab.h"
int lineno = 0;
%}
letter [a-zA-Z]
digit [0-9]
blank [ \b\t]
nline [\n]
%%
"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"main" {return MAIN;}
{letter}* {return ID;}
{digit}+ {return CONST;}
","|";"|"="|"+"|"<"|">"|"("|")"|"{"|"}" { return yytext[0];}

{nline} {++lineno;}
{blank} {}
%%


