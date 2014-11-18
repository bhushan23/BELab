%{
#include <stdio.h>
#include <malloc.h>
#include <string.h>
char vartype[10];
int lineno = 1;
struct STable{
char label[10];
char type[10];
int size;
int location;
struct STable* next;
}*head;
void yyerror(const char *st){}
%}
%left '+' '-'
%left '*' 
%union { struct sym{ char* label; char type[10]; }SM; }
%token NL 
%token <SM> ID
%token  INT FLOAT CHAR DOUBLE
%type <SM> E  
%%

S: S Declare
   | Declare
   | S Assign
   | Assign
    ;
    
Declare: Type List ';'  
    ;

Type: INT {strcpy(vartype ,"INT"); }
    | FLOAT {strcpy(vartype ,"FLOAT"); }
    | CHAR {strcpy(vartype ,"CHAR");}
    | DOUBLE {strcpy(vartype ,"DOUBLE");}
    ;
    
List : List ',' ID { newSYM($3.label,vartype);}
    | ID { newSYM($1.label,vartype);}
    ;        
    
Assign: ID '=' E ';' { 
                        if(!isDeclared($1.label)){
                                   printf("\nError at line %d: Undeclared Variable %s",lineno,$1.label);     
                        }else if(strcmp($1.type,$3.type) != 0){
                         printf("\nError at line %d: Type Mismatch %s and %s",lineno,$1.type,$3.type);     
                        }
                    }         

        ;
        
E: E '+' E          {
                        if(strcmp($1.type,$3.type) != 0){
                           printf("\nError at line %d: Type Mismatch %s and %s",lineno,$1.type,$3.type);    
                        } 
                     }
    |
    E '-' E         {
                       if(strcmp($1.type,$3.type) != 0){
                            printf("\nError at line %d: Type Mismatch %s and %s",lineno,$1.type,$3.type);   
                        } 
                    }
    | ID             { 
                        if(!isDeclared($1.label)){
                                   printf("\nError at line %d: Undeclared Variable %s",lineno,$1.label);     
                        }else{
                            strcpy($$.type,getType($1.label)); 
                        }
                     }
  ;
  
       
%%  
void DisplaySTable(struct STable*);
int isDeclared(char* lab){
    struct STable *st = head;
    while(st){
     if(strcmp(st->label,lab) == 0){
        return 1;
     }
     st = st->next;
}
return 0;
}
char* getType(char* lab){
    struct STable *st = head;
    while(st){
     if(strcmp(st->label,lab) == 0){
        return st->type;
     }
     st = st->next;
}
}
int main(){
stdin = fopen("in","r");
freopen("out","w",stdout);

yyparse();
DisplaySTable(head);
}

int getVarSize(char* st){
if(strcmp(st,"INT") == 0 ||strcmp(st,"FLOAT") == 0  )
    return 4;
if(strcmp(st,"CHAR") == 0 )
    return 1;
if(strcmp(st,"DOUBLE") == 0  )
    return 8;    
}

void newSYM(char* lab, char* vartype){
struct STable *tnode = head;
int size = getVarSize(vartype);
if( !tnode ){
    struct STable* nnode = (struct STable *)malloc(sizeof(struct STable));
    strcpy(nnode->label ,lab);
    strcpy(nnode->type ,vartype);
    nnode->size = size;
    nnode->location = 100;
    nnode->next=NULL;
    head = nnode;
   
}else{
    while(tnode->next){
        if(strcmp (tnode->label,lab) == 0){
            printf("\nError at line %d: ReDeclaration of %s Variable %s (Previous Declaration as %s)",lineno,vartype, lab,tnode->type);
            return;
        } 
        tnode = tnode->next;   
    }
    struct STable* nnode = (struct STable *)malloc(sizeof(struct STable));
    strcpy(nnode->label ,lab);
    nnode->size = size;
    strcpy(nnode->type ,vartype);
    nnode->location = tnode -> location + size;
    nnode->next=NULL;
    tnode->next = nnode;
}
}

void DisplaySTable(struct STable *st){
int i = 1;
printf("\n\n\t\t\t\t%s\n","SYMBOL TABLE");
printf("\t| %s | Label | size | location |\n","Index");
while(st){
    printf("\t|%7d|%7s|%6d|%10d|\n",i++,st->label,st->size,st->location);
    st = st->next;
}
}
