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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {  struct icg{ char code[100]; char label[10]; char type[10];}ICG; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
