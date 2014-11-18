%{
#include <stdio.h>
%}
letter [a-zA-Z]
digit [0-9]
blank [ \b\t]
nline [\n]
%%

"if"|"else"|"while"|"int"|"float"|"double" { printf("Keyword detected: %s\n",yytext);}
{letter}({letter}|{digit})* { printf("variable detected: %s\n",yytext);} 
"-"{digit}+|{digit}+ { printf("Integer detected: %s\n",yytext);};
. ;
{nline} ;
%%
main(int agcnt,char **arg){

FILE *fin,*fout;
stdin = fopen(arg[1],"r") ;
stdout = fopen(arg[2],"w");
yylex();
} 

