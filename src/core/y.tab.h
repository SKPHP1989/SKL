/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT_LITERAL = 258,
    T_DOUBLE_LITERAL = 259,
    T_FUNCTION = 260,
    T_GLOBAL = 261,
    T_FOR = 262,
    T_IF = 263,
    T_ADD = 264,
    T_SUB = 265,
    T_MUL = 266,
    T_DIV = 267,
    T_ASSIGN = 268,
    T_EQ = 269,
    T_NE = 270,
    T_GT = 271,
    T_GE = 272,
    T_LT = 273,
    T_LE = 274,
    T_LP = 275,
    T_RP = 276,
    T_LC = 277,
    T_RC = 278,
    T_SEMICOLON = 279,
    T_IDENTIFIER = 280,
    T_BREAK = 281,
    T_CONTINUE = 282,
    T_RETURN = 283,
    T_COMMA = 284,
    T_STRING_LITERAL = 285
  };
#endif
/* Tokens.  */
#define T_INT_LITERAL 258
#define T_DOUBLE_LITERAL 259
#define T_FUNCTION 260
#define T_GLOBAL 261
#define T_FOR 262
#define T_IF 263
#define T_ADD 264
#define T_SUB 265
#define T_MUL 266
#define T_DIV 267
#define T_ASSIGN 268
#define T_EQ 269
#define T_NE 270
#define T_GT 271
#define T_GE 272
#define T_LT 273
#define T_LE 274
#define T_LP 275
#define T_RP 276
#define T_LC 277
#define T_RC 278
#define T_SEMICOLON 279
#define T_IDENTIFIER 280
#define T_BREAK 281
#define T_CONTINUE 282
#define T_RETURN 283
#define T_COMMA 284
#define T_STRING_LITERAL 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "skl_language_parser.y" /* yacc.c:1909  */

    char *identifier;
    int integer;
    double db;
    variable_t *variable;
    expression_t *expression;
    expression_list_t *expression_list;
    statement_t *statement;
    statement_list_t *statement_list;
    function_t *function;
    param_list_t *param_list;

#line 127 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
