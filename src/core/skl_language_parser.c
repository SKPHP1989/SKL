/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "skl_language_parser.y" /* yacc.c:339  */

#include "skl_core.h"
#include "skl_value.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#define YYDEBUG 1


#line 76 "skl_language_parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "skl_language_parser.h".  */
#ifndef YY_YY_SKL_LANGUAGE_PARSER_H_INCLUDED
# define YY_YY_SKL_LANGUAGE_PARSER_H_INCLUDED
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
#line 11 "skl_language_parser.y" /* yacc.c:355  */

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

#line 193 "skl_language_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SKL_LANGUAGE_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "skl_language_parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    50,    53,    57,    60,    64,    68,    75,
      76,    77,    78,    79,    80,    84,    85,    88,    89,    93,
     100,   107,   114,   121,   125,   132,   140,   144,   151,   155,
     162,   166,   173,   180,   181,   188,   189,   193,   200,   201,
     205,   209,   213,   220,   221,   225,   232,   233,   237,   244,
     248,   252,   256,   260,   264,   268,   272,   279,   280,   284,
     288,   295,   299
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT_LITERAL", "T_DOUBLE_LITERAL",
  "T_FUNCTION", "T_GLOBAL", "T_FOR", "T_IF", "T_ELSE", "T_ADD", "T_SUB",
  "T_MUL", "T_DIV", "T_ASSIGN", "T_EQ", "T_NE", "T_GT", "T_GE", "T_LT",
  "T_LE", "T_LP", "T_RP", "T_LC", "T_RC", "T_SEMICOLON", "T_IDENTIFIER",
  "T_BREAK", "T_CONTINUE", "T_RETURN", "T_COMMA", "T_STRING_LITERAL",
  "T_INCLUDE", "$accept", "translation_unit", "function_definition",
  "can_top_statement", "cannot_top_statement", "all_statement",
  "include_statement", "expression_statement", "for_statement",
  "break_statement", "if_statement", "return_statement",
  "global_variable_declaration_statement", "statement_list",
  "statement_block", "continue_statement", "expression",
  "equality_expression", "relational_expression", "additive_expression",
  "multiplicative_expression", "primary_expression", "option_expression",
  "param_list", "call_param_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      88,   -51,   -51,   -13,     0,     8,    30,    97,   100,    76,
     100,   -51,    28,     4,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,    62,    90,   115,   102,   103,   -51,    49,    55,
     100,   100,    81,   -51,    85,   100,    45,   -51,   111,   112,
     -51,   113,   114,   -51,   -51,   -51,   -51,   -51,   -51,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    24,
     100,   -51,   116,   105,   -51,   -51,   -51,   -51,   -16,   -51,
     -51,   -51,   -51,   115,   115,   102,   102,   102,   102,   103,
     103,   -51,   -51,    87,   -51,    25,   117,   100,    87,   -51,
     100,    13,   -51,    87,    96,   -51,   118,   131,   -51,   -51,
     -51,   -51,   -51,    57,   -51,   -51,   100,    87,   -51,   -51,
     122,   -51,    87,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    53,    54,     0,     0,     0,     0,     0,     0,    51,
      58,    52,     0,     0,     2,     3,    14,     9,    11,    12,
      13,    10,     0,    33,    35,    38,    43,    46,     0,     0,
      58,     0,    51,    49,     0,     0,     0,    57,     0,     0,
       1,     0,     0,     6,     4,     5,    15,    16,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,    50,    34,    55,    61,     0,    25,
      19,    22,    32,    36,    37,    40,    42,    39,    41,    44,
      45,    48,    47,     0,    59,     0,     0,    58,     0,    56,
       0,     0,     8,     0,     0,    27,     0,    23,    62,    30,
      17,    18,    28,     0,     7,    60,    58,     0,    31,    29,
       0,    24,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   132,     5,   133,    44,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -50,   -51,    -8,   -51,    75,    21,
      74,    -4,   -29,   -51,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,   100,   101,   102,    16,    17,    18,    46,
      19,    20,    21,   103,    92,    47,    22,    23,    24,    25,
      26,    27,    38,    85,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    62,    37,    33,    40,    15,    89,     1,     2,     3,
       4,     5,     6,    28,    90,     7,     1,     2,    44,     4,
       5,     6,    37,    63,     7,     8,    29,    65,    67,    30,
       9,    41,    42,    10,     8,    11,    12,    99,    97,     9,
      41,    42,    10,   104,    11,    12,    83,    93,     1,     2,
      84,    31,    86,    81,    82,    94,     7,   111,    96,    39,
       1,     2,   113,     4,     5,     6,     8,    66,     7,    60,
      59,     9,    75,    76,    77,    78,    11,   110,     8,    37,
      61,   108,    98,     9,    41,    42,    10,    48,    11,    12,
      35,     1,     2,     3,     4,     5,     6,    36,    37,     7,
       1,     2,    36,     1,     2,    49,    50,    64,     7,     8,
      91,     7,    55,    56,     9,    57,    58,    10,     8,    11,
      12,     8,   105,    32,    73,    74,     9,    88,    11,    79,
      80,    11,    51,    52,    53,    54,    69,    70,    71,    72,
     107,    87,    95,   106,   112,    43,    45,   109
};

