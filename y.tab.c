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
#line 1 "compiler_actions.y" /* yacc.c:339  */
 /* C Declarations and Definitions */
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
extern int yylex();
void yyerror(string s);
//extern int yydebug;
extern int yyparse();


#include "compiler_translator.h"

Quad quadlist;
SymbolTable globalST;
SymbolTable *St = &globalST;
SymbolTable *currST = &globalST;
typeOf *g;
int w;
vector<string> literals;
int literal_count = 0;

#line 89 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RESTRICT_KEYWORD = 258,
    UNSIGNED_KEYWORD = 259,
    AUTO_KEYWORD = 260,
    ENUM_KEYWORD = 261,
    BREAK_KEYWORD = 262,
    EXTERN_KEYWORD = 263,
    RETURN_KEYWORD = 264,
    VOID_KEYWORD = 265,
    CASE_KEYWORD = 266,
    FLOAT_KEYWORD = 267,
    SHORT_KEYWORD = 268,
    VOLATILE_KEYWORD = 269,
    CHAR_KEYWORD = 270,
    FOR_KEYWORD = 271,
    SIGNED_KEYWORD = 272,
    WHILE_KEYWORD = 273,
    CONST_KEYWORD = 274,
    GOTO_KEYWORD = 275,
    SIZEOF_KEYWORD = 276,
    BOOL_KEYWORD = 277,
    CONTINUE_KEYWORD = 278,
    IF_KEYWORD = 279,
    STATIC_KEYWORD = 280,
    COMPLEX_KEYWORD = 281,
    DEFAULT_KEYWORD = 282,
    INLINE_KEYWORD = 283,
    STRUCT_KEYWORD = 284,
    IMAGINARY_KEYWORD = 285,
    DO_KEYWORD = 286,
    INT_KEYWORD = 287,
    SWITCH_KEYWORD = 288,
    DOUBLE_KEYWORD = 289,
    LONG_KEYWORD = 290,
    TYPEDEF_KEYWORD = 291,
    ELSE_KEYWORD = 292,
    REGISTER_KEYWORD = 293,
    UNION_KEYWORD = 294,
    IDENTIFIER = 295,
    INT_CONSTANT = 296,
    FLOAT_CONSTANT = 297,
    CHAR_CONSTANT = 298,
    STRING_LITERAL = 299,
    POINTER = 300,
    INCREMENT = 301,
    DECREMENT = 302,
    LEFT_SHIFT = 303,
    RIGHT_SHIFT = 304,
    LESS_EQUAL = 305,
    GREATER_EQUAL = 306,
    IS_EQUAL = 307,
    NOT_EQUAL = 308,
    LOGICALL_AND = 309,
    LOGICALL_OR = 310,
    ELLIPSIS = 311,
    MULTIPLY_BY = 312,
    DIVIDE_BY = 313,
    MOD_BY = 314,
    AND_EQUAL = 315,
    SUB_BY = 316,
    LEFT_SHIFT_EQUAL = 317,
    RIGHT_SHIFT_EQUAL = 318,
    ADD_BY = 319,
    XOR_EQUAL = 320,
    OR_EQUAL = 321
  };
#endif
/* Tokens.  */
#define RESTRICT_KEYWORD 258
#define UNSIGNED_KEYWORD 259
#define AUTO_KEYWORD 260
#define ENUM_KEYWORD 261
#define BREAK_KEYWORD 262
#define EXTERN_KEYWORD 263
#define RETURN_KEYWORD 264
#define VOID_KEYWORD 265
#define CASE_KEYWORD 266
#define FLOAT_KEYWORD 267
#define SHORT_KEYWORD 268
#define VOLATILE_KEYWORD 269
#define CHAR_KEYWORD 270
#define FOR_KEYWORD 271
#define SIGNED_KEYWORD 272
#define WHILE_KEYWORD 273
#define CONST_KEYWORD 274
#define GOTO_KEYWORD 275
#define SIZEOF_KEYWORD 276
#define BOOL_KEYWORD 277
#define CONTINUE_KEYWORD 278
#define IF_KEYWORD 279
#define STATIC_KEYWORD 280
#define COMPLEX_KEYWORD 281
#define DEFAULT_KEYWORD 282
#define INLINE_KEYWORD 283
#define STRUCT_KEYWORD 284
#define IMAGINARY_KEYWORD 285
#define DO_KEYWORD 286
#define INT_KEYWORD 287
#define SWITCH_KEYWORD 288
#define DOUBLE_KEYWORD 289
#define LONG_KEYWORD 290
#define TYPEDEF_KEYWORD 291
#define ELSE_KEYWORD 292
#define REGISTER_KEYWORD 293
#define UNION_KEYWORD 294
#define IDENTIFIER 295
#define INT_CONSTANT 296
#define FLOAT_CONSTANT 297
#define CHAR_CONSTANT 298
#define STRING_LITERAL 299
#define POINTER 300
#define INCREMENT 301
#define DECREMENT 302
#define LEFT_SHIFT 303
#define RIGHT_SHIFT 304
#define LESS_EQUAL 305
#define GREATER_EQUAL 306
#define IS_EQUAL 307
#define NOT_EQUAL 308
#define LOGICALL_AND 309
#define LOGICALL_OR 310
#define ELLIPSIS 311
#define MULTIPLY_BY 312
#define DIVIDE_BY 313
#define MOD_BY 314
#define AND_EQUAL 315
#define SUB_BY 316
#define LEFT_SHIFT_EQUAL 317
#define RIGHT_SHIFT_EQUAL 318
#define ADD_BY 319
#define XOR_EQUAL 320
#define OR_EQUAL 321

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "compiler_actions.y" /* yacc.c:355  */

  int intval;
  float floatval;
  char charval;
  string *str;
  expression *expressionList;
  declaration *decList;
  initDecList *initDeclist;
  typeOf *type_;
  Fdef *fDef;
  FList *fList;

#line 274 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 291 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  371

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    82,    75,     2,
      67,    68,    76,    77,    74,    78,    71,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    90,
      83,    89,    84,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    86,    73,    79,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   141,   147,   153,   166,   178,   190,   199,
     202,   203,   222,   223,   238,   239,   240,   259,   278,   279,
     283,   290,   300,   301,   320,   340,   364,   365,   368,   369,
     370,   371,   372,   373,   376,   377,   381,   382,   469,   552,
     636,   637,   720,   809,   810,   855,   901,   902,   927,   952,
     977,  1005,  1006,  1032,  1061,  1062,  1091,  1092,  1119,  1120,
    1147,  1148,  1184,  1185,  1220,  1221,  1261,  1262,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1296,
    1297,  1300,  1305,  1306,  1401,  1402,  1403,  1404,  1405,  1406,
    1407,  1408,  1413,  1417,  1425,  1429,  1436,  1437,  1438,  1439,
    1443,  1447,  1453,  1454,  1459,  1460,  1461,  1466,  1467,  1468,
    1469,  1470,  1471,  1474,  1475,  1476,  1477,  1481,  1482,  1483,
    1484,  1485,  1485,  1489,  1490,  1494,  1495,  1499,  1502,  1503,
    1504,  1508,  1512,  1516,  1525,  1529,  1530,  1535,  1536,  1537,
    1538,  1580,  1588,  1590,  1593,  1595,  1599,  1606,  1607,  1614,
    1617,  1618,  1622,  1624,  1627,  1631,  1634,  1638,  1644,  1660,
    1664,  1665,  1670,  1674,  1675,  1676,  1680,  1681,  1682,  1683,
    1687,  1692,  1693,  1697,  1698,  1703,  1704,  1705,  1706,  1707,
    1708,  1711,  1712,  1713,  1718,  1719,  1722,  1726,  1734,  1735,
    1739,  1740,  1743,  1754,  1766,  1769,  1781,  1788,  1802,  1805,
    1807,  1810,  1811,  1812,  1813,  1820,  1842,  1843,  1847,  1848,
    1852,  1853,  1884,  1885
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RESTRICT_KEYWORD", "UNSIGNED_KEYWORD",
  "AUTO_KEYWORD", "ENUM_KEYWORD", "BREAK_KEYWORD", "EXTERN_KEYWORD",
  "RETURN_KEYWORD", "VOID_KEYWORD", "CASE_KEYWORD", "FLOAT_KEYWORD",
  "SHORT_KEYWORD", "VOLATILE_KEYWORD", "CHAR_KEYWORD", "FOR_KEYWORD",
  "SIGNED_KEYWORD", "WHILE_KEYWORD", "CONST_KEYWORD", "GOTO_KEYWORD",
  "SIZEOF_KEYWORD", "BOOL_KEYWORD", "CONTINUE_KEYWORD", "IF_KEYWORD",
  "STATIC_KEYWORD", "COMPLEX_KEYWORD", "DEFAULT_KEYWORD", "INLINE_KEYWORD",
  "STRUCT_KEYWORD", "IMAGINARY_KEYWORD", "DO_KEYWORD", "INT_KEYWORD",
  "SWITCH_KEYWORD", "DOUBLE_KEYWORD", "LONG_KEYWORD", "TYPEDEF_KEYWORD",
  "ELSE_KEYWORD", "REGISTER_KEYWORD", "UNION_KEYWORD", "IDENTIFIER",
  "INT_CONSTANT", "FLOAT_CONSTANT", "CHAR_CONSTANT", "STRING_LITERAL",
  "POINTER", "INCREMENT", "DECREMENT", "LEFT_SHIFT", "RIGHT_SHIFT",
  "LESS_EQUAL", "GREATER_EQUAL", "IS_EQUAL", "NOT_EQUAL", "LOGICALL_AND",
  "LOGICALL_OR", "ELLIPSIS", "MULTIPLY_BY", "DIVIDE_BY", "MOD_BY",
  "AND_EQUAL", "SUB_BY", "LEFT_SHIFT_EQUAL", "RIGHT_SHIFT_EQUAL", "ADD_BY",
  "XOR_EQUAL", "OR_EQUAL", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept", "M", "N",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "LOGICAL_AND_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "constant", "specifier_qualifier_list",
  "enum_specifier", "$@1", "enumerator_list", "enumerator",
  "enumeration_constant", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "assignment_expression_opt",
  "type_qualifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_specifier",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "expression_opt",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    40,    41,    91,
      93,    46,   123,   125,    44,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    58,    61,
      59
};
# endif

