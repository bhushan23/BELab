#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yaccsan.y"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
char vartype[10];
char Tempname[10];
int newAssignment = 0;
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


#line 33 "yaccsan.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {  struct icg{ char code[100]; char label[10]; char type[10];}ICG; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 57 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NL 257
#define ID 258
#define PR 259
#define INT 260
#define FLOAT 261
#define CHAR 262
#define DOUBLE 263
#define IF 264
#define WHILE 265
#define EQ 266
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    3,    3,    3,    3,    3,    7,    8,    8,    8,
    8,    9,    9,    2,    1,    1,    1,    1,    4,    6,
    6,    6,    5,
};
static const short yylen[] = {                            2,
    1,    2,    2,    2,    2,    0,    3,    1,    1,    1,
    1,    3,    1,    4,    3,    3,    3,    1,    7,    3,
    3,    1,    7,
};
static const short yydefred[] = {                         6,
    0,    0,    0,    8,    9,   10,   11,    0,    0,    5,
    4,    3,    2,    0,    0,    0,    0,   13,    0,   18,
    0,    0,    0,    0,    7,    0,    0,    0,    0,   14,
    0,    0,    0,    0,   12,    0,    0,   17,    0,    0,
    6,    6,    0,    0,   19,   23,
};
static const short yydgoto[] = {                          1,
   22,   10,    2,   11,   12,   23,   13,   14,   19,
};
static const short yysindex[] = {                         0,
    0, -224,  -55,    0,    0,    0,    0,  -27,  -20,    0,
    0,    0,    0, -233, -223, -223, -223,    0,  -32,    0,
  -28,  -34,    5,    7,    0, -216, -223, -223, -223,    0,
 -223, -223,  -80,  -74,    0,    8,    8,    0,    2,    2,
    0,    0, -124, -115,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,   51,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   11,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -41,  -38,    0,   12,   13,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    1,    0,  -18,    0,    0,   38,    0,    0,    0,
};
#define YYTABLESIZE 232
static const short yytable[] = {                         15,
   45,   15,   16,   15,   16,   15,   16,   29,   27,   46,
   28,   26,   16,   29,   27,   21,   28,   15,   15,   17,
   16,   16,   43,   44,   18,   32,   25,   36,   37,   38,
   30,   39,   40,    3,   20,    4,    5,    6,    7,    8,
    9,   35,   41,   29,   27,   33,   28,   34,   42,   29,
    1,   22,   20,   21,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    3,    0,    4,    5,    6,    7,    8,
    9,    0,    3,    0,    4,    5,    6,    7,    8,    9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   15,    0,    0,   16,    0,    0,
    0,   31,
};
static const short yycheck[] = {                         41,
  125,   43,   41,   45,   43,   61,   45,   42,   43,  125,
   45,   44,   40,   42,   43,   15,   45,   59,   60,   40,
   59,   60,   41,   42,  258,   60,   59,   27,   28,   29,
   59,   31,   32,  258,  258,  260,  261,  262,  263,  264,
  265,  258,  123,   42,   43,   41,   45,   41,  123,   42,
    0,   41,   41,   41,   17,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  258,   -1,  260,  261,  262,  263,  264,
  265,   -1,  258,   -1,  260,  261,  262,  263,  264,  265,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  266,   -1,   -1,  266,   -1,   -1,
   -1,  266,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"NL","ID","PR","INT","FLOAT","CHAR","DOUBLE","IF","WHILE","EQ",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : Program",
"Program : S",
"S : S Declare",
"S : S While",
"S : S If",
"S : S Assign",
"S :",
"Declare : Type List ';'",
"Type : INT",
"Type : FLOAT",
"Type : CHAR",
"Type : DOUBLE",
"List : List ',' ID",
"List : ID",
"Assign : ID '=' E ';'",
"E : E '+' E",
"E : E '-' E",
"E : E '*' E",
"E : ID",
"If : IF '(' Condition ')' '{' S '}'",
"Condition : E EQ E",
"Condition : E '<' E",
"Condition : E",
"While : WHILE '(' Condition ')' '{' S '}'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 135 "yaccsan.y"
  

void newSYM(char* lab, char* vartype);
void newQuad(char* src1,char* op,char* src2,char* tar);
void DisplaySTable(struct STable*);

void add_Code(struct icg *tar,struct icg *one, struct icg *two,char* operator){
        char Tempname[10],code[50];
        static int tmpnum = 0;
        sprintf(Tempname,"temp%d",tmpnum++);
        
        strcpy(tar->label,Tempname );
        strcpy(tar->type,two->type);
        newSYM(Tempname,two->type);
        strcat(Tempname," = ");
        strcpy(code, Tempname);
        strcat(code,one->label);
        strcat (code,operator);
        strcat(code,two->label);
        strcat(code,";\n");
        
        if(newAssignment == 0){
            strcpy(tar->code , code);
            newAssignment = 1;
        }
        else
            strcat(tar->code , code);
        newQuad(one->label,operator,two->label,tar->label);
}

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
printf("\n\n\t\t\t\t%s\n","Quad TABLE");
printf("\t| %s | SRC1  | OP   |  SRC2 | TARGET |\n","Index");
struct Quad* st = Qhead;
while(st){
    printf("\t|%7d|%7s|%6s|%7s|%8s|\n",i++,st->src1,st->op,st->src2,st->tar);
    st = st->next;
}
}
#line 418 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 40 "yaccsan.y"
	{ strcpy(yyval.ICG.code,yystack.l_mark[0].ICG.code); printf("\nGenerated 3 Address Code \n%s\n",yystack.l_mark[0].ICG.code);  }