static const yytype_uint8 yycheck[] =
{
       8,    30,    10,     7,     0,     0,    22,     3,     4,     5,
       6,     7,     8,    26,    30,    11,     3,     4,    13,     6,
       7,     8,    30,    31,    11,    21,    26,    35,    36,    21,
      26,    27,    28,    29,    21,    31,    32,    24,    88,    26,
      27,    28,    29,    93,    31,    32,    22,    22,     3,     4,
      26,    21,    60,    57,    58,    30,    11,   107,    87,    31,
       3,     4,   112,     6,     7,     8,    21,    22,    11,    14,
      21,    26,    51,    52,    53,    54,    31,   106,    21,    87,
      25,    24,    90,    26,    27,    28,    29,    25,    31,    32,
      14,     3,     4,     5,     6,     7,     8,    21,   106,    11,
       3,     4,    21,     3,     4,    15,    16,    22,    11,    21,
      23,    11,    10,    11,    26,    12,    13,    29,    21,    31,
      32,    21,    26,    26,    49,    50,    26,    22,    31,    55,
      56,    31,    17,    18,    19,    20,    25,    25,    25,    25,
       9,    25,    25,    25,    22,    13,    13,   103
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    11,    21,    26,
      29,    31,    32,    34,    35,    36,    39,    40,    41,    43,
      44,    45,    49,    50,    51,    52,    53,    54,    26,    26,
      21,    21,    26,    54,    49,    14,    21,    49,    55,    31,
       0,    27,    28,    35,    36,    37,    42,    48,    25,    15,
      16,    17,    18,    19,    20,    10,    11,    12,    13,    21,
      14,    25,    55,    49,    22,    49,    22,    49,    57,    25,
      25,    25,    25,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    22,    26,    56,    49,    25,    22,    22,
      30,    23,    47,    22,    30,    25,    55,    47,    49,    24,
      36,    37,    38,    46,    47,    26,    25,     9,    24,    38,
      55,    47,    22,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    34,    35,    35,    36,
      36,    36,    36,    36,    36,    37,    37,    38,    38,    39,
      40,    41,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     6,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     9,     2,     5,     7,     3,     3,     5,     1,     2,
       2,     3,     2,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     2,
       3,     1,     1,     1,     1,     3,     4,     1,     0,     1,
       3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 50 "skl_language_parser.y" /* yacc.c:1646  */
    {
        set_global_statement_list((yyvsp[0].statement));
    }
#line 1378 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "skl_language_parser.y" /* yacc.c:1646  */
    {
        set_global_statement_list((yyvsp[0].statement));
    }
#line 1386 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "skl_language_parser.y" /* yacc.c:1646  */
    {
        set_global_statement_list((yyvsp[0].statement));
    }
#line 1394 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "skl_language_parser.y" /* yacc.c:1646  */
    {
        create_function((yyvsp[-4].identifier) ,(yyvsp[-2].param_list) ,(yyvsp[0].statement_list));
    }
#line 1402 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "skl_language_parser.y" /* yacc.c:1646  */
    {
        create_function((yyvsp[-3].identifier) ,NULL ,(yyvsp[0].statement_list));
    }
#line 1410 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_include_statment((yyvsp[-1].identifier));
    }