#define YYPACT_NINF -284

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-284)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1250,  -284,  -284,  -284,   -14,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,   -29,  1250,  1250,  -284,  1250,  1250,  1176,
    -284,  -284,     7,    16,  -284,   -24,    26,  -284,   -17,  -284,
     495,    46,     8,  -284,  -284,  -284,  -284,  -284,  -284,    16,
    -284,  -284,    52,  -284,   -26,    36,  -284,  -284,    26,   -24,
    -284,   328,   882,  -284,   -29,  -284,   763,  1212,    69,    46,
     103,  -284,    -4,   958,  -284,  -284,  -284,  -284,    28,   -19,
     762,   958,    25,  -284,    45,  1002,    58,    93,    67,  -284,
     100,    92,  -284,  -284,  -284,  -284,  1018,  1018,   685,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,   145,   408,
     958,  -284,    70,   -28,   152,   -16,   150,   114,   108,   110,
     144,   -11,  -284,  -284,    -8,  -284,  -284,  -284,  -284,   142,
    -284,  -284,  -284,  -284,  -284,  -284,   838,  -284,  -284,  -284,
    -284,  -284,   -24,   149,  -284,   157,  -284,    48,   104,  1062,
     140,  -284,     1,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
      24,   135,   607,   159,   143,   685,  -284,  -284,   958,   528,
     528,   958,   528,   685,  -284,  -284,    79,  1283,  -284,  1283,
     164,   195,  -284,  -284,   898,   958,   196,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,   958,  -284,
     958,   958,   958,   958,   958,   958,   958,   958,   958,   958,
     958,   958,   958,   958,   958,   958,   183,    -9,   958,  -284,
    -284,   416,   958,   199,  -284,   131,   882,    30,  -284,  -284,
    -284,  1140,  -284,   200,   958,   104,   171,  -284,   174,   958,
    -284,  -284,   528,   172,   958,   155,   958,  -284,   179,   172,
    -284,  -284,    88,  -284,   180,  -284,  -284,  -284,   942,  -284,
    -284,    95,  -284,    10,  -284,  -284,  -284,  -284,  -284,    70,
      70,   -28,   -28,   152,   152,   152,   152,   -16,   -16,   150,
     114,   108,  -284,  -284,  -284,  -284,  -284,   184,  -284,  -284,
     778,  -284,  -284,  -284,  -284,  -284,  -284,   185,  -284,  -284,
     186,  -284,   163,  -284,   172,   191,   189,   240,   528,   191,
     838,  -284,  -284,   958,  -284,   958,   958,   958,  -284,  -284,
    -284,   882,  -284,  -284,   958,   958,   197,  -284,   202,  -284,
     137,  -284,   110,  -284,   172,  -284,   204,  -284,  -284,   528,
     958,  -284,   822,  -284,   183,   176,   528,   187,   528,  -284,
      96,  -284,  -284,  -284,  -284,  -284,   237,   190,   958,   958,
    -284,  -284,  -284,  -284,   528,   211,  -284,  -284,  -284,   528,
    -284
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   129,   108,    98,     0,    96,   100,   105,   102,   130,
     101,   107,   128,   109,    97,   110,   131,   111,   103,   106,
     104,    99,   209,     0,    84,    86,   112,    88,    90,     0,
     206,   208,   121,     0,   134,     0,   146,    82,     0,    92,
      94,   133,     0,    85,    87,    89,    91,     1,   207,     0,
     122,   127,     0,   123,   125,     0,   150,   148,   147,     0,
      83,     0,     0,   212,     0,   211,     0,   153,   145,   132,
       0,   117,     0,     0,   135,   151,   149,    93,    94,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     2,
       0,     4,     5,     6,     7,     8,     0,     0,     0,   184,
      28,    29,    30,    31,    32,    33,   190,    10,    22,    34,
       0,    36,    40,    43,    46,    51,    54,    56,    58,    60,
      62,    64,    66,    79,     0,   188,   189,   175,   176,     2,
     186,   177,   178,   179,   180,     4,     0,   163,    95,   213,
     210,   160,   159,     0,   152,   154,   156,     0,   145,   143,
     144,   118,     0,   119,   124,    34,    81,   126,   203,   204,
       0,     0,   200,     0,     0,     0,    26,   202,     0,     0,
       0,     0,     0,     0,    23,    24,     0,   113,   162,   115,
       0,     0,    16,    17,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    68,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     185,     0,     0,     0,   166,     0,     0,     0,   171,   158,
     140,     0,   141,     0,     0,   144,    29,   142,     0,     0,
     120,   205,     0,   199,   200,     0,     0,   201,     0,     3,
     183,     2,     0,   181,     0,     9,   114,   116,     0,    15,
      12,     0,    20,     0,    14,    67,    37,    38,    39,    41,
      42,    44,    45,    49,    50,    47,    48,    52,    53,    55,
      57,    59,     2,     2,     2,    80,   187,     0,   174,   164,
       0,   167,   170,   172,   155,   157,   161,     0,   139,   136,
       0,   182,     0,     2,     3,    27,     0,     0,     0,     0,
       0,    35,    13,     0,    11,     0,     0,     0,   173,   165,
     168,     0,   137,   138,   200,   200,     0,     2,     0,   194,
       0,    21,     3,     3,     3,   169,     0,     3,     2,     0,
       0,    18,     0,    61,    63,     0,     0,     0,     0,     3,
       0,    19,     2,   198,     2,   195,   192,     0,     0,   200,
       2,   196,    65,     3,     0,     0,     3,     2,   193,     0,
     197
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -284,   -76,   -66,  -284,  -284,  -284,   -73,  -284,   -90,    18,
      19,   -36,    17,    74,    75,    73,   -25,   -23,  -284,   -72,
     -40,  -284,   -65,   -77,    -1,     3,  -284,   233,  -284,   -84,
       5,  -284,  -284,   246,   -62,  -284,   151,  -284,   -18,   254,
    -284,   156,     6,   -43,  -284,  -284,  -284,    72,  -284,  -111,
     -60,   -12,  -283,  -284,    78,  -151,  -284,    11,  -284,    85,
    -284,  -284,  -284,  -238,  -284,  -284,   278,  -284,  -284
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   163,   216,   107,   108,   261,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   198,   124,   157,    22,    64,    38,    39,    24,    25,
     178,    26,    50,    52,    53,    54,    27,    28,    78,    41,
     238,   149,    42,    58,   143,   144,   145,   146,   147,   180,
     224,   225,   226,   227,   228,   126,   127,   128,   129,   130,
     131,   132,   133,   245,   134,    29,    30,    31,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     155,   156,   138,    23,   161,    40,   302,   321,   155,   156,
     154,    34,   166,   170,   177,   160,    34,    55,   250,   251,
     199,   253,   137,   174,   175,   150,    32,    43,    44,     1,
      45,    46,    23,   176,   207,   208,    51,   155,    35,    63,
       9,    51,    57,    35,    -3,    12,   283,    36,    34,   203,
     204,    65,    36,   221,   248,   217,    51,    59,    33,   321,
     125,    37,   254,    73,    76,   139,   218,   209,   210,   153,
     142,   158,     1,    60,   240,    35,    -3,   140,   284,    49,
     314,   177,   219,     9,   218,   164,   336,   337,    12,   177,
     154,   301,   162,   177,   148,   177,   137,   243,   218,   222,
     176,   223,    36,   249,    74,   235,   252,     1,   176,   237,
     266,   267,   268,    67,   241,    68,   232,    62,     9,   292,
     263,   363,   233,    12,   229,    71,    72,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,     1,   262,   287,   200,   255,   167,   155,
     156,   201,   202,   218,     9,   169,   308,   329,   265,    12,
     168,   244,   218,   312,   357,   239,   291,   171,   311,   313,
     218,   273,   274,   275,   276,   307,   151,   152,   285,   243,
     172,   304,   256,   306,   257,   155,   137,    56,   349,   213,
     181,   182,   183,   214,   297,   353,   215,   355,    -3,   300,
     205,   206,   211,   212,   289,   290,   315,   316,   317,    75,
     341,   342,   184,   366,   185,   220,   186,   230,   370,    56,
     125,   269,   270,   242,   271,   272,   246,   325,   277,   278,
     320,   231,   258,   247,   142,   259,   264,   282,   326,   288,
     296,   298,   155,   155,   299,   303,   218,   305,   309,   179,
     137,   339,   334,   324,   318,   322,   323,   327,   328,   243,
     243,   335,   348,   310,   352,   338,   343,   344,   345,   340,
     137,   347,   346,   331,   360,   350,   358,   354,   359,   367,
     361,   137,   320,   356,   364,   155,   362,   279,   281,   280,
     332,   369,    77,   333,   243,    70,    69,   365,   330,    56,
     368,    75,   137,   295,   234,   293,   286,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,   179,     0,
     179,     1,     2,     3,     4,    79,     5,    80,     6,    81,
       7,     8,     9,    10,    82,    11,    83,    12,    84,    85,
      13,    86,    87,    14,    15,    88,    16,     0,    17,    89,
      18,    90,    19,    20,     0,     0,    21,     0,    91,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
      61,    99,     0,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     1,
       2,     3,     4,    79,     5,    80,     6,    81,     7,     8,
       9,    10,    82,    11,    83,    12,    84,    85,    13,    86,
      87,    14,    15,    88,    16,     0,    17,    89,    18,    90,
      19,    20,     0,     0,    21,     0,    91,    92,    93,    94,
      95,     0,    96,    97,     0,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,    61,     0,
       0,   100,   101,   102,   103,   104,   105,   197,     1,     2,
       3,     4,     0,     5,     0,     6,   106,     7,     8,     9,
      10,     0,    11,     0,    12,     0,     0,    13,     0,     0,
      14,    15,     0,    16,     0,    17,     0,    18,     0,    19,
      20,     0,     0,    21,     0,    79,     0,    80,     0,    81,
       0,     0,     0,     0,    82,     0,    83,     0,    84,    85,
       0,    86,    87,     0,     0,    88,     0,     0,     0,    89,
       0,    90,     0,     0,     0,     0,     0,    61,    91,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
      61,     0,     0,   100,   101,   102,   103,   104,   105,     0,
       1,     2,     3,     4,     0,     5,     0,     6,   106,     7,
       8,     9,    10,     0,    11,     0,    12,     0,    85,    13,
       0,     0,    14,    15,     0,    16,     0,    17,     0,    18,
       0,    19,    20,     0,     0,    21,     0,   135,    92,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,     1,     2,
       0,     4,     0,     0,     0,     6,     0,     7,     8,     9,
      10,     0,    11,     0,    12,     0,    85,    13,     0,     0,
       0,    15,     0,     0,     0,    17,     0,    18,     0,    19,
      20,     0,     0,     0,     0,   135,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     1,     2,     3,     4,
       0,     5,     0,     6,     0,     7,     8,     9,    10,     0,
      11,     0,    12,    85,     0,    13,     0,     0,    14,    15,
       0,    16,     0,    17,     0,    18,     0,    19,    20,    85,
       0,    21,   135,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,    98,
       0,     0,     0,     0,     0,    61,     0,   100,   101,   102,
     103,   104,   105,    85,     0,    98,     0,   222,     0,   223,
     136,   319,   159,   100,   101,   102,   103,   104,   105,    85,
       0,     0,   135,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,    98,
       0,   222,     0,   223,   136,   351,     0,   100,   101,   102,
     103,   104,   105,    85,     0,    98,     0,   222,     0,   223,
     136,     0,     0,   100,   101,   102,   103,   104,   105,    85,
       0,     0,   135,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,    98,
       0,     0,     0,     0,   136,     0,     0,   100,   101,   102,
     103,   104,   105,    85,     0,    98,   260,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,    85,
       0,     0,   135,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,    98,
       0,     0,     0,     0,   310,     0,     0,   100,   101,   102,
     103,   104,   105,    85,     0,    98,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,    85,
       0,     0,   135,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,    85,     0,   173,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,     0,
       0,     0,   135,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,   100,   236,   102,
     103,   104,   105,     1,     2,     3,     4,     0,     5,     0,
       6,     0,     7,     8,     9,    10,     0,    11,     0,    12,
       0,     0,    13,     0,     0,    14,    15,     0,    16,     0,
      17,     0,    18,     0,    19,    20,    47,     0,    21,     1,
       2,     3,     4,     0,     5,     0,     6,     0,     7,     8,
       9,    10,     0,    11,     0,    12,   294,     0,    13,     0,
       0,    14,    15,     0,    16,     0,    17,     0,    18,     0,
      19,    20,     0,     0,    21,     1,     2,     3,     4,     0,
       5,     0,     6,     0,     7,     8,     9,    10,     0,    11,
       0,    12,     0,     0,    13,     0,     0,    14,    15,     0,
      16,     0,    17,     0,    18,     0,    19,    20,     0,     0,
      21,     0,   141,     1,     2,     3,     4,     0,     5,     0,
       6,     0,     7,     8,     9,    10,     0,    11,     0,    12,
       0,     0,    13,     0,     0,    14,    15,     0,    16,     0,
      17,     0,    18,     0,    19,    20,     1,     2,    21,     4,
       0,     0,     0,     6,     0,     7,     8,     9,    10,     0,
      11,     0,    12,     0,     0,    13,     0,     0,     0,    15,
       0,     0,     0,    17,     0,    18,     0,    19,    20
};

