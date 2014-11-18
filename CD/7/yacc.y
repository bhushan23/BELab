%{
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
char vartype[10];
char Tempname[10];
int num;
struct STable{
char label[10];
char type[10];
int size;
int location;
struct STable* next;
}*head;


struct Quad{
struct Quad* prev;
char src1[10];
char op[10];
char src2[10];
char tar[10];
struct Quad* next;
}*Qhead;

void yyerror(const char *st){}


%}
%left '+' '-'
%union {  struct icg{ char code[50]; char label[10]; char type[10];}ICG; }
%token NL 
%token <ICG> ID
%token  INT FLOAT CHAR DOUBLE
%type <ICG> E  
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
                       if(strcmp($1.type,$3.type) != 0){
                         printf("\nError: Type Mismatch %s and %s",$1.type,$3.type);     
                        }
                        printf("\n\n%s",$3.code);
                    }         
                    
        ;
        
E: E '+' E          {
               
                     if(strcmp($1.type,$3.type) != 0){
                            printf("\nError: Type Mismatch %s and %s",$1.type,$3.type);   
                              
                        } else{
                        printf("\n%s   :+:   %s",$1.label,$3.label);
                        add_Code($$,$1,$3);
                        /*
                            strcpy(Tempname,"Temp");
                            char st[30],code[30];
                            sprintf(st,"%d",num++);
                            strcat(Tempname,st);
                            
                            strcpy(st,"+");  
                            strcpy($$.label,Tempname );
                            strcpy($$.type,$3.type);
                            newSYM(Tempname,$3.type);
                            strcat(Tempname," = ");
                            strcpy(code, Tempname);
                            strcat(code,$1.label);
                            strcat (code,st);
                            strcat(code,$3.label);
                            strcat(code,";\n");
                            strcat($$.code , code);
                            newQuad($1.label,"+",$3.label,$$.label);
                          */
                     }
                     }
    |
    E '-' E         {
                       if(strcmp($1.type,$3.type) != 0){
                            printf("\nError: Type Mismatch %s and %s",$1.type,$3.type);     
                        } 
                        
                    }
    | ID             { 
                      
                        if(!isDeclared($1.label)){
                                   printf("\nError: Undeclared Variable %s",$1.label);     
                        }else{
                           printf("\n%s",$1.label);
                            strcpy($$.code,$1.label);
                            strcpy($$.label,$1.label); 
                            strcpy($$.type,getType($1.label)); 
                        }
                     }
  ;
  
       
%%  
void add_Code(YYSTYPE tar,YYSTYPE one, YYSTYPE two){

}
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
void DisplayQuad();
int main(){
head =  NULL;
Qhead = NULL;
stdin = fopen("in","r");
freopen("out","w",stdout);

yyparse();
DisplaySTable(head);
DisplayQuad();
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
            printf("\nError: ReDeclaration of %s Variable %s (Previous Declaration as %s)",vartype, lab,tnode->type);
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

void newQuad(char* src1,char* op,char* src2,char* tar){

struct Quad *tnode = Qhead;
if( !tnode ){
    struct Quad* nnode = (struct Quad *)malloc(sizeof(struct Quad));
    strcpy(nnode->src1 ,src1);
    strcpy(nnode->op ,op);
    strcpy(nnode->src2 ,src2);
    strcpy(nnode->tar ,tar);
    nnode->next=NULL;
    Qhead = nnode;
   
}else{
    while(tnode->next){
        tnode = tnode->next;   
    }
    struct Quad* nnode = (struct Quad *)malloc(sizeof(struct Quad));
    strcpy(nnode->src1 ,src1);
    strcpy(nnode->op ,op);
    strcpy(nnode->src2 ,src2);
    strcpy(nnode->tar ,tar);
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

void DisplayQuad(){
int i = 1;
printf("\n\n\t\t\t\t%s\n","SYMBOL TABLE");
printf("\t| %s | SRC1 | OP | SRC2 | TARGET |\n","Index");
struct Quad* st = Qhead;
while(st){
    printf("\t|%7d|%7s|%6s|%7s|%7s\n",i++,st->src1,st->op,st->src2,st->tar);
    st = st->next;
}
}