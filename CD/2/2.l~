%{
#include <stdio.h>
int linen = 0;

%}
letter [a-zA-Z]
digit [0-9]
blank [ \b\t]
nline [\n]
%%

"'"[a-zA-Z_]"'" {printf("::Char Const detected %s\n",yytext);}
{digit}+ {printf("::Integer Const detected %s\n",yytext);}
{digit}+"."{digit}+ {printf("::Float Const detected %s\n",yytext);}

\"[^\"]*\" {printf("::String Literal detected %s\n",yytext);}

"if"|"else"|"while"|"int"|"float"|"double" { printf("Keyword detected: %s\n",yytext);}
"#include" {printf("::Preprocessor Directive Include detected %s\n",yytext);} 
"#define" {printf("::Preprocessor Directive define detected %s\n",yytext);} 

"//".* {printf("::Single Line Comment detected %s\n",yytext);}    
"/*"([^\*]*"*/")+  {printf("::MultipleJHJHJHJ Line Comment detected %s  ::Comment Ended\n",yytext);} 



"=" {printf("::Assignment operator detected %s \n",yytext);}
"=="|"!=" {printf("::Relational operator detected %s \n",yytext);}
"="|"+"|"-"|"/"|"*" {printf("::Arithmatic operator detected %s \n",yytext);}
"&&"|"||" {printf("::Logical operator detected %s \n",yytext);} 
"&"|"|" {printf("::Bitwise operator detected %s \n",yytext);}

";"|"," {printf("::delimeter detected %s \n",yytext);}
{letter}({letter}|{digit})* { printf("::variable detected: %s\n",yytext);} 
"{"|"}"|"("|")" {printf("::Bracket Detected %s \n",yytext);}
"++" {printf("::Increment Detected %s \n",yytext); } 
"--" {printf("::Decrement Detected %s \n",yytext); } 
 
"?"/[^:]*":" {printf("::Ternary Detected %s \n",yytext); }
{nline} { ++linen; }
{blank}+ {printf("::WhiteSpace detected %s \n",yytext);}
. {printf("::Lex Error NOT DETECTED %s LINE No.%d\n",yytext,linen);}
%%
int main(){
	stdin=fopen("in","r"); 
	stdout=fopen("out","w");
	yylex();
	return 0;
}