#line 1418 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 101 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_expression_statement((yyvsp[-1].expression));
    }
#line 1426 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 108 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_for_statement((yyvsp[-6].expression) ,(yyvsp[-4].expression) ,(yyvsp[-2].expression) ,(yyvsp[0].statement_list));
    }
#line 1434 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_break_statement();
    }
#line 1442 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 122 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_if_statement((yyvsp[-2].expression) ,(yyvsp[0].statement_list) ,NULL);
    }
#line 1450 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_if_statement((yyvsp[-4].expression) ,(yyvsp[-2].statement_list) ,(yyvsp[0].statement_list));
    }
#line 1458 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 133 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_return_statement((yyvsp[-1].expression));
    }
#line 1466 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_global_variable_statement((yyvsp[-1].identifier), NULL);
    }
#line 1474 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 145 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_global_variable_statement((yyvsp[-3].identifier), (yyvsp[-1].expression));
    }
#line 1482 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 152 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement_list) = create_statement_list((yyvsp[0].statement));
    }
#line 1490 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement_list) = insert_statement_list((yyvsp[-1].statement_list) ,(yyvsp[0].statement));
    }
#line 1498 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 163 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement_list) = NULL;
    }
#line 1506 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 167 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement_list) = (yyvsp[-1].statement_list);
    }
#line 1514 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 174 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.statement) = create_continue_statement();
    }
#line 1522 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_assign_expression((yyvsp[-2].identifier) ,(yyvsp[0].expression));
    }
#line 1530 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 190 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_eq ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1538 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 194 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_ne ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1546 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 202 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_lt ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1554 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 206 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_gt ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1562 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 210 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_le ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1570 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 214 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_ge ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1578 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 222 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_add ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1586 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 226 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_sub ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1594 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 234 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_div ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1602 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_binary_expression(expression_action_mul ,(yyvsp[-2].expression),(yyvsp[0].expression));
    }
#line 1610 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 245 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = (yyvsp[0].expression);
    }
#line 1618 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 249 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = (yyvsp[-1].expression);
    }
#line 1626 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 253 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_identifier_expression((yyvsp[0].identifier));
    }
#line 1634 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 257 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_string_expression((yyvsp[0].identifier));
    }
#line 1642 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 261 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_integer_expression((yyvsp[0].integer));
    }
#line 1650 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 265 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_double_expression((yyvsp[0].db));
    }
#line 1658 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 269 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_call_function_expression((yyvsp[-2].identifier) ,NULL);
    }
#line 1666 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 273 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression) = create_call_function_expression((yyvsp[-3].identifier) ,(yyvsp[-1].expression_list));
    }
#line 1674 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 280 "skl_language_parser.y" /* yacc.c:1646  */
    {(yyval.expression)=NULL;}
#line 1680 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 285 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.param_list) = create_param_list((yyvsp[0].identifier));
    }
#line 1688 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 289 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.param_list) = insert_param_list((yyvsp[-2].param_list) ,(yyvsp[0].identifier));
    }
#line 1696 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 296 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression_list) = create_call_param_list((yyvsp[0].expression));
    }
#line 1704 "skl_language_parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 300 "skl_language_parser.y" /* yacc.c:1646  */
    {
        (yyval.expression_list) = insert_call_param_list((yyvsp[-2].expression_list) ,(yyvsp[0].expression));
    }
#line 1712 "skl_language_parser.c" /* yacc.c:1646  */
    break;


#line 1716 "skl_language_parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
