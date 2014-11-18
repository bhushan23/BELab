%{
#include <stdio.h>
#include <math.h>
void yyerror(char const *s){printf("Error");}
%}

%union{ float d; }
%left '+' '-'
%left '*' '/'
%right '^'
%nonassoc UN
%type <d> E
%token <d> NUM 
%token NL SINE LOG

%%

S : S E NL  {printf("Ans is %f\n",$2);} 
	|
	;
		
E : E '+' E { printf("%f = %f + %f \n",$$,$1,$3);$$ = $1 + $3; }
	| E '-' E { $$ = $1 - $3; }
	| E '*' E { $$ = $1 * $3; }
	| E '/' E { $$ = $1 / $3; }
	| '-' E %prec UN {$$ = -1 * $2;}
	| E '^' E {$$ = pow($1,$3);}
	| SINE '(' E ')' {$$ = sin($3);}
	| LOG '(' E ')' {$$ = log($3);}
	| NUM 
	;
%%

int main(){
	stdin=fopen("in","r"); 
	yyparse();
	return 0;
}