static const yytype_int16 yycheck[] =
{
      73,    73,    62,     0,    81,    23,   244,   290,    81,    81,
      72,    40,    85,    89,    98,    80,    40,    35,   169,   170,
     110,   172,    62,    96,    97,    68,    40,    24,    25,     3,
      27,    28,    29,    98,    50,    51,    40,   110,    67,    40,
      14,    40,    36,    67,    55,    19,    55,    76,    40,    77,
      78,    40,    76,   129,   165,   121,    40,    74,    72,   342,
      61,    90,   173,    89,    58,    66,    74,    83,    84,    73,
      67,    90,     3,    90,    73,    67,    87,    66,    87,    72,
      70,   165,    90,    14,    74,    40,   324,   325,    19,   173,
     152,   242,    67,   177,    25,   179,   136,   162,    74,    69,
     165,    71,    76,   168,    68,   148,   171,     3,   173,   149,
     200,   201,   202,    67,    90,    69,    68,    89,    14,    89,
     185,   359,    74,    19,   142,    73,    74,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,     3,   184,   222,    76,    68,    90,   222,
     222,    81,    82,    74,    14,    88,    68,   308,   198,    19,
      67,   162,    74,    68,    68,    25,   226,    67,   258,    74,
      74,   207,   208,   209,   210,   251,    73,    74,   218,   244,
      88,   246,   177,   249,   179,   258,   226,    36,   339,    75,
      45,    46,    47,    85,   234,   346,    86,   348,    54,   239,
      48,    49,    52,    53,    73,    74,   282,   283,   284,    58,
      73,    74,    67,   364,    69,    73,    71,    68,   369,    68,
     221,   203,   204,    88,   205,   206,    67,   303,   211,   212,
     290,    74,    68,    90,   231,    40,    40,    54,   304,    40,
      40,    70,   315,   316,    70,    90,    74,    68,    68,    98,
     290,   327,   317,    90,    70,    70,    70,    68,    18,   324,
     325,   321,   338,    72,    88,    68,   332,   333,   334,    67,
     310,   337,    68,   313,    37,   340,   352,    90,   354,    68,
      90,   321,   342,   349,   360,   358,   358,   213,   215,   214,
     315,   367,    59,   316,   359,    49,    42,   363,   310,   148,
     366,   150,   342,   231,   148,   227,   221,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,    -1,
     179,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    38,    -1,    40,    41,    42,    43,
      44,    -1,    46,    47,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    89,     3,     4,
       5,     6,    -1,     8,    -1,    10,    90,    12,    13,    14,
      15,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      25,    26,    -1,    28,    -1,    30,    -1,    32,    -1,    34,
      35,    -1,    -1,    38,    -1,     7,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,    -1,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    72,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    10,    90,    12,
      13,    14,    15,    -1,    17,    -1,    19,    -1,    21,    22,
      -1,    -1,    25,    26,    -1,    28,    -1,    30,    -1,    32,
      -1,    34,    35,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    17,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,     3,     4,     5,     6,
      -1,     8,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    19,    21,    -1,    22,    -1,    -1,    25,    26,
      -1,    28,    -1,    30,    -1,    32,    -1,    34,    35,    21,
      -1,    38,    40,    41,    42,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    75,    76,    77,
      78,    79,    80,    21,    -1,    67,    -1,    69,    -1,    71,
      72,    73,    90,    75,    76,    77,    78,    79,    80,    21,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    67,
      -1,    69,    -1,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    21,    -1,    67,    -1,    69,    -1,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    21,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    21,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    21,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    21,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    21,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    21,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,     3,     4,     5,     6,    -1,     8,    -1,
      10,    -1,    12,    13,    14,    15,    -1,    17,    -1,    19,
      -1,    -1,    22,    -1,    -1,    25,    26,    -1,    28,    -1,
      30,    -1,    32,    -1,    34,    35,     0,    -1,    38,     3,
       4,     5,     6,    -1,     8,    -1,    10,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    19,    56,    -1,    22,    -1,
      -1,    25,    26,    -1,    28,    -1,    30,    -1,    32,    -1,
      34,    35,    -1,    -1,    38,     3,     4,     5,     6,    -1,
       8,    -1,    10,    -1,    12,    13,    14,    15,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,    26,    -1,
      28,    -1,    30,    -1,    32,    -1,    34,    35,    -1,    -1,
      38,    -1,    40,     3,     4,     5,     6,    -1,     8,    -1,
      10,    -1,    12,    13,    14,    15,    -1,    17,    -1,    19,
      -1,    -1,    22,    -1,    -1,    25,    26,    -1,    28,    -1,
      30,    -1,    32,    -1,    34,    35,     3,     4,    38,     6,
      -1,    -1,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    -1,    32,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    10,    12,    13,    14,
      15,    17,    19,    22,    25,    26,    28,    30,    32,    34,
      35,    38,   115,   116,   119,   120,   122,   127,   128,   156,
     157,   158,    40,    72,    40,    67,    76,    90,   117,   118,
     129,   130,   133,   116,   116,   116,   116,     0,   157,    72,
     123,    40,   124,   125,   126,   129,   127,   133,   134,    74,
      90,    72,    89,   115,   116,   148,   159,    67,    69,   130,
     124,    73,    74,    89,    68,   127,   133,   118,   129,     7,
       9,    11,    16,    18,    20,    21,    23,    24,    27,    31,
      33,    40,    41,    42,    43,    44,    46,    47,    67,    73,
      75,    76,    77,    78,    79,    80,    90,    94,    95,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   113,   115,   146,   147,   148,   149,
     150,   151,   152,   153,   155,    40,    72,   111,   141,   115,
     148,    40,   116,   135,   136,   137,   138,   139,    25,   132,
     134,    73,    74,    73,   125,    97,   110,   114,    90,    90,
     113,   114,    67,    92,    40,    67,    97,    90,    67,    88,
      92,    67,    88,    67,    97,    97,   113,   120,   121,   127,
     140,    45,    46,    47,    67,    69,    71,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    89,   112,    99,
      76,    81,    82,    77,    78,    48,    49,    50,    51,    83,
      84,    52,    53,    75,    85,    86,    93,    93,    74,    90,
      73,    92,    69,    71,   141,   142,   143,   144,   145,   129,
      68,    74,    68,    74,   132,   134,    76,   111,   131,    25,
      73,    90,    88,   113,   115,   154,    67,    90,   140,   113,
     146,   146,   113,   146,   140,    68,   121,   121,    68,    40,
      68,    96,   111,   113,    40,   111,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   103,   103,   104,
     105,   106,    54,    55,    87,   111,   150,   114,    40,    73,
      74,   141,    89,   145,    56,   138,    40,   111,    70,    70,
     111,   146,   154,    90,   113,    68,    93,    92,    68,    68,
      72,    99,    68,    74,    70,    92,    92,    92,    70,    73,
     141,   143,    70,    70,    90,    92,    93,    68,    18,   146,
     142,   111,   107,   108,   113,   141,   154,   154,    68,    92,
      67,    73,    74,    93,    93,    93,    68,    93,    92,   146,
     113,    73,    88,   146,    90,   146,    93,    68,    92,    92,
      37,    90,   110,   154,    92,    93,   146,    68,    93,    92,
     146
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   122,   122,   122,
     122,   123,   122,   124,   124,   125,   125,   126,   127,   127,
     127,   128,   129,   129,   130,   130,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   141,   141,   141,   142,   142,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   146,   146,   146,
     146,   147,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   153,   153,   153,   153,   154,
     154,   155,   155,   155,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     6,     1,     6,     1,     9,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     4,     5,     5,
       6,     0,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     3,     5,     6,     6,     5,
       4,     4,     1,     0,     1,     0,     1,     2,     2,     3,
       1,     2,     1,     0,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     3,     4,     1,     2,     3,     4,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     1,     3,     1,     1,
       1,     2,     8,    12,     5,     8,     9,    14,     8,     1,
       0,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     1,     2
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
        case 2:
#line 136 "compiler_actions.y" /* yacc.c:1646  */
    {
    (yyval.expressionList) = new expression;
    (yyval.expressionList)->instr = quadlist.nextinstr;
}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 141 "compiler_actions.y" /* yacc.c:1646  */
    {
    (yyval.expressionList) = new expression;
    (yyval.expressionList)->nextlist = makelist(quadlist.nextinstr);
    quadlist.emit(GOTOOP,"","","");
}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 147 "compiler_actions.y" /* yacc.c:1646  */
    {
                                (yyval.expressionList) = new expression;
                                string t = (*((yyvsp[0].str)));     
                                STelement *h = currST->lookup(t);
                                (yyval.expressionList)->location = t;
                            }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "compiler_actions.y" /* yacc.c:1646  */
    {
                                (yyval.expressionList) = new expression;
                                typeOf type;
                                type.type_specifier = "int";
                                operatorType op = CPY;
                                (yyval.expressionList)->location = currST->gentemp(type);
                                quadlist.emit(op,(yyval.expressionList)->location, (yyvsp[0].intval));
                                typeUnion *declExp = new typeUnion;
                                declExp->int_val = (yyvsp[0].intval);                     
                                currST->lookup((yyval.expressionList)->location)->initVal = declExp;
                                (yyval.expressionList)->isPointer = 0;

                            }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 166 "compiler_actions.y" /* yacc.c:1646  */
    {
                                (yyval.expressionList) = new expression;
                                typeOf type;
                                type.type_specifier = "double";
                                operatorType op = CPY;
                                (yyval.expressionList)->location = currST->gentemp(type);
                                quadlist.emit(op,(yyval.expressionList)->location, (yyvsp[0].floatval));
                                typeUnion *declExp = new typeUnion;
                                declExp->double_val = (yyvsp[0].floatval);
                                currST->lookup((yyval.expressionList)->location)->initVal = declExp;
                                (yyval.expressionList)->isPointer = 0;
                            }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 178 "compiler_actions.y" /* yacc.c:1646  */
    {
                                (yyval.expressionList) = new expression;
                                typeOf type;
                                type.type_specifier = "char";
                                operatorType op = CPY;
                                (yyval.expressionList)->location = currST->gentemp(type);
                                quadlist.emit(op,(yyval.expressionList)->location, (yyvsp[0].charval));
                                typeUnion *declExp = new typeUnion;
                                declExp->char_val = (yyvsp[0].charval);
                                currST->lookup((yyval.expressionList)->location)->initVal = declExp;
                                (yyval.expressionList)->isPointer = 0;
                            }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 190 "compiler_actions.y" /* yacc.c:1646  */
    {
                                (yyval.expressionList) = new expression;
                                string s = ".LC";
                                string temp = to_string(literal_count);
                                s = s + temp;
                                (yyval.expressionList)->location = s;
                                literal_count++;
                                literals.push_back(*(yyvsp[0].str));
                            }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 199 "compiler_actions.y" /* yacc.c:1646  */
    {   (yyval.expressionList) = (yyvsp[-1].expressionList);}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 202 "compiler_actions.y" /* yacc.c:1646  */
    {     (yyval.expressionList) = (yyvsp[0].expressionList);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 203 "compiler_actions.y" /* yacc.c:1646  */
    {
                                typeOf t = currST->lookup((yyvsp[-3].expressionList)->location)->type;
                                string s;
                                typeOf t1;
                                t1.type_specifier = "int";
                            	int idx;
                            	string s1;
                            	idx = t.idx;
                            	s = currST->gentemp(t1);
                                quadlist.emit(CPY, s, 0);
                                (yyvsp[-3].expressionList) -> inner = new string(s);    
                            	s = *((yyvsp[-3].expressionList)->inner);
                            	s1 = to_string(idx);
                                
                                quadlist.emit(MUL, s, s, s1);
                                quadlist.emit(ADD, s, s, (yyvsp[-1].expressionList)->location);
                                quadlist.emit(MUL, s, s, string("4"));
                                (yyval.expressionList) = (yyvsp[-3].expressionList);
                            }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 222 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 223 "compiler_actions.y" /* yacc.c:1646  */
    {
                                string f = (yyvsp[-3].expressionList)->location;
                                SymbolTable *fsym = globalST.lookup(f)->nextVar;
                                FList *flist = ((yyvsp[-1].fList));
                                list<Fdef*>::iterator it;
                                int c = 0;
                                for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++){
                                    Fdef *f = *it;
                                    c++;
                                    quadlist.emit(PARAM, f->name,"","");
                                }
                                string s = to_string(c);
                        	    quadlist.emit(CALL,f,s,"");
                    		
                            }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 239 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 240 "compiler_actions.y" /* yacc.c:1646  */
    {
                        
                                (yyval.expressionList) = new expression;
                                string s = (yyvsp[-1].expressionList)->location;
                                STelement * f = currST->lookup((yyvsp[-1].expressionList)->location);
                                (yyval.expressionList)->location = currST->gentemp(f->type);

                                if(f->type.arrType=="array"){
                                    string temp = currST->gentemp(f->type);
                                    quadlist.emit(RIGHTINDEX, temp, (yyvsp[-1].expressionList)->location, *((yyvsp[-1].expressionList)->inner));
                                    quadlist.emit(CPY, (yyval.expressionList)->location, temp, "");
                                    quadlist.emit(ADD, temp, temp, "1");
                                    quadlist.emit(LEFTINDEX, (yyvsp[-1].expressionList)->location, temp, *((yyvsp[-1].expressionList)->inner));
                                }
                                else {
                                    quadlist.emit(CPY, (yyval.expressionList)->location, (yyvsp[-1].expressionList)->location, "");
                                    quadlist.emit(ADD, (yyvsp[-1].expressionList)->location, (yyvsp[-1].expressionList)->location, "1");  
                                }   
                            }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 259 "compiler_actions.y" /* yacc.c:1646  */
    {

                                // same as above
                                (yyval.expressionList) = new expression;
                                STelement * f = currST->lookup((yyvsp[-1].expressionList)->location);
                                (yyval.expressionList)->location = currST->gentemp(f->type);
                                if(f->type.arrType=="array"){
                                    string temp = currST->gentemp(f->type);
                                    quadlist.emit(RIGHTINDEX, temp, (yyvsp[-1].expressionList)->location, *((yyvsp[-1].expressionList)->inner));
                                    quadlist.emit(CPY, (yyval.expressionList)->location, temp, "");
                                    quadlist.emit(SUB, temp, temp, "1");
                                    quadlist.emit(LEFTINDEX, (yyvsp[-1].expressionList)->location, temp, *((yyvsp[-1].expressionList)->inner));
                                }
                                else
                                {
                                    quadlist.emit(CPY, (yyval.expressionList)->location, (yyvsp[-1].expressionList)->location, "");
                                    quadlist.emit(SUB, (yyvsp[-1].expressionList)->location, (yyvsp[-1].expressionList)->location, "1");    
                                }
                            }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 278 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 279 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 283 "compiler_actions.y" /* yacc.c:1646  */
    {
                                    Fdef *f = new Fdef;
                                    f->name = (yyvsp[0].expressionList)->location;
                                    (yyval.fList) = new FList;
                                    f->type = &(currST->lookup(f->name)->type);
                                    (yyval.fList)->func_def_list.push_back(f);
                                }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 290 "compiler_actions.y" /* yacc.c:1646  */
    {
                                    Fdef *f = new Fdef;
                                    f->name = (yyvsp[0].expressionList)->location;
                                    (yyval.fList) = new FList;
                                    f->type = &(currST->lookup(f->name)->type);
                                    (yyval.fList) = (yyvsp[-2].fList);
                                    (yyval.fList)->func_def_list.push_back(f);
                                }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 300 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 301 "compiler_actions.y" /* yacc.c:1646  */
    {
                            operatorType op = ADD;
                            (yyval.expressionList) = new expression;
                            typeOf type;
                            type = currST->lookup((yyvsp[0].expressionList)->location)->type;
                            if(type.arrType=="array"){
                                string temp = currST->gentemp(type);
                                quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
                                quadlist.emit(ADD, temp, temp, "1");
                                quadlist.emit(LEFTINDEX, (yyvsp[0].expressionList)->location, temp, *((yyvsp[0].expressionList)->inner));
                            }
                            else
                                quadlist.emit(op, (yyval.expressionList)->location, (yyvsp[0].expressionList)->location, "1");

                            type = currST->lookup((yyvsp[0].expressionList)->location)->type;
                            (yyval.expressionList)->location = currST->gentemp(type);
                            op = CPY;
                            quadlist.emit(op, (yyvsp[0].expressionList)->location, (yyval.expressionList)->location, "");
                        }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 320 "compiler_actions.y" /* yacc.c:1646  */
    {
                            operatorType op = SUB;
                            (yyval.expressionList) = new expression;
                            typeOf type;
                            type = currST->lookup((yyvsp[0].expressionList)->location)->type;
                            (yyval.expressionList)->location = currST->gentemp(type);
                            if(type.arrType=="array"){
                                string temp = currST->gentemp(type);
                                quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
                                quadlist.emit(SUB, temp, temp, "1");
                                quadlist.emit(LEFTINDEX, (yyvsp[0].expressionList)->location, temp, *((yyvsp[0].expressionList)->inner));
                            }
                            else
                                quadlist.emit(op, (yyval.expressionList)->location, (yyvsp[0].expressionList)->location, "1");

                            type = currST->lookup((yyvsp[0].expressionList)->location)->type;
                            (yyval.expressionList)->location = currST->gentemp(type);
                            op = CPY;
                            quadlist.emit(op, (yyvsp[0].expressionList)->location, (yyval.expressionList)->location, "");        
                        }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 340 "compiler_actions.y" /* yacc.c:1646  */
    {
		                    (yyval.expressionList) = new expression;
		                    typeOf type;
		                    type.type_specifier = string("int");
		                    if((yyvsp[-1].charval) == '-'){
		                        (yyval.expressionList) = new expression; 
		                        (yyval.expressionList)->location = currST->gentemp(type);
		                        quadlist.emit(UNARY_SUB,(yyval.expressionList)->location,(yyvsp[0].expressionList)->location,"");
		                    }
		                    else if((yyvsp[-1].charval) == '&'){
		                        (yyval.expressionList) = new expression;
				        	    type.ptrType = "ptr";
				        	    type.PC = 1;
				        	    type.size = 8;
				                (yyval.expressionList)->location = currST->gentemp(type);
				                quadlist.emit(ADDRESS,(yyval.expressionList)->location,(yyvsp[0].expressionList)->location,"");
		                    }
		                    else if((yyvsp[-1].charval) == '*'){
		                        (yyval.expressionList) = new expression; 
		                        (yyval.expressionList)->location = currST->gentemp(type);
		                        quadlist.emit(RTPTR,(yyval.expressionList)->location,(yyvsp[0].expressionList)->location,"");
		                    }
		                    else{	(yyval.expressionList) = (yyvsp[0].expressionList);}
		                }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 364 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 365 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 368 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.charval) = '&';}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 369 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.charval) = '*';}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 370 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.charval) = '+';}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 371 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.charval) = '-';}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 372 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.charval) = '~';}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 373 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.charval) = '!';}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 376 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 377 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 381 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 382 "compiler_actions.y" /* yacc.c:1646  */
    {
								(yyval.expressionList) = new expression;
								typeOf type1, type2, type;
								type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
								type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;


								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
									(yyvsp[0].expressionList)->location = temp;
									(yyvsp[0].expressionList)->type.arrType = ""; 
								}
								if(type1.arrType=="array"){
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
									(yyvsp[-2].expressionList)->location = temp;
									(yyvsp[-2].expressionList)->type.arrType = ""; 
								}
				
								int flag = 0;
								if(type1.type_specifier == type2.type_specifier){
									type.type_specifier = type1.type_specifier;
									flag = 1;
								}
								if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convInt2Dbl(e,(yyvsp[0].expressionList));
									type.type_specifier = type1.type_specifier;
								}
								else if(type1.type_specifier=="int"&&type2.type_specifier=="double"){   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convInt2Dbl(e,(yyvsp[-2].expressionList));
									type.type_specifier = type2.type_specifier;
								}
								if(type1.type_specifier=="double"&& type2.type_specifier=="char"){   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Dbl(e,(yyvsp[0].expressionList));
									type.type_specifier = type1.type_specifier;
						
								}
								if(type1.type_specifier=="char"&& type2.type_specifier=="double"){   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convChar2Dbl(e,(yyvsp[-2].expressionList));
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,(yyvsp[-2].expressionList));
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,(yyvsp[0].expressionList));
									type.type_specifier = type1.type_specifier;
						
								}
								(yyval.expressionList)->location = currST->gentemp(type);
								quadlist.emit(MUL, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);

								}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 469 "compiler_actions.y" /* yacc.c:1646  */
    {

								 (yyval.expressionList) = new expression;
									typeOf type1, type2, type;
									type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
									type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

									if(type2.arrType=="array"){
										string temp = currST->gentemp(type2);
										quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
										(yyvsp[0].expressionList)->location = temp;
										(yyvsp[0].expressionList)->type.arrType = ""; 
									}
									if(type1.arrType=="array"){
										string temp = currST->gentemp(type1);
										quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
										(yyvsp[-2].expressionList)->location = temp;
										(yyvsp[-2].expressionList)->type.arrType = ""; 
									}
									int flag = 0;
									if(type1.type_specifier == type2.type_specifier){
										type.type_specifier = type1.type_specifier;
										flag = 1;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convInt2Dbl(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;

									}
									else if(type1.type_specifier=="int" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convInt2Dbl(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Dbl(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convChar2Dbl(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
						
									}
									if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									(yyval.expressionList)->location = currST->gentemp(type);
									quadlist.emit(DIV, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
								}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 552 "compiler_actions.y" /* yacc.c:1646  */
    {

									(yyval.expressionList) = new expression;
									typeOf type1, type2, type;
									type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
									type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

									if(type2.arrType=="array") {
										string temp = currST->gentemp(type2);
										quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
										(yyvsp[0].expressionList)->location = temp;
										(yyvsp[0].expressionList)->type.arrType = ""; 
									}  
									if(type1.arrType=="array"){
										string temp = currST->gentemp(type1);
										quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
										(yyvsp[-2].expressionList)->location = temp;
										(yyvsp[-2].expressionList)->type.arrType = ""; 
									}
									int flag = 0;
									if(type1.type_specifier == type2.type_specifier){
										type.type_specifier = type1.type_specifier;
										flag = 1;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convInt2Dbl(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									else if(type1.type_specifier=="int" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convInt2Dbl(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Dbl(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="double") {   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convChar2Dbl(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									(yyval.expressionList)->location = currST->gentemp(type);

									quadlist.emit(MOD, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
							}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 636 "compiler_actions.y" /* yacc.c:1646  */
    {(yyval.expressionList) = (yyvsp[0].expressionList);}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 637 "compiler_actions.y" /* yacc.c:1646  */
    {

									(yyval.expressionList) = new expression;
									typeOf type1, type2, type;
									type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
									type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

									if(type2.arrType=="array"){
										string temp = currST->gentemp(type2);
										quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
										(yyvsp[0].expressionList)->location = temp;
										(yyvsp[0].expressionList)->type.arrType = ""; 
									}    
									if(type1.arrType=="array"){
										string temp = currST->gentemp(type1);
										quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
										(yyvsp[-2].expressionList)->location = temp;
										(yyvsp[-2].expressionList)->type.arrType = ""; 
									}   
									int flag = 0;
									if(type1.type_specifier == type2.type_specifier){
										type.type_specifier = type1.type_specifier;
										flag = 1;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convInt2Dbl(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;

									}
									else if(type1.type_specifier=="int" && type2.type_specifier=="double") {   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convInt2Dbl(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Dbl(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convChar2Dbl(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,(yyvsp[-2].expressionList));
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,(yyvsp[0].expressionList));
										type.type_specifier = type1.type_specifier;
									}
									(yyval.expressionList)->location = currST->gentemp(type);
									quadlist.emit(ADD, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);

							}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 720 "compiler_actions.y" /* yacc.c:1646  */
    {

								(yyval.expressionList) = new expression;
								typeOf type1, type2, type;
								type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
								type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
									(yyvsp[0].expressionList)->location = temp;
									(yyvsp[0].expressionList)->type.arrType = ""; 
								}
				
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
									(yyvsp[-2].expressionList)->location = temp;
									(yyvsp[-2].expressionList)->type.arrType = ""; 
								}
				
								int flag = 0;
								if(type1.type_specifier == type2.type_specifier){
									type.type_specifier = type1.type_specifier;
									flag = 1;
								}
								if(type1.type_specifier=="double" && type2.type_specifier=="int")  {   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convInt2Dbl(e,(yyvsp[0].expressionList));
									type.type_specifier = type1.type_specifier;
									}
								else if(type1.type_specifier=="int" && type2.type_specifier=="double")  {   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convInt2Dbl(e,(yyvsp[-2].expressionList));
									type.type_specifier = type2.type_specifier;
								}
								if(type1.type_specifier=="double" && type2.type_specifier=="char") {   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Dbl(e,(yyvsp[0].expressionList));
									type.type_specifier = type1.type_specifier;
						
								}
								if(type1.type_specifier=="char" && type2.type_specifier=="double")  {   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convChar2Dbl(e,(yyvsp[-2].expressionList));
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="char" && type2.type_specifier=="int")  {   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,(yyvsp[-2].expressionList));
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="int" && type2.type_specifier=="char") {   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,(yyvsp[0].expressionList));
									type.type_specifier = type1.type_specifier;
						
								}
								(yyval.expressionList)->location = currST->gentemp(type);
								quadlist.emit(SUB, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
						}
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 809 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 810 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.expressionList) = new expression;
							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 
							}
				
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
								(yyvsp[-2].expressionList)->location = temp;
								(yyvsp[-2].expressionList)->type.arrType = ""; 
							}
							int flag = 0;
				
						   if(type1.type_specifier=="double"){
									type1.type_specifier = "int";
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, "int");
									expression *e = new expression;
									e->location = t;
									e->type.type_specifier = "int";
									quadlist.convDbl2Int(e,(yyvsp[0].expressionList));

						   }
						   else if(type1.type_specifier=="char"){
									type1.type_specifier = "int";
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, "int");
									expression *e = new expression;
									e->location = t;
									e->type.type_specifier = "int";
									quadlist.convChar2Int(e,(yyvsp[0].expressionList));
									//type.type_specifier = type1.type_specifier;
						  }
						  type1.type_specifier = "int";
						  (yyval.expressionList)->location = currST->gentemp(type1);
						  quadlist.emit(SHIFTLEFT, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
						}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 855 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.expressionList) = new expression;
							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
								(yyvsp[-2].expressionList)->location = temp;
								(yyvsp[-2].expressionList)->type.arrType = ""; 
							}
							int flag = 0;
							if(type1.type_specifier=="double"){
								type1.type_specifier = "int";
								string t = currST->gentemp(type1);
								STelement *s = currST->lookup(t, "int");
								expression *e = new expression;
								e->location = t;
								e->type.type_specifier = "int";
							   quadlist.convDbl2Int(e,(yyvsp[0].expressionList));

							}
							else if(type1.type_specifier=="char") {
								type1.type_specifier = "int";
								string t = currST->gentemp(type1);
								STelement *s = currST->lookup(t, "int");
								expression *e = new expression;
								e->location = t;
								e->type.type_specifier = "int";
								quadlist.convChar2Int(e,(yyvsp[0].expressionList));

							}
							type1.type_specifier = "int";
							(yyval.expressionList)->location = currST->gentemp(type1);
							quadlist.emit(SHIFTRIGHT, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
					}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 901 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 902 "compiler_actions.y" /* yacc.c:1646  */
    {
								typeOf type1, type2, type;
								type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
								type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
									(yyvsp[0].expressionList)->location = temp;
									(yyvsp[0].expressionList)->type.arrType = ""; 	
								}  
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
									(yyvsp[-2].expressionList)->location = temp;
									(yyvsp[-2].expressionList)->type.arrType = ""; 
								}
								(yyval.expressionList) = new expression;
								(yyval.expressionList)->type.type_specifier = "bool";
								(yyval.expressionList)->location = currST->gentemp((yyval.expressionList)->type);
								(yyval.expressionList)->truelist = makelist(quadlist.nextinstr);
								(yyval.expressionList)->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_LT, "", (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
								quadlist.emit(GOTOOP,"","","");
							}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 927 "compiler_actions.y" /* yacc.c:1646  */
    {
								typeOf type1, type2, type;
								type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
								type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
									(yyvsp[0].expressionList)->location = temp;
									(yyvsp[0].expressionList)->type.arrType = ""; 
								}
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
									(yyvsp[-2].expressionList)->location = temp;
									(yyvsp[-2].expressionList)->type.arrType = ""; 
								}
								(yyval.expressionList) = new expression;
								(yyval.expressionList)->type.type_specifier = "bool";
								(yyval.expressionList)->location = currST->gentemp((yyval.expressionList)->type);
								(yyval.expressionList)->truelist = makelist(quadlist.nextinstr);
								(yyval.expressionList)->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_GT, "", (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
								quadlist.emit(GOTOOP,"","","");
							}
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 952 "compiler_actions.y" /* yacc.c:1646  */
    {
								typeOf type1, type2, type;
								type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
								type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
									(yyvsp[0].expressionList)->location = temp;
									(yyvsp[0].expressionList)->type.arrType = ""; //check
								}    
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
									(yyvsp[-2].expressionList)->location = temp;
									(yyvsp[-2].expressionList)->type.arrType = ""; 
								}
								(yyval.expressionList) = new expression;
								(yyval.expressionList)->type.type_specifier = "bool";
								(yyval.expressionList)->location = currST->gentemp((yyval.expressionList)->type);
								(yyval.expressionList)->truelist = makelist(quadlist.nextinstr);
								(yyval.expressionList)->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_LE, "", (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
								quadlist.emit(GOTOOP,"","","");
							}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 977 "compiler_actions.y" /* yacc.c:1646  */
    {
								typeOf type1, type2, type;
								type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
								type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
									(yyvsp[0].expressionList)->location = temp;
									(yyvsp[0].expressionList)->type.arrType = ""; 
								}       
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
									(yyvsp[-2].expressionList)->location = temp;
									(yyvsp[-2].expressionList)->type.arrType = ""; 
								}       
								(yyval.expressionList) = new expression;
								(yyval.expressionList)->type.type_specifier = "bool";
								(yyval.expressionList)->location = currST->gentemp((yyval.expressionList)->type);
								(yyval.expressionList)->truelist = makelist(quadlist.nextinstr);
								(yyval.expressionList)->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_GE, "", (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
								quadlist.emit(GOTOOP,"","","");
							}
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1005 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1006 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 	
							}   
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
								(yyvsp[-2].expressionList)->location = temp;
								(yyvsp[-2].expressionList)->type.arrType = ""; 
							}
				
							(yyval.expressionList) = new expression;
							(yyval.expressionList)->type.type_specifier = "bool";
							(yyval.expressionList)->location = currST->gentemp((yyval.expressionList)->type);
							(yyval.expressionList)->truelist = makelist(quadlist.nextinstr);
							(yyval.expressionList)->falselist = makelist(quadlist.nextinstr + 1);
							quadlist.emit(IF_EQ,"",(yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
							quadlist.emit(GOTOOP,"","","");
				   		}
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1032 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; //check
							}
				
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
								(yyvsp[-2].expressionList)->location = temp;
								(yyvsp[-2].expressionList)->type.arrType = ""; //check
							}
				
							(yyval.expressionList) = new expression;
							(yyval.expressionList)->type.type_specifier = "bool";
							(yyval.expressionList)->location = currST->gentemp((yyval.expressionList)->type);
							(yyval.expressionList)->truelist = makelist(quadlist.nextinstr);
							(yyval.expressionList)->falselist = makelist(quadlist.nextinstr + 1);
							quadlist.emit(IF_NEQ,"",(yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
							quadlist.emit(GOTOOP,"","","");
							}
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1061 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1062 "compiler_actions.y" /* yacc.c:1646  */
    {
						typeOf type1, type2, type;
						type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
						type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

						if(type2.arrType=="array"){
							string temp = currST->gentemp(type2);
							quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
							(yyvsp[0].expressionList)->location = temp;
							(yyvsp[0].expressionList)->type.arrType = ""; //check
						}
				
						if(type1.arrType=="array") {
							string temp = currST->gentemp(type1);
							quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
							(yyvsp[-2].expressionList)->location = temp;
							(yyvsp[-2].expressionList)->type.arrType = ""; //check
						}
				
						(yyval.expressionList) = new expression;
						STelement *f = currST->lookup((yyvsp[-2].expressionList)->location);//check
						typeOf t;
						t = f->type;
						(yyval.expressionList)->location = currST->gentemp(t);
						quadlist.emit(LOGICAL_AND, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
			   	 }
#line 3046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1091 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1092 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
								(yyvsp[-2].expressionList)->location = temp;
								(yyvsp[-2].expressionList)->type.arrType = ""; 
							}
				
							(yyval.expressionList) = new expression;
							STelement *f = currST->lookup((yyvsp[-2].expressionList)->location);
							typeOf t;
							t = f->type;
							(yyval.expressionList)->location = currST->gentemp(t);
							quadlist.emit(BINARYXOR, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
						}
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1119 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1120 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-2].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
								(yyvsp[-2].expressionList)->location = temp;
								(yyvsp[-2].expressionList)->type.arrType = ""; 
							}
				
							(yyval.expressionList) = new expression;
							STelement *f = currST->lookup((yyvsp[-2].expressionList)->location);
							typeOf t;
							t = f->type;
							(yyval.expressionList)->location = currST->gentemp(t);
							quadlist.emit(BINARYOR, (yyval.expressionList)->location, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location);
						}