break;
case 3:
#line 44 "yaccsan.y"
	{  strcat(yyval.ICG.code,yystack.l_mark[0].ICG.code); }
break;
case 4:
#line 45 "yaccsan.y"
	{  strcat(yyval.ICG.code,yystack.l_mark[0].ICG.code); }
break;
case 5:
#line 46 "yaccsan.y"
	{ strcat(yyval.ICG.code,yystack.l_mark[0].ICG.code); }
break;
case 8:
#line 53 "yaccsan.y"
	{strcpy(vartype ,"INT"); }
break;
case 9:
#line 54 "yaccsan.y"
	{strcpy(vartype ,"FLOAT"); }
break;
case 10:
#line 55 "yaccsan.y"
	{strcpy(vartype ,"CHAR");}
break;
case 11:
#line 56 "yaccsan.y"
	{strcpy(vartype ,"DOUBLE");}
break;
case 12:
#line 59 "yaccsan.y"
	{ newSYM(yystack.l_mark[0].ICG.label,vartype);}
break;
case 13:
#line 60 "yaccsan.y"
	{ newSYM(yystack.l_mark[0].ICG.label,vartype);}
break;
case 14:
#line 63 "yaccsan.y"
	{ 

                        strcpy(yyval.ICG.code,yystack.l_mark[-1].ICG.code);    
                        strcat(yyval.ICG.code,yystack.l_mark[-3].ICG.label);
                        strcat(yyval.ICG.code," = ");
                        strcat(yyval.ICG.code,yystack.l_mark[-1].ICG.label);
                        strcat(yyval.ICG.code,";\n");
                        newAssignment = 0;
                         }
break;
case 15:
#line 74 "yaccsan.y"
	{   add_Code(&yyval.ICG,&yystack.l_mark[-2].ICG,&yystack.l_mark[0].ICG,"+");   }
break;
case 16:
#line 76 "yaccsan.y"
	{    add_Code(&yyval.ICG,&yystack.l_mark[-2].ICG,&yystack.l_mark[0].ICG,"-");  }
break;
case 17:
#line 78 "yaccsan.y"
	{    add_Code(&yyval.ICG,&yystack.l_mark[-2].ICG,&yystack.l_mark[0].ICG,"*");  }
break;
case 18:
#line 79 "yaccsan.y"
	{ 
                           strcpy(yyval.ICG.code,yystack.l_mark[0].ICG.label);
                           strcpy(yyval.ICG.label,yystack.l_mark[0].ICG.label); 
                           strcpy(yyval.ICG.type,getType(yystack.l_mark[0].ICG.label));
                            
                     }
break;
case 19:
#line 89 "yaccsan.y"
	{ 
                    
                     strcpy(yyval.ICG.code,yystack.l_mark[-4].ICG.code);
                     
                     strcat(yyval.ICG.code,"GOTO IF.End;\n");
                     strcat (yyval.ICG.code,"If.Then:\n");
                     strcat(yyval.ICG.code,yystack.l_mark[-1].ICG.code); 
                     strcat (yyval.ICG.code,"If.End:\n");
                    }
break;
case 20:
#line 100 "yaccsan.y"
	{ 
                         strcpy(yyval.ICG.code,yystack.l_mark[-2].ICG.code);
                         strcat(yyval.ICG.code,yystack.l_mark[0].ICG.code);
                         strcat(yyval.ICG.code,"EQ ");
                         strcat(yyval.ICG.code,yystack.l_mark[-2].ICG.label);
                         strcat(yyval.ICG.code,",");
                         strcat(yyval.ICG.code,yystack.l_mark[0].ICG.label);
                         strcat(yyval.ICG.code,"\n");
                         newAssignment = 0;                    
                         }
break;
case 21:
#line 110 "yaccsan.y"
	{ 
                         
                         add_Code(&yyval.ICG,&yystack.l_mark[0].ICG,&yystack.l_mark[-2].ICG,"-");
                         strcat(yyval.ICG.code,"LT ");
                         strcat(yyval.ICG.code,yyval.ICG.label);
                         strcat(yyval.ICG.code,",");
                         strcat(yyval.ICG.code,"0");
                         strcat(yyval.ICG.code,"\n");
                         newAssignment = 0;                    
                         }
break;
case 22:
#line 120 "yaccsan.y"
	{
                strcpy(yyval.ICG.code,yystack.l_mark[0].ICG.code);
                newAssignment = 0;
            }
break;
case 23:
#line 126 "yaccsan.y"
	{
                    strcat(yyval.ICG.code,"WHILE.BEGIN:\n");
                    strcat(yyval.ICG.code,yystack.l_mark[-4].ICG.code);
                    strcat(yyval.ICG.code,"WHILE.True:\n");
                    strcat(yyval.ICG.code,yystack.l_mark[-1].ICG.code);
                    strcat(yyval.ICG.code,"GOTO WHILE.BEGIN\n");               
                    }
break;
#line 748 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
