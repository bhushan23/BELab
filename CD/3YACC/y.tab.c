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

#line 2 "yfile.y"
#include <stdio.h>
extern lineno;
void yyerror(char const *s){}
#line 23 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

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

#define ID 257
#define INT 258
#define FLOAT 259
#define CHAR 260
#define BLANK 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define MAIN 266
#define CONST 267
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    4,    4,    1,    1,    1,   10,   10,
   10,   10,    5,   12,   12,   12,   12,   11,   11,   11,
   13,   13,   13,   14,   14,   15,   15,    6,    6,    6,
    7,    7,    8,    8,   16,   16,   16,   16,   16,    9,
    9,
};
static const short yylen[] = {                            2,
    7,    2,    0,    3,    3,    2,    2,    2,    4,    2,
    2,    2,    0,    2,    2,    1,    1,    1,    3,    3,
    1,    1,    3,    1,    1,    1,    1,    3,    1,    1,
    3,    1,    0,    1,    1,    2,    3,    3,    5,    1,
    3,    1,    5,    1,    1,    1,    1,    1,    0,    9,
    1,
};
static const short yydefred[] = {                         0,
   16,   17,   18,    0,    0,    0,    0,    0,    3,    0,
    1,    0,   40,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    8,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    5,    0,   13,    0,   30,   23,    0,    0,
    0,    0,   45,   46,    0,   48,    0,    0,   13,   41,
    0,   24,   25,   26,   27,    0,   34,   35,    0,    0,
    0,    0,    0,   20,    0,   28,   31,   39,   43,    0,
   37,    0,    0,    0,   50,
};
static const short yydgoto[] = {                          4,
   18,   10,   12,   19,   20,   21,   22,   23,   24,   31,
   39,   56,   46,   59,   50,   47,
};
static const short yysindex[] = {                      -143,
    0,    0,    0,    0, -262,  -23,  -32,  -82,    0,  -78,
    0, -169,    0,  -12,   16,   17,   23, -206,   -7,    7,
 -194,    0,    0,  -50, -251, -251, -251, -181,  -12,    0,
   36,    0,    0,  -42,    0,   66,    0,    0,   58,   44,
   69,  -16,    0,    0,   58,    0,   48, -138,    0,    0,
 -169,    0,    0,    0,    0, -136,    0,    0, -251,  -42,
  -42, -251,  -12,    0,  -61,    0,    0,    0,    0,   64,
    0, -181,   84,  -42,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -159,
    0,    2,    0,    0,    0,    0,    0,    0, -111, -101,
  -81,    0,    0,  -71,    0,   19,   85,    7,  -31,  -21,
   -1,    0,    0,    0,    0,  -41,    0,    0,    9,  -91,
    0,   12,    0,    0,   -4,    0,    0,    0,    0,    0,
  -58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    7,  -11,    0, -122,    0,    0,    0,    0,    0,
    0,   85,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  128,    0,  -24,  -26,  -13,    0,    0,    0,    0,    0,
   11,    0,  -19,    0,    1,   57,
};
#define YYTABLESIZE 284
static const short yytable[] = {                         29,
   36,   43,   29,    6,   30,   36,   40,   41,    8,   21,
   51,   11,   21,   11,   44,   37,    7,   29,   29,   15,
   29,   12,   22,   12,   65,   54,   52,   21,   53,   19,
   55,   38,   19,   38,   64,   38,   32,   15,   45,   14,
    9,    6,   70,    6,   25,   43,   11,   19,   25,   32,
   29,   32,   29,   10,   32,   26,   27,   14,   44,   33,
   68,   69,   28,   71,    9,   33,    9,   32,   34,   67,
   29,   29,   35,   29,   75,   42,    1,    2,    3,   48,
   49,   29,   45,   29,   60,   37,   13,   14,    1,    2,
    3,   21,   15,   21,   16,   17,   13,   13,   13,   13,
   13,   15,   13,   15,   13,   13,   62,   54,   52,   61,
   53,   19,   55,   19,    1,    2,    3,   58,   63,   57,
   66,   14,   72,   14,   74,   33,    2,    5,   73,    0,
    0,   32,    0,   32,    0,    0,    0,    0,    0,    0,
   36,   33,    0,   33,   11,   11,   11,   11,   11,    0,
   11,   11,   11,   11,   12,   12,   12,   12,   12,    0,
   12,   12,   12,   12,   38,   38,   38,   38,   38,    0,
   38,   38,   38,   38,    6,    6,    6,    6,    6,    0,
    6,    0,    6,    6,   10,   10,   10,   10,   10,    0,
   10,   10,   10,   10,   13,   14,    1,    2,    3,    0,
   15,    0,   16,   17,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,   29,   29,   29,   29,    0,
   29,   29,   29,   29,   21,   21,   21,   21,   21,    0,
   21,   21,   21,   21,   15,   15,   15,   15,   15,    0,
   15,   15,   15,   15,   19,   19,   19,   19,   19,    0,
   19,   19,   19,   19,   14,   14,   14,   14,   14,    0,
   14,   14,   14,   14,   32,   32,   32,   32,   32,    0,
   32,   32,   32,   32,   33,    0,   33,   33,   33,    0,
   33,   33,   33,   33,
};
static const short yycheck[] = {                         41,
  123,   28,   44,  266,   18,  257,   26,   27,   41,   41,
   35,  123,   44,  125,   28,  267,   40,   59,   60,   41,
   62,  123,   44,  125,   49,   42,   43,   59,   45,   41,
   47,  123,   44,  125,   48,   25,   41,   59,   28,   41,
  123,  123,   62,  125,   61,   72,  125,   59,   61,   41,
  257,   59,   41,  125,   59,   40,   40,   59,   72,   41,
   60,   61,   40,  125,  123,   59,  125,   59,  263,   59,
   59,   60,  123,   62,   74,  257,  258,  259,  260,   44,
  123,  123,   72,  125,   41,  267,  256,  257,  258,  259,
  260,  123,  262,  125,  264,  265,  256,  257,  258,  259,
  260,  123,  262,  125,  264,  265,   59,   42,   43,   41,
   45,  123,   47,  125,  258,  259,  260,   60,  257,   62,
  257,  123,   59,  125,   41,   41,  125,    0,   72,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
  263,  123,   -1,  125,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,   -1,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,   -1,  264,  265,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  256,   -1,  258,  259,  260,   -1,
  262,  263,  264,  265,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"ID","INT","FLOAT","CHAR","BLANK","IF","ELSE","WHILE","FOR",
"MAIN","CONST","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : Main",
"Main : Type MAIN '(' ')' '{' Program '}'",
"Program : Program SList",
"Program :",
"SList : SList Declare ';'",
"SList : SList AssignMent ';'",
"SList : SList If",
"SList : SList IfElse",
"SList : SList While",
"SList : SList For '{' SList",
"SList : SList For",
"SList : SList Declare",
"SList : SList AssignMent",
"SList :",
"Declare : Type Idlist",
"Declare : Type AssignMent",
"Type : INT",
"Type : FLOAT",
"Type : CHAR",
"Idlist : Idlist ',' ID",
"Idlist : Idlist ',' AssignMent",
"Idlist : ID",
"Idlist : AssignMent",
"AssignMent : ID '=' Expression",
"NumOperator : '+'",
"NumOperator : '-'",
"NumOperator : '*'",
"NumOperator : '/'",
"Expression : ID NumOperator ID",
"Expression : ID",
"Expression : CONST",
"Condition : Expression RelOperator Expression",
"Condition : Expression",
"Condition :",
"RelOperator : '>'",
"RelOperator : '<'",
"StatementBlock : '{' SList",
"StatementBlock : '{' SList '}'",
"If : IF '(' Condition",
"If : IF '(' Condition ')' StatementBlock",
"If : error",
"IfElse : If ELSE StatementBlock",
"IfElse : error",
"While : WHILE '(' Condition ')' StatementBlock",
"While : error",
"ForData : Declare",
"ForData : AssignMent",
"ForData : Expression",
"ForData : Condition",
"ForData :",
"For : FOR '(' ForData ';' Condition ';' ForData ')' StatementBlock",
"For : error",

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
#line 90 "yfile.y"

int main(){
	stdin=fopen("in.c","r"); 
	stdout=fopen("out","w");
	yyparse();
	return 0;
}
#line 305 "y.tab.c"

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
#line 10 "yfile.y"
	{printf("MAIN DETECTED\n");}
break;
case 9:
#line 22 "yfile.y"
	{printf("Error at Line:%d - Missing } For Loop\n",lineno);}
break;
case 11:
#line 24 "yfile.y"
	{printf("Error at Line:%d - Declaration Missing Semicolon \n",lineno);}
break;
case 12:
#line 25 "yfile.y"
	{printf("Error at Line:%d -Assingment Missing Semicolon \n",lineno);}
break;
case 14:
#line 28 "yfile.y"
	{printf("Declare detected \n");}
break;
case 15:
#line 29 "yfile.y"
	{printf("Declarative assignment detected \n");}
break;
case 16:
#line 31 "yfile.y"
	{printf("int detected\n");}
break;
case 17:
#line 32 "yfile.y"
	{printf("float detected\n");}
break;
case 18:
#line 33 "yfile.y"
	{printf("char detected\n");}
break;
case 19:
#line 36 "yfile.y"
	{printf("idlist detected\n");}
break;
case 20:
#line 37 "yfile.y"
	{printf("declarative idlist  assignment detected\n");}
break;
case 21:
#line 38 "yfile.y"
	{printf("id detected\n");}
break;
case 22:
#line 39 "yfile.y"
	{printf("declarative id assignment detected\n");}
break;
case 23:
#line 42 "yfile.y"
	{printf("idlist with = assignment detected\n");}
break;
case 28:
#line 50 "yfile.y"
	{printf("idlist with + assignment detected\n");}
break;
case 36:
#line 62 "yfile.y"
	{printf("Error at Line:%d - Missing } Bracket \n",lineno);}
break;
case 38:
#line 65 "yfile.y"
	{printf("Error at line:%d -Missing ) Bracket\n",lineno);}
break;
case 39:
#line 66 "yfile.y"
	{printf("IF Loop detected\n");}
break;
case 40:
#line 67 "yfile.y"
	{printf("Error at line:%d \n",lineno); }
break;
case 41:
#line 70 "yfile.y"
	{printf("ELSE Loop detected\n");}
break;
case 42:
#line 71 "yfile.y"
	{printf("Error at line:%d \n",lineno); }
break;
case 43:
#line 74 "yfile.y"
	{printf("WHILE Loop detected\n");}
break;
case 44:
#line 75 "yfile.y"
	{printf("Error at line:%d \n",lineno); }
break;
case 50:
#line 85 "yfile.y"
	{printf("FOR Loop detected\n");}
break;
case 51:
#line 86 "yfile.y"
	{printf("Error at line:%d \n",lineno); }
break;
#line 607 "y.tab.c"
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