#line 3118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1147 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1148 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2;
							type1 = currST->lookup((yyvsp[-5].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[-1].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-1].expressionList)->location, *((yyvsp[-1].expressionList)->inner));
								(yyvsp[-1].expressionList)->location = temp;
								(yyvsp[-1].expressionList)->type.arrType = "";
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-5].expressionList)->location, *((yyvsp[-5].expressionList)->inner));
								(yyvsp[-5].expressionList)->location = temp;
								(yyvsp[-5].expressionList)->type.arrType = ""; 
							}
				
							typeOf type;
							type.type_specifier = "bool";
							(yyval.expressionList) = new expression;
							(yyval.expressionList)->type = type;

							quadlist.backpatch((yyvsp[-4].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-5].expressionList));

							quadlist.backpatch((yyvsp[0].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-1].expressionList));

							quadlist.backpatch((yyvsp[-5].expressionList)->truelist, (yyvsp[-2].expressionList)->instr);
							(yyval.expressionList)->truelist = (yyvsp[-1].expressionList)->truelist;
							(yyval.expressionList)->falselist = merge((yyvsp[-5].expressionList)->falselist, (yyvsp[-1].expressionList)->falselist);

						}
#line 3163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1184 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1185 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2;
							type1 = currST->lookup((yyvsp[-5].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[-1].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-1].expressionList)->location, *((yyvsp[-1].expressionList)->inner));
								(yyvsp[-1].expressionList)->location = temp;
								(yyvsp[-1].expressionList)->type.arrType = ""; //check
							}    
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-5].expressionList)->location, *((yyvsp[-5].expressionList)->inner));
								(yyvsp[-5].expressionList)->location = temp;
								(yyvsp[-5].expressionList)->type.arrType = ""; //check
							}
				
							typeOf type;
							type.type_specifier = "bool";
							(yyval.expressionList) = new expression;
							(yyval.expressionList)->type = type;
							quadlist.backpatch((yyvsp[-4].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-5].expressionList));

							quadlist.backpatch((yyvsp[0].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-1].expressionList));

							quadlist.backpatch((yyvsp[-5].expressionList)->falselist, (yyvsp[-2].expressionList)->instr);
							(yyval.expressionList)->truelist = merge((yyvsp[-5].expressionList)->truelist, (yyvsp[-1].expressionList)->truelist);
							(yyval.expressionList)->falselist = (yyvsp[-1].expressionList)->falselist;
						}
