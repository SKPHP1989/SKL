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

#ifndef YY_YY_SRC_CORE_SKL_LANGUAGE_PARSER_H_INCLUDED
# define YY_YY_SRC_CORE_SKL_LANGUAGE_PARSER_H_INCLUDED
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
    T_ELSE = 264,
    T_ADD = 265,
    T_SUB = 266,
    T_MUL = 267,
    T_DIV = 268,
    T_ASSIGN = 269,
    T_EQ = 270,
    T_NE = 271,
    T_GT = 272,
    T_GE = 273,
    T_LT = 274,
    T_LE = 275,
    T_LP = 276,
    T_RP = 277,
    T_LC = 278,
    T_RC = 279,
    T_SEMICOLON = 280,
    T_IDENTIFIER = 281,
    T_BREAK = 282,
    T_CONTINUE = 283,
    T_RETURN = 284,
    T_COMMA = 285,
    T_STRING_LITERAL = 286,
    T_INCLUDE = 287
  };
#endif
/* Tokens.  */
#define T_INT_LITERAL 258
#define T_DOUBLE_LITERAL 259
#define T_FUNCTION 260
#define T_GLOBAL 261
#define T_FOR 262
#define T_IF 263
#define T_ELSE 264
#define T_ADD 265
#define T_SUB 266
#define T_MUL 267
#define T_DIV 268
#define T_ASSIGN 269
#define T_EQ 270
#define T_NE 271
#define T_GT 272
#define T_GE 273
#define T_LT 274
#define T_LE 275
#define T_LP 276
#define T_RP 277
#define T_LC 278
#define T_RC 279
#define T_SEMICOLON 280
#define T_IDENTIFIER 281
#define T_BREAK 282
#define T_CONTINUE 283
#define T_RETURN 284
#define T_COMMA 285
#define T_STRING_LITERAL 286
#define T_INCLUDE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "./src/core/skl_language_parser.y" /* yacc.c:1909  */

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

#line 131 "./src/core/skl_language_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_CORE_SKL_LANGUAGE_PARSER_H_INCLUDED  */