#line 3206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1220 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1221 "compiler_actions.y" /* yacc.c:1646  */
    {
							typeOf type1, type2;
							type1 = currST->lookup((yyvsp[-4].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 
							}	
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[-4].expressionList)->location, *((yyvsp[-4].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = "";
							}
				
							(yyval.expressionList) = new expression;
							list<int> I;
							typeOf type;
							type = currST->lookup((yyvsp[-4].expressionList)->location)->type;
							(yyval.expressionList)->location = currST->gentemp(type);
							quadlist.emit(CPY, (yyval.expressionList)->location, (yyvsp[0].expressionList)->location,"");
							I = makelist(quadlist.nextinstr);
							quadlist.emit(GOTOOP,"","","");
							quadlist.backpatch((yyvsp[-3].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.emit(CPY, (yyval.expressionList)->location, (yyvsp[-4].expressionList)->location, "");
							I = merge(I, makelist(quadlist.nextinstr));
							quadlist.emit(GOTOOP,"", "", "");
							quadlist.backpatch((yyvsp[-7].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-8].expressionList));
							quadlist.backpatch((yyvsp[-8].expressionList)->truelist, (yyvsp[-5].expressionList)->instr);
							quadlist.backpatch((yyvsp[-8].expressionList)->falselist, (yyvsp[-1].expressionList)->instr);
							quadlist.backpatch(I, quadlist.nextinstr);
						}
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1261 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1262 "compiler_actions.y" /* yacc.c:1646  */
    {

							typeOf type1, type2, type;
							type1 = currST->lookup((yyvsp[-2].expressionList)->location)->type;
							type2 = currST->lookup((yyvsp[0].expressionList)->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, (yyvsp[0].expressionList)->location, *((yyvsp[0].expressionList)->inner));
								(yyvsp[0].expressionList)->location = temp;
								(yyvsp[0].expressionList)->type.arrType = ""; 
							}
							if(type1.arrType=="array") 
								quadlist.emit(LEFTINDEX, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location, *((yyvsp[-2].expressionList)->inner));
							else
								quadlist.emit(CPY, (yyvsp[-2].expressionList)->location, (yyvsp[0].expressionList)->location, "");
							(yyval.expressionList) = (yyvsp[-2].expressionList);
						}
#line 3282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1283 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1284 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1285 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1286 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1287 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1288 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1289 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1290 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1291 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1292 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1293 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1296 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.expressionList) = (yyvsp[0].expressionList);}
#line 3354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1297 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 3360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1300 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1305 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1306 "compiler_actions.y" /* yacc.c:1646  */
    {

					initDecList *new_dec = new initDecList;
					new_dec = (yyvsp[-1].initDeclist);
					int size = 0;
					typeOf *type = (yyvsp[-2].type_);
					if(type->type_specifier=="int") size = 4;
					if(type->type_specifier=="double") size = 8;
					if(type->type_specifier=="char") size = 1;

					list<declaration*>::iterator it;
					for(it = (yyvsp[-1].initDeclist)->declist.begin(); it != (yyvsp[-1].initDeclist)->declist.end(); it++)
					{
						declaration *new_dec = *it;
						if(new_dec->type!=NULL){
							if(new_dec->type->type_specifier.compare("function")==0)
							{
								string name = new_dec->decl;

								currST = &globalST;
								quadlist.emit(_FUNC_END,name,"","");

							}
						
							STelement *ret, *f;
							SymbolTable *nest;
							if(new_dec->type->type_specifier.compare("function")==0)
							{
								f = currST->lookup(new_dec->decl, type->type_specifier);
								nest = f->nextVar;
								ret = nest->lookup("retVal", type->type_specifier, new_dec->PC);
								f->offset = currST->offset;
								f->size = size;
								f->initVal = NULL;
								continue;
							}
						}
						STelement *f1 = currST->lookup(new_dec->decl, type->type_specifier);

						f1->nextVar = NULL;

						if(new_dec->alist == vector<int>() && new_dec->PC == 0)
						{
						    f1->offset = currST->offset;
						    f1->type = *type;
						    f1 = currST->lookup(new_dec->decl, type->type_specifier);
						    if(new_dec->declExp){
						        string x = new_dec->declExp->location;
						        quadlist.emit(CPY, new_dec->decl, x, "");
						        f1->initVal = currST->lookup(x,f1->type.type_specifier)->initVal;
						    }
						    else
						        new_dec->declExp = NULL;
						}
						else if(new_dec -> PC > 0)
						{
						    STelement *sp;
						    for(sp = currST->ST; sp < &currST->ST[currST->count]; sp++){
						        if(!sp->name.empty() && sp->name!=new_dec->decl){
						            sp->offset = currST->offset-4;
						            sp->PC = new_dec->PC;
						            sp->type = *type;
						            sp->type.ptrType = "ptr";
						            sp->size = 4;
						        }
						    }
						}

						else if(new_dec->alist!=vector<int>()){
						    STelement *sp;
						    for(sp = currST->ST; sp < &currST->ST[currST->count]; sp++){
						        if(!sp->name.empty() && !sp->name.compare(new_dec->decl)){
						            int temp_size = size;
						            sp->offset = currST->offset-4;
						            sp->type = *type;
									sp->type.type_specifier = type->type_specifier;
						            sp->type.arrType = "array";
						            sp->type.ptrType = "";

						            for(int i = 0; i < new_dec->alist.size(); i++){
						                sp->type.typeList.push_back(new_dec->alist[i]);
						            }
						            for (int i = 0; i < sp->type.typeList.size(); ++i){
						                temp_size = temp_size * sp->type.typeList[i];
						            }
						            sp->size = temp_size;
						            currST->offset = currST->offset + temp_size;
						        }
						    }
						}
					}
				}
#line 3469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1401 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1402 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1403 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.type_) = (yyvsp[0].type_);}
#line 3487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1404 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1405 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1406 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1407 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1408 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1413 "compiler_actions.y" /* yacc.c:1646  */
    { 
								(yyval.initDeclist) = new initDecList;
								(yyval.initDeclist)->declist.push_back((yyvsp[0].decList));
							}
#line 3526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1417 "compiler_actions.y" /* yacc.c:1646  */
    {
								(yyvsp[-2].initDeclist)->declist.push_back((yyvsp[0].decList));
								(yyval.initDeclist) = (yyvsp[-2].initDeclist);
							}
#line 3535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1425 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.decList) = (yyvsp[0].decList);
						(yyval.decList)->declExp = NULL;
					}
#line 3544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1429 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.decList) = (yyvsp[-2].decList);
						(yyval.decList)->declExp = (yyvsp[0].expressionList);
					}
#line 3553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1440 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1443 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.type_) = new typeOf;
						(yyval.type_)->type_specifier = string("void"); 
				}
#line 3568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1447 "compiler_actions.y" /* yacc.c:1646  */
    {
				    (yyval.type_) = new typeOf;
					(yyval.type_)->type_specifier = string("char");
					(yyval.type_)->next = NULL;

				}
#line 3579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1453 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 3585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1454 "compiler_actions.y" /* yacc.c:1646  */
    {
				    (yyval.type_) = new typeOf;
					(yyval.type_)->type_specifier = string("int");
					(yyval.type_)->next = NULL;
				}
#line 3595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1459 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 3601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1460 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 3607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1461 "compiler_actions.y" /* yacc.c:1646  */
    {
					(yyval.type_) = new typeOf;
					(yyval.type_)->type_specifier = string("double");
					(yyval.type_)->next = NULL;
				}
#line 3617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1466 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1467 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1468 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1469 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1470 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1471 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1474 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.type_) = (yyvsp[0].type_);}
#line 3659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1475 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1476 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1477 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 3677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1485 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1486 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1491 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1496 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1499 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1505 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1509 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1512 "compiler_actions.y" /* yacc.c:1646  */
    {
				(yyval.decList) = (yyvsp[0].decList);
				(yyval.decList)->PC = (yyvsp[-1].type_)->PC;
			}
#line 3728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1516 "compiler_actions.y" /* yacc.c:1646  */
    {
				(yyval.decList) = (yyvsp[0].decList);
				(yyval.decList)->PC = 0;

			}
#line 3738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1525 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.decList) = new declaration; 
							(yyval.decList)->decl = *((yyvsp[0].str));
						}
#line 3747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1529 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.decList) = (yyvsp[-1].decList);}
#line 3753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1530 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.decList) = (yyvsp[-4].decList);
							int idx = currST->lookup((yyvsp[-1].expressionList)->location)->initVal->int_val;
							(yyval.decList)->alist.push_back(idx);
						}
#line 3763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1535 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1536 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1537 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1538 "compiler_actions.y" /* yacc.c:1646  */
    {

							list<Fdef*> l = (yyvsp[-1].fList)->func_def_list;
							SymbolTable *nextST = new SymbolTable;
							(yyval.decList) = (yyvsp[-3].decList);
							string name = (yyval.decList)->decl;
							(yyval.decList)->type = new typeOf;
							(yyval.decList)->type->type_specifier = string("function");
							(yyval.decList)->type->numParam = l.size();
							STelement *func_lookup = St->lookup((yyval.decList)->decl, (yyval.decList)->type->type_specifier);

							for(int i=0; i < St->count; i++){
								if(St->ST[i].name==(yyval.decList)->decl){
									St->ST[i].type.type_specifier = "function";
									St->ST[i].type.numParam = l.size();
								}
							}

							func_lookup -> nextVar = nextST;
							list<Fdef*>::iterator it;
							for(it = l.begin(); it != l.end(); it++) {
								Fdef *temp = *it;
								nextST -> lookup(temp->name, temp->type->type_specifier);
								for(int i = 0; i<nextST->count; i++){
									if(nextST->ST[i].name==temp->name){
										if(temp->type->arrType=="array"){
											nextST->ST[i].type.arrType = "array";
											nextST->ST[i].type.idx = temp->type->idx;
										}
									}
								}
							}

							STelement *sp;
							for(sp = St->ST; sp < &St->ST[St->count]; sp++){
								if(!sp->name.empty() && !sp->name.compare((yyval.decList)->decl)) {
									sp->nextVar = nextST;
								}
							}
							currST = nextST;
							quadlist.emit(_FUNC_START, name,"","");
						}
#line 3828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1580 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1590 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1595 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1599 "compiler_actions.y" /* yacc.c:1646  */
    {
					(yyval.type_) = new typeOf;
					(yyval.type_)->type_specifier = string("ptr");
					(yyval.type_)->next = NULL;
					(yyval.type_)->ptrType = string("ptr");
					(yyval.type_)->PC = 1;
		   	 }
#line 3858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1606 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1607 "compiler_actions.y" /* yacc.c:1646  */
    {
					(yyval.type_) = new typeOf;
					(yyval.type_)->type_specifier = string("ptr");
					(yyval.type_)->next = NULL;
					(yyval.type_)->ptrType = string("ptr");
					(yyval.type_)->PC = (yyvsp[0].type_)->PC + 1; 
				}
#line 3876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1614 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1619 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1624 "compiler_actions.y" /* yacc.c:1646  */
    { 	(yyval.fList) = new FList; }
#line 3894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1627 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.fList) = new FList;
						(yyval.fList) = (yyvsp[0].fList);
					}
#line 3903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1631 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1634 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.fList) = new FList;
						(yyval.fList)->func_def_list.push_back((yyvsp[0].fDef));
					}
#line 3918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1638 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyvsp[-2].fList)->func_def_list.push_back((yyvsp[0].fDef));
						(yyval.fList) = (yyvsp[-2].fList);
					}
#line 3927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1644 "compiler_actions.y" /* yacc.c:1646  */
    {
									(yyval.fDef) = new Fdef;
									(yyval.fDef)->type = (yyvsp[-1].type_);
								if((yyvsp[0].decList)->alist.size()>0)
									{(yyval.fDef)->type->arrType = "array";(yyval.fDef)->type->idx = (yyvsp[0].decList)->alist[0];(yyval.fDef)->type->type_specifier = (yyvsp[-1].type_)->type_specifier;
								}
								for(int i=0; i<currST->count; i++){
									if(currST->ST[i].name.compare((yyvsp[0].decList)->decl)==0){
										if((yyvsp[0].decList)->type->arrType=="array" || currST->ST[i].type.arrType=="array"){
											currST->ST[i].type.arrType = "array";
											(yyval.fDef)->type->arrType = "array";
										}
									}
								}
								(yyval.fDef)->name = (yyvsp[0].decList)->decl;
							}
#line 3948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1660 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1666 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1670 "compiler_actions.y" /* yacc.c:1646  */
    {	 (yyval.type_) = (yyvsp[0].type_);}
#line 3966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1674 "compiler_actions.y" /* yacc.c:1646  */
    {	 (yyval.expressionList) = (yyvsp[0].expressionList);}
#line 3972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1675 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1676 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 3984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1680 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1681 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 3996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1682 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1683 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1688 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1694 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1699 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1703 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1704 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1705 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1706 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1707 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1708 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1714 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1718 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1719 "compiler_actions.y" /* yacc.c:1646  */
    {	(yyval.expressionList) = (yyvsp[-1].expressionList);}
#line 4080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1722 "compiler_actions.y" /* yacc.c:1646  */
    {
					(yyval.expressionList) = (yyvsp[0].expressionList);
					quadlist.backpatch((yyvsp[0].expressionList)->nextlist, quadlist.nextinstr);
					}
#line 4089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1726 "compiler_actions.y" /* yacc.c:1646  */
    {
					quadlist.backpatch((yyvsp[-2].expressionList)->nextlist, (yyvsp[-1].expressionList)->instr);
					(yyval.expressionList) = new expression;
					(yyval.expressionList)->nextlist = (yyvsp[0].expressionList)->nextlist;

				}
#line 4100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1734 "compiler_actions.y" /* yacc.c:1646  */
    { 	(yyval.expressionList) = new expression; }
#line 4106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1736 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1739 "compiler_actions.y" /* yacc.c:1646  */
    { 	 (yyval.expressionList) = new expression; }
#line 4118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1740 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1743 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.expressionList) = new expression;
							quadlist.backpatch((yyvsp[-4].expressionList)->nextlist, quadlist.nextinstr);

							quadlist.conv2Bool((yyvsp[-5].expressionList));
				
							quadlist.backpatch((yyvsp[-5].expressionList)->truelist, (yyvsp[-2].expressionList)->instr);

							(yyval.expressionList)->nextlist = merge((yyvsp[0].expressionList)->nextlist, (yyvsp[-1].expressionList)->nextlist);
							(yyval.expressionList)->nextlist = merge((yyval.expressionList)->nextlist, (yyvsp[-5].expressionList)->falselist);
						}
#line 4140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1754 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.expressionList) = new expression;
							quadlist.backpatch((yyvsp[-8].expressionList)->nextlist , quadlist.nextinstr);

							quadlist.conv2Bool((yyvsp[-9].expressionList));

							(yyval.expressionList)->nextlist = merge((yyvsp[-5].expressionList)->nextlist, (yyvsp[-4].expressionList)->nextlist);
							quadlist.backpatch((yyvsp[-9].expressionList)->truelist, (yyvsp[-6].expressionList)->instr);
							quadlist.backpatch((yyvsp[-9].expressionList)->falselist, (yyvsp[-2].expressionList)->instr);
							(yyval.expressionList)->nextlist = merge((yyval.expressionList)->nextlist, (yyvsp[0].expressionList)->nextlist);
							(yyval.expressionList)->nextlist = merge((yyval.expressionList)->nextlist, (yyvsp[-1].expressionList)->nextlist);
						}
#line 4157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1766 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1769 "compiler_actions.y" /* yacc.c:1646  */
    {
							quadlist.emit(GOTOOP,"","","");
							quadlist.backpatch(makelist(quadlist.nextinstr-1),(yyvsp[-6].expressionList)->instr);    

							quadlist.backpatch((yyvsp[-3].expressionList)->nextlist,quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-4].expressionList));

							(yyval.expressionList) = new expression;
							quadlist.backpatch((yyvsp[0].expressionList)->nextlist, (yyvsp[-6].expressionList)->instr);
							quadlist.backpatch((yyvsp[-4].expressionList)->truelist, (yyvsp[-1].expressionList)->instr);
							(yyval.expressionList)->nextlist = (yyvsp[-4].expressionList)->falselist;
						}
#line 4180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1781 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.expressionList) = new expression;
							quadlist.conv2Bool((yyvsp[-2].expressionList));
							quadlist.backpatch((yyvsp[-6].expressionList)->nextlist, (yyvsp[-5].expressionList)->instr);
							quadlist.backpatch((yyvsp[-2].expressionList)->truelist, (yyvsp[-7].expressionList)->instr);
							(yyval.expressionList)->nextlist = (yyvsp[-2].expressionList)->falselist;
						}
#line 4192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1788 "compiler_actions.y" /* yacc.c:1646  */
    {
							(yyval.expressionList) = new expression;
		
							quadlist.emit(GOTOOP,"","","");
							quadlist.backpatch(makelist(quadlist.nextinstr-1),(yyvsp[-5].expressionList)->instr);    
							quadlist.backpatch((yyvsp[-7].expressionList)->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool((yyvsp[-8].expressionList));

							quadlist.backpatch((yyvsp[-3].expressionList)->nextlist,(yyvsp[-9].expressionList)->instr);
							quadlist.backpatch((yyvsp[-8].expressionList)->truelist,(yyvsp[-1].expressionList)->instr);
							quadlist.backpatch((yyvsp[0].expressionList)->nextlist,(yyvsp[-5].expressionList)->instr);
		
							(yyval.expressionList)->nextlist = (yyvsp[-8].expressionList)->falselist;
						}
#line 4211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1802 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1806 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1807 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1810 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1811 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1812 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1813 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.expressionList) = new expression;

						if(currST->lookup("retVal")->type.type_specifier=="void"){
							quadlist.emit(RETURN_VOID,"","","");
						}
			   		}
#line 4259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1820 "compiler_actions.y" /* yacc.c:1646  */
    {
						(yyval.expressionList) = new expression;
						typeOf type1, type2, type3;
						type1 = currST->lookup("retVal")->type;
						type2 = currST->lookup((yyvsp[-1].expressionList)->location)->type;
						for(int i=0; i<St->count;i++) {
							if(St->ST[i].name==(yyvsp[-1].expressionList)->location)
								type3 = St->ST[i].type;
						}
						if(type3.type_specifier=="function"){	
							string t = currST->gentemp(type1);
							quadlist.emit(CPY, t, (yyvsp[-1].expressionList)->location, "");
							quadlist.emit(RETURN,t,"","");
						}
						else if(type1.type_specifier == type2.type_specifier)
								quadlist.emit(RETURN, (yyvsp[-1].expressionList)->location, "", "");
				}
#line 4281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1842 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1843 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1847 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1848 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1852 "compiler_actions.y" /* yacc.c:1646  */
    { }
#line 4311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1853 "compiler_actions.y" /* yacc.c:1646  */
    {
						declaration *new_dec = (yyvsp[-1].decList);
							int size = 0;
							typeOf *type = (yyvsp[-2].type_);
							if(type->type_specifier=="int") size = 4;
							if(type->type_specifier=="double") size = 8;
							if(type->type_specifier=="char") size = 1;
							if(type->type_specifier=="void") size = 0;

							SymbolTable *gt = &globalST;
							quadlist.emit(_FUNC_END,new_dec->decl,"","");
							STelement *func = gt->lookup((yyvsp[-1].decList)->decl);

							if(func->nextVar) {
								if((yyvsp[-1].decList)->PC>0)
									type->ptrType = "ptr";
								STelement *ret = func->nextVar->lookup("retVal", type->type_specifier, (yyvsp[-1].decList)->PC);
							
								if((yyvsp[-1].decList)->PC>0) {
									ret->PC = (yyvsp[-1].decList)->PC;
									ret->type.ptrType = "ptr";
								}
								ret->offset = currST->offset;
								ret->size = size;
								ret->initVal = NULL;
							}
							currST = gt;
							(yyval.decList) = (yyvsp[-1].decList);
					}
#line 4345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1884 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1885 "compiler_actions.y" /* yacc.c:1646  */
    {}
#line 4357 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4361 "y.tab.c" /* yacc.c:1646  */
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
#line 1888 "compiler_actions.y" /* yacc.c:1906  */

void yyerror(string s) 
{
	cout << s << endl;
}
