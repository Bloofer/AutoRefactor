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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "pt_j.y" /* yacc.c:339  */

#include "ptree.h"

using namespace std;

#line 72 "pt_j.tab.cc" /* yacc.c:339  */

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
   by #include "pt_j.tab.hh".  */
#ifndef YY_YY_PT_J_TAB_HH_INCLUDED
# define YY_YY_PT_J_TAB_HH_INCLUDED
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
    PLUS_TK = 258,
    MINUS_TK = 259,
    MULT_TK = 260,
    DIV_TK = 261,
    REM_TK = 262,
    LS_TK = 263,
    SRS_TK = 264,
    ZRS_TK = 265,
    AND_TK = 266,
    XOR_TK = 267,
    OR_TK = 268,
    BOOL_AND_TK = 269,
    BOOL_OR_TK = 270,
    EQ_TK = 271,
    NEQ_TK = 272,
    GT_TK = 273,
    GTE_TK = 274,
    LT_TK = 275,
    LTE_TK = 276,
    PLUS_ASSIGN_TK = 277,
    MINUS_ASSIGN_TK = 278,
    MULT_ASSIGN_TK = 279,
    DIV_ASSIGN_TK = 280,
    REM_ASSIGN_TK = 281,
    LS_ASSIGN_TK = 282,
    SRS_ASSIGN_TK = 283,
    ZRS_ASSIGN_TK = 284,
    AND_ASSIGN_TK = 285,
    XOR_ASSIGN_TK = 286,
    OR_ASSIGN_TK = 287,
    PUBLIC_TK = 288,
    PRIVATE_TK = 289,
    PROTECTED_TK = 290,
    STATIC_TK = 291,
    FINAL_TK = 292,
    SYNCHRONIZED_TK = 293,
    VOLATILE_TK = 294,
    TRANSIENT_TK = 295,
    NATIVE_TK = 296,
    PAD_TK = 297,
    ABSTRACT_TK = 298,
    STRICT_TK = 299,
    MODIFIER_TK = 300,
    DECR_TK = 301,
    INCR_TK = 302,
    DEFAULT_TK = 303,
    IF_TK = 304,
    THROW_TK = 305,
    BOOLEAN_TK = 306,
    DO_TK = 307,
    IMPLEMENTS_TK = 308,
    THROWS_TK = 309,
    BREAK_TK = 310,
    IMPORT_TK = 311,
    ELSE_TK = 312,
    INSTANCEOF_TK = 313,
    RETURN_TK = 314,
    VOID_TK = 315,
    CATCH_TK = 316,
    INTERFACE_TK = 317,
    CASE_TK = 318,
    EXTENDS_TK = 319,
    FINALLY_TK = 320,
    SUPER_TK = 321,
    WHILE_TK = 322,
    CLASS_TK = 323,
    SWITCH_TK = 324,
    CONST_TK = 325,
    TRY_TK = 326,
    FOR_TK = 327,
    NEW_TK = 328,
    CONTINUE_TK = 329,
    GOTO_TK = 330,
    PACKAGE_TK = 331,
    THIS_TK = 332,
    ASSERT_TK = 333,
    ENUM_TK = 334,
    BYTE_TK = 335,
    SHORT_TK = 336,
    INT_TK = 337,
    LONG_TK = 338,
    CHAR_TK = 339,
    INTEGRAL_TK = 340,
    FLOAT_TK = 341,
    DOUBLE_TK = 342,
    FP_TK = 343,
    ID_TK = 344,
    REL_QM_TK = 345,
    REL_CL_TK = 346,
    NOT_TK = 347,
    NEG_TK = 348,
    AT_TK = 349,
    ASSIGN_ANY_TK = 350,
    ASSIGN_TK = 351,
    ELLIPSIS_TK = 352,
    OP_TK = 353,
    CP_TK = 354,
    OCB_TK = 355,
    CCB_TK = 356,
    OSB_TK = 357,
    CSB_TK = 358,
    SC_TK = 359,
    C_TK = 360,
    DOT_TK = 361,
    STRING_LIT_TK = 362,
    CHAR_LIT_TK = 363,
    INT_LIT_TK = 364,
    FP_LIT_TK = 365,
    TRUE_TK = 366,
    FALSE_TK = 367,
    BOOL_LIT_TK = 368,
    NULL_TK = 369
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "pt_j.y" /* yacc.c:355  */

Tree *t;

#line 231 "pt_j.tab.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_PT_J_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 14 "pt_j.y" /* yacc.c:358  */

void yyerror(char*s);
int yylex(YYSTYPE *yylvalp);

Tree *root;

#line 253 "pt_j.tab.cc" /* yacc.c:358  */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  192
/* YYNRULES -- Number of rules.  */
#define YYNRULES  638
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1016

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   369

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   383,   383,   395,   406,   417,   428,   439,   450,   461,
     472,   483,   494,   505,   516,   527,   538,   549,   560,   571,
     582,   593,   604,   615,   626,   637,   648,   659,   676,   687,
     698,   715,   732,   749,   760,   771,   782,   805,   817,   823,
     834,   845,   856,   873,   890,   907,   930,   941,   958,   969,
     986,  1009,  1038,  1049,  1066,  1083,  1106,  1117,  1128,  1151,
    1180,  1191,  1208,  1225,  1248,  1283,  1324,  1347,  1376,  1405,
    1440,  1451,  1468,  1485,  1520,  1555,  1566,  1589,  1600,  1611,
    1634,  1651,  1674,  1685,  1696,  1707,  1736,  1759,  1776,  1805,
    1858,  1869,  1886,  1897,  1914,  1937,  1954,  1965,  1976,  1987,
    1998,  2009,  2020,  2031,  2060,  2071,  2088,  2099,  2110,  2121,
    2132,  2143,  2150,  2161,  2178,  2189,  2206,  2217,  2228,  2239,
    2250,  2261,  2272,  2283,  2294,  2305,  2316,  2327,  2338,  2349,
    2360,  2371,  2412,  2447,  2494,  2535,  2552,  2563,  2580,  2603,
    2626,  2649,  2666,  2677,  2700,  2711,  2734,  2745,  2768,  2785,
    2796,  2820,  2826,  2843,  2860,  2872,  2878,  2895,  2906,  2917,
    2940,  2957,  2974,  2997,  3008,  3025,  3036,  3047,  3058,  3069,
    3080,  3091,  3102,  3113,  3124,  3135,  3146,  3157,  3180,  3209,
    3220,  3243,  3260,  3271,  3294,  3311,  3334,  3345,  3368,  3379,
    3396,  3413,  3424,  3435,  3452,  3463,  3480,  3503,  3526,  3555,
    3584,  3595,  3612,  3623,  3640,  3651,  3674,  3703,  3726,  3743,
    3760,  3771,  3782,  3805,  3828,  3845,  3868,  3885,  3908,  3919,
    3936,  3948,  3954,  3971,  3982,  3993,  4016,  4033,  4044,  4055,
    4072,  4083,  4100,  4117,  4134,  4157,  4180,  4209,  4226,  4249,
    4272,  4301,  4312,  4341,  4376,  4423,  4464,  4475,  4486,  4509,
    4538,  4567,  4596,  4631,  4666,  4701,  4718,  4741,  4758,  4781,
    4792,  4809,  4826,  4849,  4860,  4877,  4888,  4899,  4910,  4921,
    4932,  4943,  4954,  4971,  4982,  4999,  5040,  5075,  5086,  5103,
    5126,  5155,  5190,  5201,  5224,  5241,  5258,  5269,  5286,  5303,
    5326,  5349,  5378,  5389,  5412,  5429,  5446,  5469,  5480,  5491,
    5502,  5519,  5530,  5541,  5552,  5569,  5586,  5609,  5620,  5631,
    5642,  5653,  5664,  5675,  5686,  5697,  5708,  5719,  5730,  5741,
    5752,  5763,  5774,  5785,  5796,  5807,  5818,  5829,  5840,  5851,
    5862,  5873,  5890,  5907,  5918,  5935,  5952,  5963,  5974,  5985,
    6002,  6025,  6048,  6077,  6100,  6129,  6164,  6205,  6240,  6251,
    6262,  6273,  6284,  6295,  6306,  6317,  6352,  6363,  6380,  6403,
    6450,  6497,  6514,  6543,  6554,  6571,  6600,  6617,  6640,  6663,
    6692,  6703,  6720,  6737,  6748,  6765,  6788,  6805,  6816,  6833,
    6844,  6873,  6890,  6901,  6918,  6941,  6958,  6969,  7016,  7063,
    7104,  7151,  7168,  7197,  7220,  7267,  7308,  7355,  7372,  7383,
    7400,  7418,  7424,  7435,  7446,  7458,  7464,  7475,  7486,  7509,
    7526,  7543,  7566,  7577,  7594,  7611,  7634,  7645,  7662,  7679,
    7702,  7713,  7730,  7753,  7764,  7781,  7816,  7839,  7850,  7867,
    7902,  7931,  7942,  7965,  7982,  7993,  8016,  8039,  8068,  8079,
    8090,  8107,  8118,  8135,  8158,  8169,  8180,  8203,  8220,  8231,
    8248,  8265,  8294,  8305,  8322,  8345,  8362,  8373,  8384,  8395,
    8406,  8417,  8440,  8451,  8462,  8473,  8484,  8495,  8518,  8535,
    8552,  8569,  8586,  8609,  8632,  8655,  8678,  8713,  8742,  8753,
    8782,  8817,  8852,  8893,  8910,  8927,  8950,  8979,  8990,  9007,
    9048,  9083,  9106,  9129,  9140,  9163,  9180,  9203,  9226,  9255,
    9284,  9313,  9342,  9359,  9376,  9387,  9404,  9427,  9444,  9455,
    9472,  9495,  9512,  9535,  9558,  9569,  9592,  9621,  9656,  9697,
    9732,  9773,  9796,  9819,  9848,  9877,  9894,  9917,  9934,  9957,
    9968,  9979,  9990, 10001, 10018, 10035, 10046, 10057, 10074, 10085,
   10096, 10107, 10124, 10135, 10152, 10163, 10180, 10191, 10202, 10219,
   10236, 10247, 10258, 10269, 10304, 10333, 10362, 10397, 10420, 10431,
   10460, 10483, 10512, 10523, 10546, 10569, 10592, 10609, 10626, 10643,
   10654, 10677, 10700, 10717, 10734, 10745, 10768, 10791, 10814, 10831,
   10848, 10865, 10876, 10899, 10922, 10945, 10968, 10991, 11008, 11025,
   11042, 11059, 11076, 11087, 11110, 11133, 11150, 11167, 11178, 11201,
   11218, 11229, 11252, 11269, 11280, 11303, 11320, 11331, 11354, 11371,
   11382, 11405, 11422, 11433, 11468, 11491, 11508, 11537, 11548, 11559,
   11582, 11599, 11610, 11621, 11632, 11643, 11654, 11665, 11676, 11687,
   11698, 11709, 11720, 11731, 11742, 11753, 11764, 11775, 11786
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS_TK", "MINUS_TK", "MULT_TK",
  "DIV_TK", "REM_TK", "LS_TK", "SRS_TK", "ZRS_TK", "AND_TK", "XOR_TK",
  "OR_TK", "BOOL_AND_TK", "BOOL_OR_TK", "EQ_TK", "NEQ_TK", "GT_TK",
  "GTE_TK", "LT_TK", "LTE_TK", "PLUS_ASSIGN_TK", "MINUS_ASSIGN_TK",
  "MULT_ASSIGN_TK", "DIV_ASSIGN_TK", "REM_ASSIGN_TK", "LS_ASSIGN_TK",
  "SRS_ASSIGN_TK", "ZRS_ASSIGN_TK", "AND_ASSIGN_TK", "XOR_ASSIGN_TK",
  "OR_ASSIGN_TK", "PUBLIC_TK", "PRIVATE_TK", "PROTECTED_TK", "STATIC_TK",
  "FINAL_TK", "SYNCHRONIZED_TK", "VOLATILE_TK", "TRANSIENT_TK",
  "NATIVE_TK", "PAD_TK", "ABSTRACT_TK", "STRICT_TK", "MODIFIER_TK",
  "DECR_TK", "INCR_TK", "DEFAULT_TK", "IF_TK", "THROW_TK", "BOOLEAN_TK",
  "DO_TK", "IMPLEMENTS_TK", "THROWS_TK", "BREAK_TK", "IMPORT_TK",
  "ELSE_TK", "INSTANCEOF_TK", "RETURN_TK", "VOID_TK", "CATCH_TK",
  "INTERFACE_TK", "CASE_TK", "EXTENDS_TK", "FINALLY_TK", "SUPER_TK",
  "WHILE_TK", "CLASS_TK", "SWITCH_TK", "CONST_TK", "TRY_TK", "FOR_TK",
  "NEW_TK", "CONTINUE_TK", "GOTO_TK", "PACKAGE_TK", "THIS_TK", "ASSERT_TK",
  "ENUM_TK", "BYTE_TK", "SHORT_TK", "INT_TK", "LONG_TK", "CHAR_TK",
  "INTEGRAL_TK", "FLOAT_TK", "DOUBLE_TK", "FP_TK", "ID_TK", "REL_QM_TK",
  "REL_CL_TK", "NOT_TK", "NEG_TK", "AT_TK", "ASSIGN_ANY_TK", "ASSIGN_TK",
  "ELLIPSIS_TK", "OP_TK", "CP_TK", "OCB_TK", "CCB_TK", "OSB_TK", "CSB_TK",
  "SC_TK", "C_TK", "DOT_TK", "STRING_LIT_TK", "CHAR_LIT_TK", "INT_LIT_TK",
  "FP_LIT_TK", "TRUE_TK", "FALSE_TK", "BOOL_LIT_TK", "NULL_TK", "$accept",
  "goal", "literal", "type", "primitive_type", "integral", "float",
  "reference_type", "class_or_interface_type", "class_type",
  "interface_type", "array_type", "class_or_interface_array_type", "name",
  "simple_name", "qualified_name", "identifier", "compilation_unit",
  "import_declarations", "type_declarations", "package_declaration",
  "import_declaration", "single_type_import_declaration",
  "type_import_on_demand_declaration", "annotations", "annotation",
  "annotation_name", "element_value_pairs", "element_value_pair",
  "element_value", "element_value_array_initializer",
  "annotation_type_declaration", "annotation_type_body",
  "annotation_type_element_declarations",
  "annotation_type_element_declaration", "annotation_type_element_rest",
  "annotation_type_element_non_delimited",
  "annotation_method_or_constant_rest", "annotation_method_rest",
  "annotation_constant_rest", "default_value", "type_declaration",
  "modifiers", "modifiers_without_type_parameterization", "modifier",
  "class_declaration", "type_list", "types", "type_parameters",
  "type_parameter", "type_bound", "super", "interfaces",
  "interface_type_list", "class_body", "class_body_declarations",
  "class_body_declaration", "class_member_declaration",
  "field_declaration", "variable_declarators", "variable_declarator",
  "variable_declarator_id", "variable_initializer", "method_declaration",
  "generic_method_declaration", "method_header", "method_declarator",
  "formal_parameter_list", "last_formal_parameter", "formal_parameter",
  "final", "throws", "class_type_list", "method_body",
  "static_initializer", "static", "constructor_declaration",
  "generic_constructor_declaration", "constructor_header",
  "constructor_declarator", "constructor_body", "constructor_block_end",
  "explicit_constructor_invocation", "this_or_super",
  "interface_declaration", "extends_interfaces", "interface_body",
  "interface_member_declarations", "interface_member_declaration",
  "constant_declaration", "abstract_method_declaration",
  "generic_abstract_method_declaration", "enum_declaration",
  "enum_constants", "enum_constant", "array_initializer",
  "variable_initializers", "block", "block_begin", "block_end",
  "block_statements", "block_statement",
  "local_variable_declaration_statement", "local_variable_declaration",
  "statement", "statement_nsi", "statement_without_trailing_substatement",
  "empty_statement", "label_decl", "labeled_statement",
  "labeled_statement_nsi", "expression_statement", "statement_expression",
  "if_then_statement", "if_then_else_statement",
  "if_then_else_statement_nsi", "switch_statement", "switch_expression",
  "switch_block", "switch_block_statement_groups",
  "switch_block_statement_group", "switch_labels", "switch_label",
  "while_expression", "while_statement", "while_statement_nsi",
  "do_statement_begin", "do_statement", "for_statement",
  "for_statement_nsi", "for_header", "for_begin", "for_init", "for_update",
  "statement_expression_list", "break_statement", "continue_statement",
  "return_statement", "throw_statement", "assert_statement",
  "synchronized_statement", "synchronized", "try_statement", "try_head",
  "resource_list", "resources", "resource", "catches", "catch_clause",
  "catch_clause_parameter", "finally", "primary", "primary_no_new_array",
  "type_literals", "class_instance_creation_expression",
  "anonymous_class_creation", "something_dot_new", "argument_list",
  "array_creation_expression", "dim_exprs", "dim_expr", "dims",
  "field_access", "method_invocation", "array_access",
  "postfix_expression", "post_increment_expression",
  "post_decrement_expression", "trap_overflow_corner_case",
  "unary_expression", "pre_increment_expression",
  "pre_decrement_expression", "unary_expression_not_plus_minus",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "conditional_and_expression", "conditional_or_expression",
  "conditional_expression", "assignment_expression", "assignment",
  "left_hand_side", "assignment_operator", "assign_any", "expression",
  "constant_expression", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369
};
# endif

#define YYPACT_NINF -793

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-793)))

#define YYTABLE_NINF -624

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1857,  -793,  -793,  -793,  -793,  -793,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,  -793,  -793,    53,   140,   507,  -793,   578,
     602,    31,  -793,   256,  -793,  6841,  7007,  6888,  -793,  -793,
    -793,    -6,   749,  -793,  -793,   701,  3008,  -793,  -793,  -793,
    -793,  -793,  -793,   614,  -793,    75,  -793,  -793,  -793,   403,
    -793,   473,  -793,    99,  -793,   465,  -793,   140,   181,   334,
    -793,  7055,  -793,  -793,  -793,  6960,  7102,   637,   639,  -793,
     140,   640,  2564,  -793,  -793,  -793,   103,  -793,  -793,   661,
    -793,   647,  7725,    -2,     6,  -793,  -793,   648,   258,   387,
    -793,  -793,   140,  -793,   649,   318,   306,  3011,  7150,  -793,
     120,   500,  -793,   561,  -793,  -793,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,   347,  -793,  -793,  -793,
     347,  -793,  -793,   759,   399,    38,   506,  -793,  -793,  -793,
     683,  -793,    81,  -793,  -793,  -793,  -793,   604,   656,  -793,
     667,  1917,  -793,  8179,  -793,   123,  -793,  7795,  -793,  -793,
    -793,  -793,  -793,     6,  -793,   691,  -793,  -793,  -793,   485,
     387,   375,  -793,  -793,   395,  -793,   427,  8055,  -793,  -793,
    3893,  6285,  3948,  4019,   591,    62,  7175,  -793,  4074,  4145,
    4200,   -11,  -793,  -793,  -793,  -793,  -793,  -793,  -793,   488,
     605,  1701,   518,  -793,   655,  -793,   456,  -793,   610,   511,
    -793,  -793,  -793,   694,  -793,  1198,  -793,  2306,   221,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,  -793,   932,    83,   954,
     915,   774,   729,   743,   757,   800,   674,  -793,  -793,  -793,
    2508,  -793,  -793,  -793,  -793,   726,     6,  -793,  -793,   258,
     387,   745,   773,   773,  -793,   773,  7415,  -793,  2667,  -793,
     140,  -793,   144,  -793,  -793,  -793,   753,   616,  -793,   408,
     795,  -793,   760,   616,  -793,   695,   704,   667,  7403,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,  -793,  -793,   375,  7499,
    -793,   705,  -793,  -793,  -793,   200,  -793,   251,  -793,   140,
    -793,  7864,  -793,  -793,   755,  8117,  -793,  -793,  -793,  -793,
     163,  -793,  -793,  -793,  -793,  -793,  -793,  -793,  -793,  -793,
     430,  -793,   708,   877,   775,   775,    80,  -793,  -793,  -793,
    -793,  -793,   792,  1701,   224,  -793,   518,   626,   625,   850,
    6511,  3137,   738,  6456,  -793,   720,  -793,    10,  4271,  -793,
     132,  -793,  -793,  4326,  4397,  4452,  4523,  4578,  4649,  4704,
    4775,  4830,  4901,  4956,  5027,  7442,  5082,  5153,  5208,  5279,
    5334,  5405,  5460,  3192,  -793,  -793,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,  5531,  -793,  -793,  -793,
     387,   375,  -793,    46,  -793,  -793,   910,  -793,   399,  -793,
    -793,  -793,  7197,   721,    96,  -793,  -793,  -793,   723,  3263,
     203,   931,  -793,  -793,   616,  -793,   805,   616,   704,  -793,
    -793,  -793,   845,  6889,  -793,  8179,  7571,  -793,  -793,  -793,
    -793,  -793,   276,  -793,   858,  -793,  -793,   858,   901,  -793,
    -793,  -793,  2744,  -793,  -793,  -793,  -793,  -793,  -793,  -793,
      47,   449,   862,  -793,  -793,   864,   871,  -793,  -793,   140,
     740,  -793,  -793,  -793,     8,   884,  -793,  -793,  -793,  3318,
     775,  -793,   527,   775,   527,  -793,  3389,  5586,   278,   475,
     722,  -793,  7973,  -793,   353,  -793,  -793,  -793,  -793,   687,
    -793,  -793,   378,  -793,  -793,  -793,  -793,  -793,  -793,  -793,
    -793,   886,  -793,   392,  -793,  6576,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,   932,  -793,   932,  -793,    83,  -793,    83,
    -793,    83,  -793,   954,  -793,   954,  -793,   954,  -793,   954,
    -793,   347,  -793,  -793,   915,  -793,   915,  -793,   774,  -793,
     729,  -793,   743,  -793,   757,  -793,   800,  -793,   988,   914,
    -793,  -793,   375,  -793,  -793,  -793,  2667,  -793,  -793,   562,
    -793,   690,  -793,  -793,  2667,  -793,  -793,   904,  -793,  -793,
    -793,   179,  -793,  -793,  6385,   291,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,  -793,  7933,   901,  7403,  -793,  -793,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,  -793,  2744,  -793,   361,
     227,  5657,  -793,   216,  3444,    91,   469,   489,   432,   514,
     308,   893,  5712,  6751,  -793,   140,   488,   605,   930,  1258,
     539,  -793,  2667,   912,  -793,  -793,  2744,  -793,  -793,   909,
    -793,  -793,  -793,  2833,  -793,  -793,   911,  -793,  -793,  -793,
     918,  2833,  -793,  2833,  -793,  -793,  7643,   916,  -793,  -793,
    -793,  -793,  -793,  -793,   548,  -793,   348,   842,   855,   221,
     866,   900,  -793,  -793,  -793,  -793,  -793,   922,  -793,   920,
     590,  -793,   575,  -793,  -793,  6631,  -793,   393,  -793,   773,
    -793,   773,  -793,  -793,   375,   107,  -793,  -793,  -793,  5783,
    2213,  -793,  -793,  -793,  5838,  -793,  -793,  6696,  -793,  -793,
     375,   739,  -793,  5909,  -793,  -793,  -793,   140,   849,  -793,
    7326,   742,   746,  -793,   924,  -793,   666,  -793,  -793,   761,
    -793,   965,  -793,  2744,   928,  -793,  2744,  -793,  -793,  -793,
    -793,  5964,  -793,   153,  -793,  -793,   259,  -793,  -793,   261,
    -793,  6035,  -793,  6090,  -793,  1562,  -793,  -793,  1055,  -793,
    -793,   284,  -793,   182,   356,   864,   657,  -793,  -793,   140,
    3515,  -793,  -793,  -793,   776,  -793,  -793,  -793,    11,  -793,
    -793,   962,   140,   976,  -793,  -793,  -793,   117,  3570,  -793,
    6161,  -793,   807,   983,   933,  -793,    -2,     6,  -793,  -793,
     258,   387,  -793,   765,  -793,  -793,  -793,  -793,   375,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,   785,  -793,   375,  -793,
    -793,   849,  -793,  -793,  -793,  -793,   849,  -793,  -793,  -793,
    -793,  3066,  -793,   685,  -793,  2744,  3641,  -793,  -793,   443,
    -793,  -793,  -793,  -793,  -793,  -793,  -793,   444,  -793,   936,
    -793,  -793,   140,   609,  -793,  -793,  -793,  -793,  -793,  6751,
    -793,  -793,   555,   864,  -793,  1037,   138,   316,  6216,  -793,
     421,  -793,  2415,  -793,   941,   949,  -793,  6340,  -793,  1389,
     937,   943,   944,   579,   425,   807,  -793,   858,  -793,  6456,
    -793,   945,  -793,  -793,   387,   375,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,   582,  -793,   310,   197,  -793,  2922,  -793,
    -793,   429,  -793,  -793,  2667,   940,  -793,  3696,  -793,  -793,
    1045,  -793,  -793,  -793,  -793,   428,  -793,  -793,  2525,  -793,
    2623,  -793,  6751,  6751,  -793,  -793,  -793,   953,   950,  2121,
    -793,   435,  -793,  7388,  -793,  -793,  -793,  -793,  -793,  -793,
    8055,   375,  -793,  3767,  -793,   311,   583,  -793,  1000,  1001,
    2922,  -793,  -793,  2922,  -793,  -793,  7643,   956,  -793,  -793,
    -793,  -793,  1060,   300,  -793,  -793,  -793,  -793,   967,   970,
    2833,  -793,   971,  -793,  -793,   973,   751,   977,  7264,  -793,
     312,   303,  -793,  5964,  2833,  -793,  -793,   140,  3822,  -793,
    -793,  1061,   975,  2833,  -793,  2833,  -793,  -793,  -793,  -793,
     317,   459,  -793,   984,  1389,   980,  -793,  -793,  -793,  -793,
    -793,  2922,  6751,   978,  2121,  1024,   986,  2922,   987,  2922,
    2922,  -793,  2922,  -793,  -793,  -793
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   111,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   129,     0,     0,     0,   128,     0,
       0,     0,   330,     0,     2,     0,     0,     0,    46,    56,
      57,     0,   130,   109,    48,     0,   112,   114,   106,   107,
     108,   110,    60,     0,    37,     0,    33,    34,    35,     0,
     136,     0,    52,     0,   277,     0,    75,     0,    77,    72,
       1,     0,    47,   130,    49,     0,     0,     0,     0,    71,
       0,     0,     0,   115,   113,    62,     0,    61,    58,     0,
     255,     0,     0,     0,     0,   248,   137,     0,   151,   155,
      53,    50,     0,   278,     0,     0,     0,     0,     0,    54,
       0,     0,   135,     0,   141,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   142,     9,    11,    12,    10,
      23,    24,    25,    26,    35,     0,     0,   144,    63,    59,
       0,    66,     0,    36,   259,    29,   257,    26,     0,   261,
       0,     0,   268,     0,   271,     0,   269,     0,   263,   265,
     266,   267,   270,     0,   251,     0,   250,   154,    28,     0,
     155,     0,   157,   158,   156,   279,     0,     0,    88,    76,
       0,     0,     0,     0,     0,     0,     0,   460,     0,     0,
       0,     0,     7,     6,     3,     4,     5,     8,   459,     0,
       0,   530,    35,    83,     0,    78,     0,    84,   529,   457,
     466,   462,   478,     0,   458,   463,   464,   465,   547,   531,
     532,   540,   562,   535,   536,   538,   550,   569,   574,   581,
     592,   597,   600,   603,   606,   609,   612,   617,   637,   618,
       0,    82,    55,    51,   256,     0,     0,   249,   138,   151,
     155,     0,    30,    32,    27,    31,     0,   140,     0,   139,
       0,    68,     0,    67,    64,   202,     0,   221,   200,     0,
       0,   179,   182,   221,   204,     0,     0,     0,     0,   274,
     273,   272,   262,   264,   253,   260,   258,   153,     0,     0,
     132,     0,   280,   276,   286,     0,    70,     0,   282,     0,
     100,     0,    90,    92,    96,     0,    97,    98,    99,   539,
     530,   463,   465,   537,   542,   541,   546,   545,   544,   543,
       0,   514,     0,     0,     0,    28,     0,   551,   548,   552,
     549,   558,     0,   530,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    73,     0,     0,   487,
       0,   534,   533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   625,     0,   624,   252,   254,
     155,     0,   509,     0,   148,   149,   147,   143,   146,   145,
      69,    65,     0,     0,     0,   197,   188,   177,     0,     0,
       0,     0,   196,   203,   221,   201,     0,   221,     0,   134,
     297,   161,    33,     0,   173,     0,     0,   163,   165,   170,
     171,   172,     0,   166,     0,   167,   168,     0,   221,   174,
     175,   169,     0,   176,   160,   159,   287,   281,   275,   284,
       0,     0,     0,   101,   102,   104,     0,    91,    95,     0,
       0,    93,   471,   475,     0,   513,   503,   502,   483,     0,
     496,   504,     0,   497,     0,   484,     0,     0,     0,    30,
      31,   468,   461,    86,     0,   470,   474,   473,   515,     0,
     493,   525,     0,   469,   472,   491,   467,    81,    80,    79,
     492,   512,   527,     0,   488,     0,   566,   563,   567,   564,
     568,   565,   572,   570,   573,   571,   578,   575,   579,   576,
     580,   577,   588,   583,   590,   585,   587,   582,   589,   584,
     591,     0,   586,   595,   593,   596,   594,   599,   598,   602,
     601,   605,   604,   608,   607,   611,   610,   615,     0,     0,
     620,   619,     0,   131,   511,   510,     0,   208,   205,     0,
     220,     0,   211,   210,     0,   223,   224,   222,   209,   207,
     181,     0,   180,   184,     0,     0,   192,   191,   189,   187,
     190,   199,   178,   198,     0,   221,     0,   195,   232,   162,
     164,   194,   228,   193,   227,   229,   231,     0,   233,     0,
       0,     0,   386,     0,     0,     0,     0,     0,     0,     0,
       0,   460,     0,     0,   298,     0,     9,    24,   621,     0,
     220,   303,     0,     0,   318,   295,     0,   299,   301,     0,
     302,   307,   319,     0,   308,   320,     0,   309,   310,   321,
       0,     0,   311,     0,   322,   312,   401,     0,   323,   324,
     325,   327,   329,   326,     0,   328,     0,   354,   353,     0,
     351,   352,   349,   350,   348,   285,   283,     0,    94,     0,
       0,   135,     0,   521,   522,     0,   508,     0,   505,   498,
     501,   499,   500,   485,   477,     0,   560,   554,   557,     0,
       0,   555,    85,   516,     0,   526,   523,     0,   528,   524,
     479,     0,   614,     0,   133,   150,   218,     0,   216,   206,
       0,     0,     0,   288,     0,   292,     0,   185,   235,     0,
     234,   621,   237,     0,     0,   241,     0,   337,   338,   336,
     356,     0,   423,     0,   412,   410,     0,   420,   418,     0,
     382,     0,   363,     0,   441,     0,   440,   398,     0,   416,
     414,     0,   427,     0,     0,   305,     0,   333,   331,     0,
       0,   296,   300,   304,   621,   434,   332,   335,     0,   361,
     381,     0,     0,   621,   403,   407,   400,     0,     0,   431,
       0,   438,     0,     0,     0,   255,     0,     0,   248,   137,
     151,   155,   519,     0,   507,   506,   490,   486,   476,   559,
     553,   561,   556,   495,   494,   517,     0,   480,   481,   616,
     613,   215,   214,   213,   212,   219,   217,   226,   225,   289,
     290,     0,   236,     0,   238,     0,     0,   239,   357,     0,
     424,   422,   413,   411,   421,   419,   383,     0,   364,     0,
     444,   442,     0,     0,   445,   399,   417,   415,   428,     0,
     426,   461,     0,   306,   339,     0,     0,     0,     0,   366,
       0,   370,     0,   373,     0,   179,   404,     0,   391,     0,
       0,   433,     0,     0,     0,   435,   448,     0,   436,     0,
     103,     0,   251,   250,   155,     0,   520,   489,   518,   482,
     294,   291,   293,     0,   240,     0,     0,   358,     0,   384,
     380,     0,   447,   443,     0,     0,   343,     0,   340,   341,
       0,   379,   376,   377,   638,     0,   368,   371,     0,   367,
       0,   374,     0,     0,   409,   408,   393,     0,   406,     0,
     432,     0,   452,     0,   456,   455,   449,   437,   450,   105,
       0,     0,   131,     0,   242,     0,     0,   355,     0,   307,
       0,   314,   315,     0,   316,   317,   401,     0,   365,   446,
     425,   344,     0,     0,   342,   378,   375,   369,     0,     0,
       0,   392,     0,   430,   429,   453,     0,     0,     0,   133,
       0,     0,   243,     0,     0,   334,   385,     0,     0,   347,
     345,     0,     0,     0,   389,     0,   454,   451,    89,   245,
       0,     0,   359,   179,     0,     0,   346,   387,   390,   388,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,   360,   396,   394
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -793,  -793,  -793,   635,   601,  -793,  -793,   732,   -26,  -161,
     -36,   906,  -793,   -15,  -202,  -793,   367,  -793,  1076,   793,
    -793,    40,  -793,  -793,  1104,    18,  -793,   926,  -304,  -323,
    -793,  -164,  -793,   175,  -286,   813,  -793,  -793,  -793,  -793,
    -793,   747,    19,  -793,  1073,    69,   141,  -793,  -793,   860,
    -793,   -80,   -87,  -793,  -271,  -793,   696,  -793,  -245,  -129,
    -389,  -525,  -539,   699,  -793,  -228,  -118,   537,   417,  -684,
    -379,  -213,  -793,  -793,  -793,  -793,   703,  -793,  -793,  -380,
    -793,  -327,  -793,   532,   -45,   -37,   -62,  -793,   979,  -793,
     990,  -793,   -44,  -793,   680,  -165,  -793,  -278,   700,  -406,
    -418,  -541,  -793,  -596,  -155,   -90,  -530,   193,  -518,  -793,
    -793,  -793,  -619,  -793,  -793,  -793,  -793,  -793,  -793,  -793,
     272,   273,  -792,  -441,  -793,  -793,  -793,  -793,  -793,  -793,
    -365,  -338,  -793,  -162,  -593,  -793,  -793,  -793,  -793,  -793,
    -793,  -793,  -793,  -793,  -793,  -793,   236,  -793,   266,  -793,
     269,  -793,  -793,  -793,   627,  -793,  -793,  -424,  -793,   830,
     373,    -7,  2005,   692,  2083,   801,   963,  1072,   985,  -143,
    1129,  1239,  -431,  -793,   628,   654,   553,   651,   788,   789,
     790,   796,   798,  -793,   458,   782,  1400,  -793,  -793,  -793,
      28,  -793
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,   188,   605,   189,   117,   118,   119,   120,   159,
     136,   190,   122,   191,    46,    47,    48,    24,    25,    26,
      27,    28,    29,    30,   285,    63,    59,   194,   195,   196,
     197,    33,   168,   291,   292,   293,   294,   442,   443,   444,
     870,    34,   755,    36,    37,   611,   244,   125,   126,   127,
     386,    89,    95,   164,   280,   416,   417,   418,   144,   745,
     261,   262,   565,   420,   421,   145,   263,   551,   552,   553,
     612,   395,   557,   583,   423,   424,   425,   426,   427,   428,
     586,   712,   713,   613,    39,   153,    85,   147,   148,   149,
     150,   151,    40,   287,   288,   566,   706,   614,   432,   715,
     910,   617,   618,   619,   620,   938,   621,   622,   623,   624,
     941,   625,   626,   627,   628,   942,   629,   630,   759,   850,
     851,   852,   853,   631,   632,   944,   633,   634,   635,   945,
     636,   637,   766,   917,   918,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   736,   833,   834,   865,   866,   867,
     868,   198,   199,   200,   201,   202,   203,   479,   204,   460,
     461,   245,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   376,   377,
     480,   905
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   431,   161,   290,    53,   447,    58,   409,   160,   562,
     487,   260,    84,   554,   616,   316,   804,   765,    32,    35,
     257,   154,   156,   240,   698,   705,   615,   303,    76,   307,
     309,   489,    56,   575,   419,   318,   320,   146,   152,   237,
     764,   681,   675,   767,    35,    35,    35,   544,   655,    69,
     402,   422,   100,    58,    42,   135,   247,   123,   163,   847,
     911,   158,    81,   311,   236,    62,   137,   123,   135,    38,
      67,   691,   137,   278,   848,   752,    77,   412,    44,   137,
      35,   465,   253,   490,    35,    35,   346,   347,    68,    43,
     325,   274,   311,    57,    38,    38,    38,   558,    82,    44,
      90,   141,   146,   152,   128,    62,    82,   663,   787,   242,
     543,   155,   849,   243,   664,   193,   911,    35,   856,   276,
      44,   232,   297,   298,   270,   231,   123,   290,   123,   135,
      38,   290,   123,   494,    38,    38,    44,   406,   431,   899,
     137,    68,    44,   248,   584,   390,   585,   404,   407,   545,
     315,   142,   123,   381,   820,   300,   300,   300,   300,   380,
     445,   137,   268,   300,   300,   323,   141,    38,   312,   716,
     489,   419,   801,   378,   379,   752,   806,    74,   466,    78,
     396,    79,   242,   838,   286,   254,   295,   422,   422,  -247,
      83,   571,    88,    41,   573,   554,   575,   312,   899,   559,
     497,   499,   501,    91,   568,    92,   788,   129,   324,   130,
     751,   412,   684,   412,   412,   588,   142,   724,    41,    41,
      41,  -402,   857,   143,   233,   471,    92,   271,   720,    44,
     495,   123,   556,   123,   429,   430,   296,   900,   915,   967,
     765,   783,   235,   684,   239,   435,   297,   298,   391,   792,
     297,   298,   437,   123,    41,   135,    60,   821,    41,    41,
     822,   330,   824,   796,   123,   331,   137,   341,   342,   332,
    -186,   694,   882,   839,   752,  -186,   123,   581,  -186,   678,
     123,  -186,  -186,  -186,  -186,   836,   840,    92,   143,    44,
     407,    41,   707,   542,    68,   815,   935,   670,   413,   672,
     765,   980,   684,    69,   980,    44,   569,   462,   464,   739,
     295,   898,   954,   979,    35,   469,   470,   901,   996,   165,
     725,   554,    87,   472,   677,   721,   846,   765,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     123,   300,   300,   300,   300,   300,   300,   300,   414,   771,
     764,   193,   438,   767,   488,   439,   440,   471,   939,   482,
     296,   231,   710,   823,   296,   825,   493,   158,   772,   752,
     940,   429,   430,   855,   412,   765,   410,   123,   137,   685,
     582,   382,  -183,    49,    51,   765,   814,    55,   837,   817,
    -183,   539,   886,   688,   784,  -183,  -183,    44,   123,   981,
     123,   123,   990,   786,    80,   684,   167,   902,   684,   396,
     939,   550,   740,   939,   934,   972,   989,   608,   166,   797,
     415,  1000,   940,    72,    96,   940,   924,   567,   282,   955,
     948,   452,    97,   734,   576,   413,   963,   101,   103,   124,
      94,   698,    44,   892,   887,   889,   133,   943,   410,   241,
     396,   610,   300,   669,   682,   841,   671,   300,   286,   133,
     887,   717,   718,   246,   192,   719,    93,    81,   756,   847,
     730,   939,   433,   953,    86,   279,   760,   939,   761,   939,
     939,   686,   939,   940,   848,   414,   277,   667,   884,   940,
     732,   940,   940,    72,   940,   689,   785,   133,   453,   943,
     281,   234,   943,    82,  -186,   256,   392,   259,    50,   971,
    -186,  -186,  -186,  -186,   242,   737,    44,   877,    94,   956,
      72,    68,   906,   946,   249,   410,  -151,   879,   283,  -362,
     735,   123,  -439,   284,   333,   410,   790,    87,  -152,   123,
    -434,   808,   888,   890,   554,  -186,   929,   657,   326,   769,
     947,  -186,  -186,  -186,  -186,   336,   896,   415,  1001,   123,
     943,   123,   238,   696,    81,  -155,   943,   731,   943,   943,
     340,   943,   711,  -151,   679,   946,   779,   383,   946,    52,
     922,    72,   781,   896,   720,  -152,   925,   733,   993,   928,
     241,   775,   567,   550,   328,    72,    44,   123,   778,   242,
      82,   608,   947,    54,   932,   947,   610,    71,   754,   433,
      72,   250,   738,   338,  -151,    75,   754,   388,   754,   723,
     843,   763,   729,   777,    72,    87,   475,   564,  -151,   383,
     743,   744,   256,   259,   256,   610,   946,  -434,    99,    87,
      56,   102,   946,   964,   946,   946,   770,   946,   134,   157,
     162,    44,   436,   897,    81,   550,   441,   255,   483,   697,
     969,  -151,   131,   947,   300,   300,   132,    44,   258,   947,
     393,   947,   947,   116,   947,  -151,   158,   923,   300,   455,
     933,   973,   447,   116,   251,   123,   483,   137,   252,   362,
      82,    44,   275,   476,   875,   339,   403,   310,   608,   133,
     874,   608,   326,    44,   491,   405,   434,   115,   893,   454,
      92,   329,   794,   894,   872,   873,   337,   140,   394,   550,
     123,   488,   555,   842,   560,   484,    44,   473,    44,    44,
     485,   474,   610,   937,   486,   610,    44,    44,    44,   483,
     358,   661,   116,   805,   116,    44,    44,   807,   116,   819,
      44,   883,   696,   484,   334,   359,    44,   962,   485,   827,
     335,   829,   486,    70,   363,   561,   290,   810,   116,    71,
     360,   811,    44,    64,    44,   256,   266,   314,   267,    72,
      44,   322,   140,    44,    44,   756,   683,   931,   760,   699,
     356,   357,   684,    44,    44,   700,   860,    44,   862,   609,
     608,   776,   289,   780,   290,   984,   484,   284,    64,    44,
      44,   485,    44,    64,   361,   486,   660,   662,    61,   992,
      66,   680,  -530,  -530,   383,   -70,    82,    44,   998,    44,
     999,    44,  1003,   668,   610,    44,   668,   608,   798,   567,
      44,   326,  1008,   -70,   684,    64,   937,   116,   382,   116,
     975,   392,   984,   976,   992,   998,   399,   999,    98,   448,
     812,   241,   400,   401,   876,    92,   700,   895,   863,   116,
     684,   610,   864,   754,   330,   383,   904,   459,   331,   123,
     116,   385,   746,   387,   878,   297,   298,   193,  -462,  -462,
     684,   467,   116,   608,   468,   608,   116,   231,   328,   397,
     398,  -464,  -464,   408,   513,   515,   517,   519,   123,   572,
     398,  1005,  -531,  -531,   140,   123,   561,  1011,   477,  1013,
    1014,   546,  1015,   297,   298,   754,   289,   610,   754,   610,
     289,   763,   570,   351,   352,   353,   354,   343,   344,   345,
     958,   959,   550,   574,  -462,   754,  -532,  -532,  -462,   295,
      72,   400,   401,   123,   609,   393,   521,  -464,   410,   754,
     726,  -464,   348,   349,   350,   550,   658,   741,   754,   398,
     754,   659,   561,   355,   503,   505,  -530,  -530,   121,   456,
     457,   458,   665,   609,   687,    72,   754,   295,   121,   692,
     609,  -246,   754,   116,   754,   754,    72,   754,   609,   296,
     609,   991,   507,   509,   511,   693,   995,   524,   526,   702,
     750,  -530,  -530,   753,   116,   757,   116,   116,   758,   -26,
     768,   773,  -530,  -530,   774,   809,   816,   549,   330,   854,
    1006,   869,   331,   606,   871,   891,   746,   296,   898,   912,
     913,   919,   920,   921,   950,   930,   954,   121,   266,   121,
     267,   140,   960,   121,   -26,   857,   835,   974,  -313,   647,
     978,   979,   996,   330,   561,   -26,   982,   331,   561,   983,
     985,   813,   986,   121,   330,  1002,   987,  1007,   331,   997,
     609,  1009,   332,   609,  1004,  1010,  1012,   522,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,    65,    31,   968,  -397,   327,   451,    73,
     389,   709,   580,   133,   577,  -397,   561,   803,   578,   714,
     656,  -397,   907,   908,   648,  -397,   273,   587,  -397,   561,
     949,   926,  -397,   269,   927,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,   463,   528,   116,   530,  -397,
     532,   800,   121,  -397,   121,   116,   305,   534,   541,  -397,
     536,     0,  -397,  -397,  -397,  -397,     0,     0,  -397,  -397,
       0,     0,     0,     0,   121,   116,     0,   116,     0,     0,
     133,   695,   609,     0,     0,   121,     0,     0,   606,   701,
       0,     0,     0,     0,     0,     0,     0,   121,     0,   561,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   549,
       0,   408,     0,   116,   647,     0,     0,   606,     0,   609,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,     0,     0,   649,     0,     0,     0,   606,     0,     0,
       0,     0,     0,   647,     0,     0,     0,   749,     0,     0,
     647,     0,     0,     0,     0,   609,     0,     0,   647,   747,
     647,   121,     0,   647,     0,     0,     0,     0,     0,     0,
       0,   762,     0,     0,     0,   609,     0,   609,   -35,   648,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,     0,     0,     0,  -622,     0,     0,     0,   121,     0,
       0,   116,     0,     0,   -35,   -35,     0,   609,   648,     0,
     609,     0,     0,     0,   606,   648,     0,   606,     0,   121,
       0,   121,   121,   648,     0,   648,     0,   609,   648,     0,
       0,     0,     0,   561,     0,   549,   116,     0,   607,     0,
     647,   609,     0,   647,   561,     0,     0,   -35,     0,   748,
     609,     0,   609,     0,   -35,     0,   -35,     0,     0,     0,
     -35,     0,     0,     0,   -35,     0,     0,     0,   609,     0,
     832,     0,     0,     0,   609,     0,   609,   609,     0,   609,
       0,     0,     0,     0,     0,     0,     0,     0,   649,     0,
     916,     0,     0,     0,     0,   650,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   648,     0,     0,   648,     0,
       0,     0,     0,     0,     0,     0,   606,   649,     0,     0,
       0,     0,     0,     0,   649,     0,     0,     0,     0,     0,
       0,     0,   649,     0,   649,   172,   173,   649,     0,     0,
     105,     0,   647,     0,     0,     0,     0,     0,     0,   174,
       0,     0,   121,   606,     0,   175,     0,     0,     0,     0,
     121,     0,   176,     0,     0,     0,   177,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,   647,
     121,     0,   121,     0,   647,     0,   647,   603,  -405,     0,
       0,     0,     0,   607,     0,   116,   182,   183,   184,   185,
       0,     0,   186,   187,   651,     0,     0,   648,     0,   606,
       0,   606,     0,     0,   649,   647,     0,   649,   121,     0,
       0,     0,   607,     0,   116,     0,     0,     0,     0,   832,
       0,   116,     0,     0,     0,   647,     0,   647,     0,     0,
       0,     0,   607,     0,   648,     0,   647,   606,     0,   648,
     650,   648,     0,     0,     0,     0,     0,     0,   966,     0,
       0,   652,     0,   830,     0,   289,     0,   647,     0,   116,
     647,     0,     0,   647,     0,     0,     0,     0,     0,   650,
     648,   977,     0,     0,     0,     0,   650,   647,     0,     0,
       0,     0,     0,     0,   650,     0,   650,     0,     0,   650,
     648,   647,   648,   289,     0,     0,   121,     0,     0,     0,
     647,   648,   647,   105,     0,     0,   649,     0,     0,   607,
       0,   647,   607,     0,     0,     0,     0,     0,   647,     0,
       0,   647,   648,     0,   647,   648,   647,   647,   648,   647,
       0,   121,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,   648,   649,     0,     0,     0,     0,   649,   651,
     649,   831,     0,     0,     0,     0,   648,     0,     0,     0,
       0,   653,     0,     0,     0,   648,   650,   648,     0,   650,
       0,     0,     0,     0,     0,     0,   648,     0,   651,   649,
       0,     0,     0,   648,     0,   651,   648,     0,     0,   648,
       0,   648,   648,   651,   648,   651,     0,     0,   651,   649,
       0,   649,     0,     0,     0,     0,   652,     0,     0,     0,
     649,   607,     0,  -621,  -621,  -621,  -621,  -621,  -621,  -621,
    -621,  -621,  -621,  -621,     0,     0,     0,     0,     0,     0,
       0,   649,     0,     0,   649,   652,     0,   649,     0,     0,
       0,     0,   652,     0,     0,     0,     0,     0,   607,     0,
     652,   649,   652,     0,     0,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   649,     0,     0,   650,     0,
       0,     0,     0,     0,   649,   651,   649,     0,   651,     0,
       0,     0,     0,     0,     0,   649,     0,  -621,     0,   330,
     121,     0,   649,   331,     0,   649,     0,   332,   649,     0,
     649,   649,     0,   649,   607,   650,   607,     0,     0,     0,
     650,     0,   650,     0,     0,     0,   653,     0,     0,   121,
       0,     0,   654,     0,     0,     0,   121,     0,     0,     0,
       0,     0,   652,     0,     0,   652,     0,     0,     0,     0,
       0,   650,   607,     0,     0,   653,     0,   -38,     1,     0,
       0,     0,   653,     0,     0,     0,     0,     0,     0,     0,
     653,   650,   653,   650,   121,   653,     0,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,   651,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   650,     0,     0,   650,     0,     0,   650,
       0,     0,     0,    15,     0,     0,     0,     0,   264,    16,
       0,     0,     0,   650,   651,    17,     0,    18,     0,   651,
       0,   651,     0,    19,     0,     0,    20,   650,     0,     0,
       0,     0,     0,     0,   652,     0,   650,     0,   650,     0,
       0,    21,   653,     0,     0,   653,     0,   650,     0,     0,
     651,    22,     0,     0,   650,     0,     0,   650,   105,     0,
     650,     0,   650,   650,     0,   650,     0,   265,     0,    70,
     651,   652,   651,     0,     0,    71,   652,   654,   652,     0,
       0,   651,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,     0,
       0,     0,   651,     0,     0,   651,   654,   652,   651,     0,
       0,     0,     0,   654,     0,     0,     0,     0,     0,     0,
       0,   654,   651,   654,     0,     0,   654,   652,     0,   652,
       0,     0,     0,     0,     0,     0,   651,     0,   652,     0,
       0,     0,     0,     0,   653,   651,     0,   651,     0,     0,
       0,     0,     0,     0,     0,     0,   651,     0,     0,   652,
       0,     0,   652,   651,     0,   652,   651,     0,     0,   651,
       0,   651,   651,     0,   651,     0,     0,     0,     0,   652,
       0,   653,     0,     0,     0,     0,   653,     0,   653,     0,
       0,     0,     0,   652,     0,     0,     0,     0,     0,     0,
       0,     0,   652,   654,   652,     0,   654,     0,     0,     0,
       0,     0,   961,   652,     0,     0,     0,   653,     0,     0,
     652,     0,     0,   652,     0,     0,   652,     0,   652,   652,
       0,   652,     0,     0,     0,     0,     0,   653,     0,   653,
       0,     0,     0,     0,     0,     0,     0,     0,   653,     0,
       0,     0,     0,     0,     0,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,   301,   301,   301,   301,   653,
       0,   174,   653,   301,   301,   653,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,   653,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   653,   791,   654,     0,     0,     0,   603,
    -405,     0,   653,     0,   653,     0,     0,     0,   182,   183,
     184,   185,     0,   653,   186,   187,     0,     0,     0,     0,
     653,     0,     0,   653,     0,     0,   653,     0,   653,   653,
       0,   653,   654,   302,   302,   302,   302,   654,     0,   654,
       0,   302,   302,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,   654,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,   654,     0,
     654,   180,     0,     0,     0,     0,     0,     0,     0,   654,
     182,   183,   184,   185,     0,     0,   186,   187,  -623,  -623,
    -623,  -623,  -623,  -623,  -623,  -623,  -623,  -623,  -623,     0,
     654,     0,     0,   654,     0,     0,   654,     0,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     654,   301,   301,   301,   301,   301,   301,   301,     0,     0,
       0,     0,     0,     0,   654,     0,     0,     0,     0,     0,
       0,     0,     0,   654,     0,   654,     0,     0,     0,     0,
       0,     0,     0,     0,   654,     0,     0,     0,     0,     0,
       0,   654,  -623,     0,   654,     0,     0,   654,     0,   654,
     654,     0,   654,     0,     0,     0,   589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,     0,   302,
     302,   302,   302,   302,   302,   302,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   172,   173,   847,   590,   591,   105,   592,     0,     0,
     593,     0,   301,     0,   594,   174,     0,   301,   848,     0,
       0,   595,   596,    17,   597,    18,   598,   599,   176,   600,
       0,     0,   601,   602,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,     0,     0,    68,
       0,     0,     0,   603,     0,   410,   909,     0,     0,    22,
       0,     0,   182,   183,   184,   185,   589,     0,   186,   187,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,     0,     0,   302,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   172,   173,   847,   590,   591,   105,   592,     0,     0,
     593,     0,   104,     0,   594,   174,     0,     0,   848,     0,
       0,   595,   596,    17,   597,    18,   598,   599,   176,   600,
       0,     0,   601,   602,   375,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,   105,     0,     0,     0,    68,
       0,     0,     0,   603,   589,   410,   957,     0,     0,    22,
       0,     0,   182,   183,   184,   185,     0,     0,   186,   187,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   172,
     173,  -372,   590,   591,   105,   592,     0,     0,   593,     0,
       0,     0,   594,   174,   301,   301,  -372,     0,     0,   595,
     596,    17,   597,    18,   598,   599,   176,   600,   301,     0,
     601,   602,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,     0,     0,    68,   105,     0,
       0,   603,     0,   410,  -372,     0,     0,    22,     0,     0,
     182,   183,   184,   185,     0,     0,   186,   187,     0,     0,
       0,     0,     0,     0,     0,   589,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,     0,
       0,     0,   302,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     172,   173,     0,   590,   591,   105,   592,     0,     0,   593,
       0,     0,     0,   594,   174,     0,     0,     0,     0,     0,
     595,   596,    17,   597,    18,   598,   599,   176,   600,     0,
       0,   601,   602,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,   589,     0,     0,     0,    68,     0,
       0,     0,   603,     0,   410,   604,     0,     0,    22,     0,
       0,   182,   183,   184,   185,     0,     0,   186,   187,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   172,
     173,     0,   590,   591,   105,   592,     0,     0,   593,     0,
       0,     0,   594,   174,     0,     0,     0,     0,     0,   595,
     596,     0,   597,    18,   598,   599,   176,   600,     0,     0,
     601,   602,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,   589,     0,     0,     0,    68,     0,     0,
       0,   603,     0,   410,     0,     0,     0,    22,     0,     0,
     182,   183,   184,   185,     0,     0,   186,   187,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   172,   173,
       0,   936,   591,   105,   592,     0,     0,   593,     0,     0,
       0,   594,   174,     0,     0,     0,     0,     0,   595,   596,
       0,   597,    18,   598,   599,   176,   600,     0,     0,   601,
     602,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,   169,     0,   170,   171,    68,     0,     0,     0,
     603,     0,   410,     0,     0,     0,    22,     0,    72,   182,
     183,   184,   185,     0,     0,   186,   187,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,     0,     0,   880,     0,   170,
     171,   174,     0,     0,     0,     0,     0,   175,    18,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,    68,   178,   179,    68,     0,     0,     0,   180,
       0,   181,   172,   173,     0,     0,     0,   105,   182,   183,
     184,   185,     0,     0,   186,   187,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,   481,   176,
     170,   171,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,     0,   564,   881,     0,     0,
       0,     0,     0,   182,   183,   184,   185,     0,     0,   186,
     187,     0,     0,   172,   173,     0,     0,     0,   105,     0,
       0,     0,     0,   537,     0,   170,   171,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,   177,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,   178,
     179,     0,     0,     0,     0,   180,     0,     0,   172,   173,
     382,     0,     0,   105,   182,   183,   184,   185,     0,     0,
     186,   187,   174,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,   563,   176,   170,   171,     0,   177,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,     0,   538,   178,   179,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,     0,     0,   186,   187,     0,     0,   172,
     173,     0,     0,     0,   105,     0,     0,     0,     0,   666,
       0,   170,   171,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,     0,     0,
       0,   180,     0,   564,   172,   173,     0,     0,     0,   105,
     182,   183,   184,   185,     0,     0,   186,   187,   174,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
     673,   176,   170,   171,     0,   177,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,     0,     0,
     178,   179,     0,     0,     0,     0,   180,     0,     0,     0,
       0,   382,     0,     0,     0,   182,   183,   184,   185,     0,
       0,   186,   187,     0,     0,   172,   173,     0,     0,     0,
     105,     0,     0,     0,     0,   727,     0,   170,   171,   174,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   177,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,   178,   179,     0,     0,     0,     0,   180,   674,     0,
     172,   173,     0,     0,     0,   105,   182,   183,   184,   185,
       0,     0,   186,   187,   174,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,   844,   176,   170,   171,
       0,   177,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,   178,   179,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,   728,     0,
       0,   182,   183,   184,   185,     0,     0,   186,   187,     0,
       0,   172,   173,     0,     0,     0,   105,     0,     0,     0,
       0,   858,     0,   170,   171,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,   845,     0,   172,   173,     0,     0,
       0,   105,   182,   183,   184,   185,     0,     0,   186,   187,
     174,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,   844,   176,   170,   171,     0,   177,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
       0,     0,   178,   179,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,   859,     0,     0,   182,   183,   184,
     185,     0,     0,   186,   187,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,     0,     0,   951,     0,   170,
     171,   174,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
     885,     0,   172,   173,     0,     0,     0,   105,   182,   183,
     184,   185,     0,     0,   186,   187,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,   951,   176,
     170,   171,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,   952,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,     0,     0,   186,
     187,     0,     0,   172,   173,     0,     0,     0,   105,     0,
       0,     0,     0,   858,     0,   170,   171,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,   177,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,   178,
     179,     0,     0,     0,     0,   180,   970,     0,   172,   173,
       0,     0,     0,   105,   182,   183,   184,   185,     0,     0,
     186,   187,   174,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,   299,   176,   170,   171,     0,   177,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,     0,     0,   178,   179,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,   994,     0,     0,   182,
     183,   184,   185,     0,     0,   186,   187,     0,     0,   172,
     173,     0,     0,     0,   105,     0,     0,     0,     0,   306,
       0,   170,   171,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,     0,     0,
       0,   180,     0,     0,   172,   173,     0,     0,     0,   105,
     182,   183,   184,   185,     0,     0,   186,   187,   174,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
     308,   176,   170,   171,     0,   177,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,     0,     0,
     178,   179,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,     0,
       0,   186,   187,     0,     0,   172,   173,     0,     0,     0,
     105,     0,     0,     0,     0,   317,     0,   170,   171,   174,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   177,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,   178,   179,     0,     0,     0,     0,   180,     0,     0,
     172,   173,     0,     0,     0,   105,   182,   183,   184,   185,
       0,     0,   186,   187,   174,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,   319,   176,   170,   171,
       0,   177,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,   178,   179,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,     0,     0,   186,   187,     0,
       0,   172,   173,     0,     0,     0,   105,     0,     0,     0,
       0,   321,     0,   170,   171,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,     0,     0,   172,   173,     0,     0,
       0,   105,   182,   183,   184,   185,     0,     0,   186,   187,
     174,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,   492,   176,   170,   171,     0,   177,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
       0,     0,   178,   179,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,     0,     0,   186,   187,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,     0,     0,   496,     0,   170,
     171,   174,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
       0,     0,   172,   173,     0,     0,     0,   105,   182,   183,
     184,   185,     0,     0,   186,   187,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,   498,   176,
     170,   171,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,     0,     0,   186,
     187,     0,     0,   172,   173,     0,     0,     0,   105,     0,
       0,     0,     0,   500,     0,   170,   171,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,   177,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,   178,
     179,     0,     0,     0,     0,   180,     0,     0,   172,   173,
       0,     0,     0,   105,   182,   183,   184,   185,     0,     0,
     186,   187,   174,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,   502,   176,   170,   171,     0,   177,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,     0,     0,   178,   179,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,     0,     0,   186,   187,     0,     0,   172,
     173,     0,     0,     0,   105,     0,     0,     0,     0,   504,
       0,   170,   171,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,     0,     0,
       0,   180,     0,     0,   172,   173,     0,     0,     0,   105,
     182,   183,   184,   185,     0,     0,   186,   187,   174,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
     506,   176,   170,   171,     0,   177,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,     0,     0,
     178,   179,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,     0,
       0,   186,   187,     0,     0,   172,   173,     0,     0,     0,
     105,     0,     0,     0,     0,   508,     0,   170,   171,   174,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   177,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,   178,   179,     0,     0,     0,     0,   180,     0,     0,
     172,   173,     0,     0,     0,   105,   182,   183,   184,   185,
       0,     0,   186,   187,   174,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,   510,   176,   170,   171,
       0,   177,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,   178,   179,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,     0,     0,   186,   187,     0,
       0,   172,   173,     0,     0,     0,   105,     0,     0,     0,
       0,   512,     0,   170,   171,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,     0,     0,   172,   173,     0,     0,
       0,   105,   182,   183,   184,   185,     0,     0,   186,   187,
     174,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,   514,   176,   170,   171,     0,   177,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
       0,     0,   178,   179,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,     0,     0,   186,   187,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,     0,     0,   516,     0,   170,
     171,   174,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
       0,     0,   172,   173,     0,     0,     0,   105,   182,   183,
     184,   185,     0,     0,   186,   187,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,   518,   176,
     170,   171,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,     0,     0,   186,
     187,     0,     0,   172,   173,     0,     0,     0,   105,     0,
       0,     0,     0,   523,     0,   170,   171,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,   177,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,   178,
     179,     0,     0,     0,     0,   180,     0,     0,   172,   173,
       0,     0,     0,   105,   182,   183,   184,   185,     0,     0,
     186,   187,   174,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,   525,   176,   170,   171,     0,   177,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,     0,     0,   178,   179,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,     0,     0,   186,   187,     0,     0,   172,
     173,     0,     0,     0,   105,     0,     0,     0,     0,   527,
       0,   170,   171,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,     0,     0,
       0,   180,     0,     0,   172,   173,     0,     0,     0,   105,
     182,   183,   184,   185,     0,     0,   186,   187,   174,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
     529,   176,   170,   171,     0,   177,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,     0,     0,
     178,   179,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,     0,
       0,   186,   187,     0,     0,   172,   173,     0,     0,     0,
     105,     0,     0,     0,     0,   531,     0,   170,   171,   174,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   177,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,   178,   179,     0,     0,     0,     0,   180,     0,     0,
     172,   173,     0,     0,     0,   105,   182,   183,   184,   185,
       0,     0,   186,   187,   174,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,   533,   176,   170,   171,
       0,   177,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,   178,   179,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,     0,     0,   186,   187,     0,
       0,   172,   173,     0,     0,     0,   105,     0,     0,     0,
       0,   535,     0,   170,   171,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,     0,     0,   172,   173,     0,     0,
       0,   105,   182,   183,   184,   185,     0,     0,   186,   187,
     174,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,   540,   176,   170,   171,     0,   177,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
       0,     0,   178,   179,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,     0,     0,   186,   187,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,     0,     0,   676,     0,   170,
     171,   174,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
       0,     0,   172,   173,     0,     0,     0,   105,   182,   183,
     184,   185,     0,     0,   186,   187,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,   722,   176,
     170,   171,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,     0,     0,   186,
     187,     0,     0,   172,   173,     0,     0,     0,   105,     0,
       0,     0,     0,   742,     0,   170,   171,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,   177,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,   178,
     179,     0,     0,     0,     0,   180,     0,     0,   172,   173,
       0,     0,     0,   105,   182,   183,   184,   185,     0,     0,
     186,   187,   174,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,   789,   176,   170,   171,     0,   177,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,     0,     0,   178,   179,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,     0,     0,   186,   187,     0,     0,   172,
     173,     0,     0,     0,   105,     0,     0,     0,     0,   793,
       0,   170,   171,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,     0,     0,
       0,   180,     0,     0,   172,   173,     0,     0,     0,   105,
     182,   183,   184,   185,     0,     0,   186,   187,   174,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
     799,   176,   170,   171,     0,   177,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,     0,     0,
     178,   179,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,     0,
       0,   186,   187,     0,     0,   172,   173,     0,     0,     0,
     105,     0,     0,     0,     0,   818,     0,   170,   171,   174,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   177,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,   178,   179,     0,     0,     0,     0,   180,     0,     0,
     172,   173,     0,     0,     0,   105,   182,   183,   184,   185,
       0,     0,   186,   187,   174,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,   826,   176,   170,   171,
       0,   177,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,   178,   179,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,     0,     0,   186,   187,     0,
       0,   172,   173,     0,     0,     0,   105,     0,     0,     0,
       0,   828,     0,   170,   171,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,     0,     0,   172,   173,     0,     0,
       0,   105,   182,   183,   184,   185,     0,     0,   186,   187,
     174,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,   861,   176,   170,   171,     0,   177,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
       0,     0,   178,   179,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,     0,     0,   186,   187,     0,     0,   172,   173,     0,
       0,     0,   105,     0,     0,     0,     0,   903,     0,   170,
     171,   174,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
       0,     0,   172,   173,     0,     0,     0,   105,   182,   183,
     184,   185,     0,     0,   186,   187,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,   304,     0,   170,   176,
       0,     0,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,     0,     0,   186,
     187,   172,   173,     0,     0,     0,   105,     0,     0,     0,
       0,   914,     0,     0,     0,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,     0,     0,   172,   173,   170,   171,
       0,   105,   182,   183,   184,   185,     0,     0,   186,   187,
     174,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,   177,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
       0,   172,   173,     0,     0,     0,   105,     0,   603,     0,
       0,     0,     0,     0,     0,   174,     0,   182,   183,   184,
     185,   175,     0,   186,   187,     0,     0,     0,   176,   170,
     171,     0,   177,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,   178,   179,     0,
       0,     0,     0,   180,     0,   564,   703,     0,     0,     0,
     704,     0,   182,   183,   184,   185,     0,     0,   186,   187,
       0,     0,   172,   173,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,   170,   171,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
      68,     0,     0,     0,   180,     0,   181,   172,   173,     0,
       0,     0,   105,   182,   183,   184,   185,     0,     0,   186,
     187,   174,     0,     0,     0,     0,     0,   175,     0,   170,
     171,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
     478,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   172,   173,   186,   187,     0,   105,     0,     0,
       0,     0,     0,     0,   170,   171,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,   690,     0,   172,   173,     0,
       0,     0,   105,   182,   183,   184,   185,     0,     0,   186,
     187,   174,     0,     0,     0,     0,     0,   175,     0,   170,
     171,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,   178,   179,     0,     0,     0,     0,   180,
     782,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   172,   173,   186,   187,     0,   105,     0,     0,
       0,     0,     0,     0,   170,   171,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,   177,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,     0,     0,   178,   179,
       0,     0,     0,     0,   180,   795,     0,   172,   173,     0,
       0,     0,   105,   182,   183,   184,   185,     0,     0,   186,
     187,   174,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,   177,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,   -40,     1,   178,   179,     0,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,     0,     0,   186,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,   -39,     1,
     264,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    17,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,    21,     0,     0,     0,     0,
     105,     0,     0,     0,    15,    22,     0,     0,     0,   265,
      16,    70,     0,     0,     0,     0,    17,    71,    18,     0,
     -42,     1,     0,     0,     0,     0,     0,    20,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,  -230,
       0,     0,    22,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,   -41,     1,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    21,   -44,     1,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    17,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    21,   -43,     1,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,    21,
     -45,     1,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      17,     0,    18,     0,     0,     0,   313,     0,     0,     0,
       0,    20,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    21,     0,   547,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,     0,
      18,     0,     0,     0,     0,     0,   105,     0,     0,    20,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    21,     0,     0,     0,   105,     0,
       0,     0,     0,     0,    22,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,   988,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,     0,
       0,    68,     0,     0,     0,     0,   548,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,   802,     0,     0,
       0,     0,    17,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,    20,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,     0,     0,    21,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,   264,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,   384,     0,     0,     0,
      68,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,   105,
       0,     0,     0,   520,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,    18,     0,
       0,     0,     0,   265,     0,     0,   105,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    44,     0,     0,
       0,     0,    68,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,   105,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,    16,     0,     0,     0,     0,     0,    17,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,    20,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,    72,     0,    68,     0,     0,     0,     0,     0,   410,
     411,     0,     0,    22,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,    16,     0,     0,     0,     0,     0,    17,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      20,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      44,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,   410,   579,     0,     0,    22,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   172,
     173,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,    18,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,     0,     0,    68,     0,     0,
       0,   603,     0,     0,     0,    72,     0,     0,     0,     0,
     182,   183,   184,   185,     0,     0,   186,   187,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,    16,     0,     0,
       0,     0,     0,    17,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    20,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,    72,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,   139,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,    16,     0,     0,
       0,     0,     0,    17,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    20,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,   272,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,    20,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    44,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,   446,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,   105,     0,     0,    68,     0,     0,
       0,     0,   708,   174,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     177,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,     0,     0,   178,   179,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,     0,     0,   186,   187,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    20,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    44,     0,     0,     0,     0,    21,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,   450,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    20,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,     0,     0,     0,
       0,    21,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,     0,
       0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
      15,   279,    89,   167,    19,   291,    21,   278,    88,   398,
     333,   140,    49,   392,   432,   176,   700,   636,     0,     0,
     138,    83,    84,   103,   549,   564,   432,   170,    43,   172,
     173,   335,     1,   413,   279,   178,   179,    82,    82,   101,
     636,   472,   466,   636,    25,    26,    27,     1,     1,    31,
     263,   279,    67,    68,     1,    81,    18,    72,    94,    48,
     852,    87,    64,     1,   101,    25,    81,    82,    94,     0,
      76,   495,    87,   160,    63,   616,     1,   279,    89,    94,
      61,     1,     1,    73,    65,    66,     3,     4,    94,    36,
     101,   153,     1,    62,    25,    26,    27,     1,   100,    89,
       1,    82,   147,   147,     1,    65,   100,    99,     1,   116,
     381,   105,   101,   120,   106,    97,   908,    98,     1,   155,
      89,     1,   167,   167,     1,    97,   141,   291,   143,   155,
      61,   295,   147,     1,    65,    66,    89,   266,   416,     1,
     155,    94,    89,   105,   422,     1,   424,   265,   266,   103,
     176,    82,   167,   240,     1,   170,   171,   172,   173,   239,
     289,   176,   143,   178,   179,   180,   147,    98,   106,   587,
     474,   416,   697,   235,   236,   716,   701,    36,    98,   104,
       1,   106,   189,     1,   166,   104,   167,   415,   416,    98,
      49,   404,    51,     0,   407,   574,   576,   106,     1,   103,
     343,   344,   345,   104,     1,   106,    99,   104,   180,   106,
     616,   413,   105,   415,   416,   428,   147,     1,    25,    26,
      27,   104,   105,    82,   104,     1,   106,   104,     1,    89,
      98,   246,   393,   248,   279,   279,   167,    99,   857,   923,
     859,   665,   101,   105,   103,   281,   291,   291,   104,   680,
     295,   295,     1,   268,    61,   281,     0,   104,    65,    66,
       1,    98,     1,   687,   279,   102,   281,    46,    47,   106,
      91,   542,   811,    91,   815,    96,   291,     1,    99,     1,
     295,   102,   103,   104,   105,     1,   104,   106,   147,    89,
     408,    98,     1,   380,    94,   713,    99,   462,   279,   464,
     919,     1,   105,   285,     1,    89,   103,   314,   315,     1,
     291,     1,     1,     1,   295,   322,   323,     1,     1,     1,
     104,   700,    64,    99,   467,    98,   750,   946,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   279,     1,
     946,   333,   101,   946,     1,   104,   105,     1,   888,   331,
     291,   333,   575,   104,   295,   104,   338,   393,   646,   910,
     888,   416,   416,   762,   576,   994,   100,   392,   393,     1,
     104,   103,    91,    16,    17,  1004,   713,    20,   104,   716,
      99,   363,   816,     1,     1,   104,   105,    89,   413,    99,
     415,   416,    99,   674,     1,   105,   100,    91,   105,     1,
     940,   392,   104,   943,   104,   104,   104,   432,   100,   690,
     279,   104,   940,    20,    57,   943,     1,   399,     1,     1,
       1,     1,    98,     1,   415,   416,     1,    70,    71,    72,
      53,   966,    89,   832,     1,     1,    79,   888,   100,   102,
       1,   432,   467,   460,   101,    99,   463,   472,   440,    92,
       1,   100,   101,    64,    97,   104,     1,    64,   623,    48,
       1,  1001,   279,   897,     1,   100,   631,  1007,   633,  1009,
    1010,   103,  1012,  1001,    63,   416,     1,   459,   815,  1007,
       1,  1009,  1010,    20,  1012,   103,   103,   130,    68,   940,
     105,     1,   943,   100,    96,   138,    98,   140,     1,   933,
     102,   103,   104,   105,   521,     1,    89,   788,    53,    91,
      20,    94,   101,   888,    18,   100,    53,   798,   101,   100,
      98,   546,   100,   166,    16,   100,   679,    64,    53,   554,
       1,   702,    99,    99,   923,    96,   869,    98,   181,     1,
     888,   102,   103,   104,   105,    99,     1,   416,    99,   574,
    1001,   576,     1,     1,    64,   100,  1007,    98,  1009,  1010,
     203,  1012,   587,   100,    99,   940,     1,   102,   943,     1,
       1,    20,   662,     1,     1,   100,   864,    98,   977,   867,
     102,     1,   564,   574,   106,    20,    89,   612,   660,   606,
     100,   616,   940,     1,   875,   943,   587,    68,   623,   416,
      20,   105,    98,   102,    53,     1,   631,   250,   633,   591,
     749,   636,   594,   660,    20,    64,     1,   100,    53,   102,
     602,   603,   265,   266,   267,   616,  1001,    98,     1,    64,
       1,     1,  1007,   921,  1009,  1010,    98,  1012,     1,     1,
       1,    89,   285,    98,    64,   636,   289,     1,     1,    97,
     931,   100,     1,  1001,   679,   680,     5,    89,     1,  1007,
      54,  1009,  1010,    72,  1012,   100,   702,    98,   693,   312,
      98,    98,   968,    82,     1,   700,     1,   702,     5,    15,
     100,    89,     1,    68,   781,     1,     1,   106,   713,   332,
     780,   716,   335,    89,   337,     1,     1,    72,    99,     1,
     106,   106,   684,   104,   776,   777,   106,    82,   102,   700,
     735,     1,     1,    66,     1,    68,    89,   101,    89,    89,
      73,   105,   713,   888,    77,   716,    89,    89,    89,     1,
      11,     1,   141,     1,   143,    89,    89,     1,   147,   721,
      89,    66,     1,    68,    99,    12,    89,   919,    73,   731,
     105,   733,    77,    62,    90,   398,   930,   101,   167,    68,
      13,   105,    89,    26,    89,   408,   141,   176,   143,    20,
      89,   180,   147,    89,    89,   940,    99,   874,   943,    99,
      16,    17,   105,    89,    89,   105,   768,    89,   770,   432,
     815,   660,   167,   662,   968,   960,    68,   440,    61,    89,
      89,    73,    89,    66,    14,    77,   449,   450,    25,   974,
      27,    99,    46,    47,   102,    76,   100,    89,   983,    89,
     985,    89,   994,   460,   815,    89,   463,   852,    99,   811,
      89,   474,  1004,    94,   105,    98,  1001,   246,   103,   248,
     940,    98,  1007,   943,  1009,  1010,    96,  1012,    65,   104,
      99,   102,   102,   103,    99,   106,   105,   839,    61,   268,
     105,   852,    65,   888,    98,   102,   848,   102,   102,   894,
     279,   246,   106,   248,    99,   930,   930,   869,    46,    47,
     105,    99,   291,   908,   102,   910,   295,   869,   106,   104,
     105,    46,    47,   268,   351,   352,   353,   354,   923,   104,
     105,  1001,    46,    47,   279,   930,   549,  1007,    68,  1009,
    1010,    11,  1012,   968,   968,   940,   291,   908,   943,   910,
     295,   946,     1,    18,    19,    20,    21,     5,     6,     7,
     912,   913,   923,    98,   102,   960,    46,    47,   106,   930,
      20,   102,   103,   968,   587,    54,   355,   102,   100,   974,
     593,   106,     8,     9,    10,   946,   104,   600,   983,   105,
     985,   100,   605,    58,   346,   347,    46,    47,    72,   102,
     103,   104,    98,   616,    98,    20,  1001,   968,    82,     1,
     623,    98,  1007,   392,  1009,  1010,    20,  1012,   631,   930,
     633,   973,   348,   349,   350,    91,   978,   356,   357,   105,
      98,    46,    47,   104,   413,   104,   415,   416,   100,    89,
     104,    99,    46,    47,   104,   101,    98,   392,    98,    67,
    1002,    48,   102,   432,   101,    99,   106,   968,     1,    98,
      91,   104,    99,    99,   104,   100,     1,   141,   413,   143,
     415,   416,    99,   147,    89,   105,     1,    57,    57,   432,
     104,     1,     1,    98,   697,    89,    99,   102,   701,    99,
      99,   106,    99,   167,    98,    91,    99,    99,   102,   104,
     713,    57,   106,   716,   104,    99,    99,   355,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    27,     0,   930,    51,   181,   295,    36,
     250,   574,   416,   746,   415,    60,   749,   700,   415,   587,
     440,    66,   850,   850,   432,    70,   147,   427,    73,   762,
     894,   865,    77,   143,   865,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   315,   358,   546,   359,    94,
     360,   693,   246,    98,   248,   554,   171,   361,   376,   104,
     362,    -1,   107,   108,   109,   110,    -1,    -1,   113,   114,
      -1,    -1,    -1,    -1,   268,   574,    -1,   576,    -1,    -1,
     813,   546,   815,    -1,    -1,   279,    -1,    -1,   587,   554,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,   832,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,
      -1,   576,    -1,   612,   587,    -1,    -1,   616,    -1,   852,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,   432,    -1,    -1,    -1,   636,    -1,    -1,
      -1,    -1,    -1,   616,    -1,    -1,    -1,   612,    -1,    -1,
     623,    -1,    -1,    -1,    -1,   888,    -1,    -1,   631,     1,
     633,   355,    -1,   636,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   636,    -1,    -1,    -1,   908,    -1,   910,    20,   587,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    96,    -1,    -1,    -1,   392,    -1,
      -1,   700,    -1,    -1,    46,    47,    -1,   940,   616,    -1,
     943,    -1,    -1,    -1,   713,   623,    -1,   716,    -1,   413,
      -1,   415,   416,   631,    -1,   633,    -1,   960,   636,    -1,
      -1,    -1,    -1,   966,    -1,   700,   735,    -1,   432,    -1,
     713,   974,    -1,   716,   977,    -1,    -1,    89,    -1,    91,
     983,    -1,   985,    -1,    96,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,  1001,    -1,
     735,    -1,    -1,    -1,  1007,    -1,  1009,  1010,    -1,  1012,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   587,    -1,
       1,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   713,    -1,    -1,   716,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   815,   616,    -1,    -1,
      -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   631,    -1,   633,    46,    47,   636,    -1,    -1,
      51,    -1,   815,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,   546,   852,    -1,    66,    -1,    -1,    -1,    -1,
     554,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   852,
     574,    -1,   576,    -1,   857,    -1,   859,    98,    99,    -1,
      -1,    -1,    -1,   587,    -1,   894,   107,   108,   109,   110,
      -1,    -1,   113,   114,   432,    -1,    -1,   815,    -1,   908,
      -1,   910,    -1,    -1,   713,   888,    -1,   716,   612,    -1,
      -1,    -1,   616,    -1,   923,    -1,    -1,    -1,    -1,   894,
      -1,   930,    -1,    -1,    -1,   908,    -1,   910,    -1,    -1,
      -1,    -1,   636,    -1,   852,    -1,   919,   946,    -1,   857,
     587,   859,    -1,    -1,    -1,    -1,    -1,    -1,   923,    -1,
      -1,   432,    -1,     1,    -1,   930,    -1,   940,    -1,   968,
     943,    -1,    -1,   946,    -1,    -1,    -1,    -1,    -1,   616,
     888,   946,    -1,    -1,    -1,    -1,   623,   960,    -1,    -1,
      -1,    -1,    -1,    -1,   631,    -1,   633,    -1,    -1,   636,
     908,   974,   910,   968,    -1,    -1,   700,    -1,    -1,    -1,
     983,   919,   985,    51,    -1,    -1,   815,    -1,    -1,   713,
      -1,   994,   716,    -1,    -1,    -1,    -1,    -1,  1001,    -1,
      -1,  1004,   940,    -1,  1007,   943,  1009,  1010,   946,  1012,
      -1,   735,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   960,   852,    -1,    -1,    -1,    -1,   857,   587,
     859,    99,    -1,    -1,    -1,    -1,   974,    -1,    -1,    -1,
      -1,   432,    -1,    -1,    -1,   983,   713,   985,    -1,   716,
      -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,   616,   888,
      -1,    -1,    -1,  1001,    -1,   623,  1004,    -1,    -1,  1007,
      -1,  1009,  1010,   631,  1012,   633,    -1,    -1,   636,   908,
      -1,   910,    -1,    -1,    -1,    -1,   587,    -1,    -1,    -1,
     919,   815,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   940,    -1,    -1,   943,   616,    -1,   946,    -1,    -1,
      -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,   852,    -1,
     631,   960,   633,    -1,    -1,   636,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   974,    -1,    -1,   815,    -1,
      -1,    -1,    -1,    -1,   983,   713,   985,    -1,   716,    -1,
      -1,    -1,    -1,    -1,    -1,   994,    -1,    96,    -1,    98,
     894,    -1,  1001,   102,    -1,  1004,    -1,   106,  1007,    -1,
    1009,  1010,    -1,  1012,   908,   852,   910,    -1,    -1,    -1,
     857,    -1,   859,    -1,    -1,    -1,   587,    -1,    -1,   923,
      -1,    -1,   432,    -1,    -1,    -1,   930,    -1,    -1,    -1,
      -1,    -1,   713,    -1,    -1,   716,    -1,    -1,    -1,    -1,
      -1,   888,   946,    -1,    -1,   616,    -1,     0,     1,    -1,
      -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     631,   908,   633,   910,   968,   636,    -1,    -1,    -1,    -1,
      -1,    -1,   919,    -1,    -1,    -1,    -1,   815,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   940,    -1,    -1,   943,    -1,    -1,   946,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,     1,    62,
      -1,    -1,    -1,   960,   852,    68,    -1,    70,    -1,   857,
      -1,   859,    -1,    76,    -1,    -1,    79,   974,    -1,    -1,
      -1,    -1,    -1,    -1,   815,    -1,   983,    -1,   985,    -1,
      -1,    94,   713,    -1,    -1,   716,    -1,   994,    -1,    -1,
     888,   104,    -1,    -1,  1001,    -1,    -1,  1004,    51,    -1,
    1007,    -1,  1009,  1010,    -1,  1012,    -1,    60,    -1,    62,
     908,   852,   910,    -1,    -1,    68,   857,   587,   859,    -1,
      -1,   919,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,   940,    -1,    -1,   943,   616,   888,   946,    -1,
      -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   631,   960,   633,    -1,    -1,   636,   908,    -1,   910,
      -1,    -1,    -1,    -1,    -1,    -1,   974,    -1,   919,    -1,
      -1,    -1,    -1,    -1,   815,   983,    -1,   985,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,    -1,   940,
      -1,    -1,   943,  1001,    -1,   946,  1004,    -1,    -1,  1007,
      -1,  1009,  1010,    -1,  1012,    -1,    -1,    -1,    -1,   960,
      -1,   852,    -1,    -1,    -1,    -1,   857,    -1,   859,    -1,
      -1,    -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   983,   713,   985,    -1,   716,    -1,    -1,    -1,
      -1,    -1,     1,   994,    -1,    -1,    -1,   888,    -1,    -1,
    1001,    -1,    -1,  1004,    -1,    -1,  1007,    -1,  1009,  1010,
      -1,  1012,    -1,    -1,    -1,    -1,    -1,   908,    -1,   910,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   919,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,   170,   171,   172,   173,   940,
      -1,    60,   943,   178,   179,   946,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,   960,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,   974,     1,   815,    -1,    -1,    -1,    98,
      99,    -1,   983,    -1,   985,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,   994,   113,   114,    -1,    -1,    -1,    -1,
    1001,    -1,    -1,  1004,    -1,    -1,  1007,    -1,  1009,  1010,
      -1,  1012,   852,   170,   171,   172,   173,   857,    -1,   859,
      -1,   178,   179,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,   888,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,   908,    -1,
     910,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   919,
     107,   108,   109,   110,    -1,    -1,   113,   114,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
     940,    -1,    -1,   943,    -1,    -1,   946,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     960,   356,   357,   358,   359,   360,   361,   362,    -1,    -1,
      -1,    -1,    -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   983,    -1,   985,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   994,    -1,    -1,    -1,    -1,    -1,
      -1,  1001,    96,    -1,  1004,    -1,    -1,  1007,    -1,  1009,
    1010,    -1,  1012,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,    -1,   356,
     357,   358,   359,   360,   361,   362,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    -1,   467,    -1,    59,    60,    -1,   472,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,   100,   101,    -1,    -1,   104,
      -1,    -1,   107,   108,   109,   110,     1,    -1,   113,   114,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     467,    -1,    -1,    -1,    -1,   472,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    -1,    18,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    96,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    51,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,     1,   100,   101,    -1,    -1,   104,
      -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,   114,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,   679,   680,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   693,    -1,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    51,    -1,
      -1,    98,    -1,   100,   101,    -1,    -1,   104,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,   679,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   693,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     1,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,   100,   101,    -1,    -1,   104,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     1,    -1,     3,     4,    94,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,   104,    -1,    20,   107,
     108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    60,    -1,    -1,    -1,    -1,    -1,    66,    70,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    94,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,   100,    46,    47,    -1,    -1,    -1,    51,   107,   108,
     109,   110,    -1,    -1,   113,   114,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,     1,    73,
       3,     4,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     114,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    46,    47,
     103,    -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,
     113,   114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,     1,    73,     3,     4,    -1,    77,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,   100,    46,    47,    -1,    -1,    -1,    51,
     107,   108,   109,   110,    -1,    -1,   113,   114,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
       1,    73,     3,     4,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,   114,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    98,    99,    -1,
      46,    47,    -1,    -1,    -1,    51,   107,   108,   109,   110,
      -1,    -1,   113,   114,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,     1,    73,     3,     4,
      -1,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   114,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    99,    -1,    46,    47,    -1,    -1,
      -1,    51,   107,   108,   109,   110,    -1,    -1,   113,   114,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,     1,    73,     3,     4,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   114,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      99,    -1,    46,    47,    -1,    -1,    -1,    51,   107,   108,
     109,   110,    -1,    -1,   113,   114,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,     1,    73,
       3,     4,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     114,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    98,    99,    -1,    46,    47,
      -1,    -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,
     113,   114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,     1,    73,     3,     4,    -1,    77,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
     107,   108,   109,   110,    -1,    -1,   113,   114,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
       1,    73,     3,     4,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,   114,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,   107,   108,   109,   110,
      -1,    -1,   113,   114,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,     1,    73,     3,     4,
      -1,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   114,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,   107,   108,   109,   110,    -1,    -1,   113,   114,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,     1,    73,     3,     4,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   114,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,   107,   108,
     109,   110,    -1,    -1,   113,   114,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,     1,    73,
       3,     4,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     114,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,
     113,   114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,     1,    73,     3,     4,    -1,    77,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
     107,   108,   109,   110,    -1,    -1,   113,   114,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
       1,    73,     3,     4,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,   114,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,   107,   108,   109,   110,
      -1,    -1,   113,   114,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,     1,    73,     3,     4,
      -1,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   114,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,   107,   108,   109,   110,    -1,    -1,   113,   114,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,     1,    73,     3,     4,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   114,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,   107,   108,
     109,   110,    -1,    -1,   113,   114,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,     1,    73,
       3,     4,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     114,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,
     113,   114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,     1,    73,     3,     4,    -1,    77,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
     107,   108,   109,   110,    -1,    -1,   113,   114,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
       1,    73,     3,     4,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,   114,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,   107,   108,   109,   110,
      -1,    -1,   113,   114,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,     1,    73,     3,     4,
      -1,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   114,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,   107,   108,   109,   110,    -1,    -1,   113,   114,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,     1,    73,     3,     4,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   114,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,   107,   108,
     109,   110,    -1,    -1,   113,   114,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,     1,    73,
       3,     4,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     114,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,
     113,   114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,     1,    73,     3,     4,    -1,    77,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,   114,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
     107,   108,   109,   110,    -1,    -1,   113,   114,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
       1,    73,     3,     4,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,   114,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,   107,   108,   109,   110,
      -1,    -1,   113,   114,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,     1,    73,     3,     4,
      -1,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   114,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,   107,   108,   109,   110,    -1,    -1,   113,   114,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,     1,    73,     3,     4,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,   114,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,   107,   108,
     109,   110,    -1,    -1,   113,   114,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,     1,    -1,     3,    73,
      -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
     114,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    46,    47,     3,     4,
      -1,    51,   107,   108,   109,   110,    -1,    -1,   113,   114,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    46,    47,    -1,    -1,    -1,    51,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,   107,   108,   109,
     110,    66,    -1,   113,   114,    -1,    -1,    -1,    73,     3,
       4,    -1,    77,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,   100,   101,    -1,    -1,    -1,
     105,    -1,   107,   108,   109,   110,    -1,    -1,   113,   114,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,   100,    46,    47,    -1,
      -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,   113,
     114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,     3,
       4,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,    46,    47,   113,   114,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    99,    -1,    46,    47,    -1,
      -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,   113,
     114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,     3,
       4,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,    46,    47,   113,   114,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    98,    99,    -1,    46,    47,    -1,
      -1,    -1,    51,   107,   108,   109,   110,    -1,    -1,   113,
     114,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     1,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,     0,     1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    94,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    56,   104,    -1,    -1,    -1,    60,
      62,    62,    -1,    -1,    -1,    -1,    68,    68,    70,    -1,
       0,     1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,   104,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,     0,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    94,     0,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    94,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    94,
       0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    79,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    94,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    79,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    94,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,   104,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    99,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,     1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     1,    -1,    -1,    -1,
      94,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    51,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    51,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    20,    -1,    94,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,   104,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,   114,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    20,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    51,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    99,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,   114,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    56,    62,    68,    70,    76,
      79,    94,   104,   116,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   146,   156,   157,   158,   159,   160,   199,
     207,   222,     1,    36,    89,   128,   129,   130,   131,   131,
       1,   131,     1,   128,     1,   131,     1,    62,   128,   141,
       0,   134,   136,   140,   156,   133,   134,    76,    94,   140,
      62,    68,    20,   159,   161,     1,   128,     1,   104,   106,
       1,    64,   100,   161,   200,   201,     1,    64,   161,   166,
       1,   104,   106,     1,    53,   167,   131,    98,   134,     1,
     128,   131,     1,   131,    18,    51,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   118,   119,   120,   121,   122,
     123,   126,   127,   128,   131,   162,   163,   164,     1,   104,
     106,     1,     5,   131,     1,   123,   125,   128,    60,   101,
     118,   157,   160,   161,   173,   180,   199,   202,   203,   204,
     205,   206,   207,   200,   201,   105,   201,     1,   123,   124,
     166,   167,     1,   125,   168,     1,   100,   100,   147,     1,
       3,     4,    46,    47,    60,    66,    73,    77,    92,    93,
      98,   100,   107,   108,   109,   110,   113,   114,   117,   119,
     126,   128,   131,   140,   142,   143,   144,   145,   266,   267,
     268,   269,   270,   271,   273,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   305,     1,   104,     1,   161,   200,   201,     1,   161,
     166,   102,   276,   276,   161,   276,    64,    18,   105,    18,
     105,     1,     5,     1,   104,     1,   131,   181,     1,   131,
     174,   175,   176,   181,     1,    60,   118,   118,   157,   205,
       1,   104,   101,   203,   201,     1,   125,     1,   167,   100,
     169,   105,     1,   101,   131,   139,   140,   208,   209,   118,
     146,   148,   149,   150,   151,   157,   160,   199,   207,     1,
     128,   277,   279,   284,     1,   283,     1,   284,     1,   284,
     106,     1,   106,     1,   119,   123,   124,     1,   284,     1,
     284,     1,   119,   128,   305,   101,   131,   142,   106,   106,
      98,   102,   106,    16,    99,   105,    99,   106,   102,     1,
     131,    46,    47,     5,     6,     7,     3,     4,     8,     9,
      10,    18,    19,    20,    21,    58,    16,    17,    11,    12,
      13,    14,    15,    90,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    96,   303,   304,   201,   201,
     166,   167,   103,   102,     1,   118,   165,   118,   131,   164,
       1,   104,    98,    54,   102,   186,     1,   104,   105,    96,
     102,   103,   186,     1,   181,     1,   174,   181,   118,   169,
     100,   101,   129,   157,   160,   161,   170,   171,   172,   173,
     178,   179,   180,   189,   190,   191,   192,   193,   194,   199,
     207,   212,   213,   222,     1,   125,   131,     1,   101,   104,
     105,   131,   152,   153,   154,   174,   101,   149,   104,    62,
      68,   150,     1,    68,     1,   131,   102,   103,   104,   102,
     274,   275,   276,   274,   276,     1,    98,    99,   102,   276,
     276,     1,    99,   101,   105,     1,    68,    68,    99,   272,
     305,     1,   305,     1,    68,    73,    77,   144,     1,   143,
      73,   131,     1,   305,     1,    98,     1,   284,     1,   284,
       1,   284,     1,   289,     1,   289,     1,   290,     1,   290,
       1,   290,     1,   291,     1,   291,     1,   291,     1,   291,
       1,   119,   122,     1,   292,     1,   292,     1,   293,     1,
     294,     1,   295,     1,   296,     1,   297,     1,    91,   305,
       1,   300,   167,   169,     1,   103,    11,     1,    99,   118,
     157,   182,   183,   184,   185,     1,   124,   187,     1,   103,
       1,   131,   175,     1,   100,   177,   210,   305,     1,   103,
       1,   186,   104,   186,    98,   194,   157,   178,   191,   101,
     171,     1,   104,   188,   212,   212,   195,   213,   186,     1,
      49,    50,    52,    55,    59,    66,    67,    69,    71,    72,
      74,    77,    78,    98,   101,   118,   119,   126,   128,   131,
     157,   160,   185,   198,   212,   214,   215,   216,   217,   218,
     219,   221,   222,   223,   224,   226,   227,   228,   229,   231,
     232,   238,   239,   241,   242,   243,   245,   246,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   269,   278,   280,
     281,   282,   285,   286,   301,     1,   209,    98,   104,   100,
     131,     1,   131,    99,   106,    98,     1,   305,   275,   276,
     210,   276,   210,     1,    99,   272,     1,   284,     1,    99,
      99,   287,   101,    99,   105,     1,   103,    98,     1,   103,
      99,   272,     1,    91,   169,   118,     1,    97,   176,    99,
     105,   118,   105,   101,   105,   177,   211,     1,    99,   182,
     186,   128,   196,   197,   198,   214,   215,   100,   101,   104,
       1,    98,     1,   305,     1,   104,   131,     1,   104,   305,
       1,    98,     1,    98,     1,    98,   259,     1,    98,     1,
     104,   131,     1,   305,   305,   174,   106,     1,    91,   118,
      98,   214,   216,   104,   128,   157,   219,   104,   100,   233,
     219,   219,   118,   128,   218,   227,   247,   249,   104,     1,
      98,     1,   212,    99,   104,     1,   161,   200,   201,     1,
     161,   166,    99,   272,     1,   103,   169,     1,    99,     1,
     284,     1,   287,     1,   305,    99,   272,   169,    99,     1,
     299,   176,     1,   183,   184,     1,   176,     1,   124,   101,
     101,   105,    99,   106,   196,   215,    98,   196,     1,   305,
       1,   104,     1,   104,     1,   104,     1,   305,     1,   305,
       1,    99,   118,   260,   261,     1,     1,   104,     1,    91,
     104,    99,    66,   174,     1,    99,   272,    48,    63,   101,
     234,   235,   236,   237,    67,   175,     1,   105,     1,   104,
     305,     1,   305,    61,    65,   262,   263,   264,   265,    48,
     155,   101,   201,   201,   166,   167,    99,   169,    99,   169,
       1,   101,   177,    66,   196,    99,   272,     1,    99,     1,
      99,    99,   175,    99,   104,   305,     1,    98,     1,     1,
      99,     1,    91,     1,   305,   306,   101,   235,   236,   101,
     215,   237,    98,    91,     1,   227,     1,   248,   249,   104,
      99,    99,     1,    98,     1,   212,   263,   265,   212,   144,
     100,   167,   169,    98,   104,    99,    49,   219,   220,   221,
     223,   225,   230,   238,   240,   244,   245,   246,     1,   261,
     104,     1,    99,   272,     1,     1,    91,   101,   305,   305,
      99,     1,   248,     1,   212,     1,   118,   184,   148,   169,
      99,   272,   104,    98,    57,   220,   220,   118,   104,     1,
       1,    99,    99,    99,   219,    99,    99,    99,     1,   104,
      99,   305,   219,   175,   104,   305,     1,   104,   219,   219,
     104,    99,    91,   248,   104,   220,   305,    99,   248,    57,
      99,   220,    99,   220,   220,   220
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   115,   116,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     121,   121,   121,   122,   122,   122,   123,   123,   124,   125,
     126,   126,   127,   128,   128,   129,   130,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   134,   134,
     135,   135,   135,   135,   135,   135,   136,   136,   137,   137,
     137,   137,   137,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   140,   140,   140,   141,   142,   142,
     142,   143,   144,   144,   144,   145,   145,   145,   146,   147,
     148,   148,   149,   149,   150,   150,   150,   151,   151,   151,
     151,   152,   152,   153,   154,   155,   156,   156,   156,   156,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   160,   160,   160,   160,   160,   160,   160,   160,   161,
     161,   161,   162,   162,   163,   163,   164,   164,   164,   165,
     165,   166,   166,   166,   166,   167,   167,   167,   168,   168,
     168,   169,   169,   170,   170,   171,   171,   171,   171,   171,
     172,   172,   172,   172,   172,   172,   172,   173,   173,   174,
     174,   174,   175,   175,   175,   175,   176,   176,   176,   176,
     176,   177,   177,   178,   178,   179,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   181,   181,   181,   181,   181,
     182,   182,   182,   182,   182,   183,   184,   184,   184,   184,
     185,   186,   186,   186,   187,   187,   187,   188,   188,   189,
     190,   191,   192,   193,   193,   194,   194,   195,   195,   195,
     195,   196,   197,   197,   197,   197,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   200,   200,   200,
     200,   201,   201,   202,   202,   203,   203,   203,   203,   203,
     203,   204,   205,   205,   206,   207,   207,   207,   207,   207,
     207,   207,   208,   208,   208,   208,   209,   209,   210,   210,
     210,   210,   211,   211,   211,   212,   212,   213,   214,   215,
     215,   216,   216,   216,   217,   218,   218,   219,   219,   219,
     219,   219,   219,   220,   220,   220,   220,   220,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     222,   223,   224,   224,   225,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   228,   228,   229,
     230,   231,   232,   232,   232,   232,   233,   233,   233,   233,
     234,   234,   235,   236,   236,   237,   237,   237,   237,   237,
     238,   239,   239,   239,   239,   240,   241,   242,   243,   243,
     243,   243,   243,   243,   244,   244,   244,   245,   245,   245,
     246,   247,   247,   247,   247,   248,   248,   249,   249,   249,
     250,   250,   250,   250,   251,   251,   251,   251,   252,   252,
     252,   252,   253,   253,   253,   254,   254,   254,   254,   255,
     255,   255,   255,   255,   256,   257,   257,   257,   257,   258,
     258,   258,   259,   259,   259,   260,   260,   261,   262,   262,
     263,   264,   264,   264,   264,   265,   265,   266,   266,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   268,   268,   268,   268,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   270,
     270,   271,   271,   272,   272,   272,   273,   273,   273,   273,
     273,   273,   273,   273,   274,   274,   275,   275,   275,   276,
     276,   276,   277,   277,   277,   278,   278,   278,   278,   278,
     278,   278,   278,   279,   279,   279,   279,   279,   279,   280,
     280,   280,   280,   281,   282,   283,   283,   283,   283,   283,
     284,   284,   284,   285,   285,   286,   286,   287,   287,   287,
     287,   287,   287,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   289,   289,   289,   289,   289,   289,   289,   290,
     290,   290,   290,   290,   291,   291,   291,   291,   291,   291,
     291,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   293,   293,   293,   293,   293,   294,   294,   294,
     295,   295,   295,   296,   296,   296,   297,   297,   297,   298,
     298,   298,   299,   299,   299,   299,   299,   300,   300,   301,
     301,   302,   302,   302,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   305,   306
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     3,     1,     0,     1,
       1,     1,     2,     2,     2,     3,     1,     2,     1,     2,
       3,     4,     2,     3,     3,     4,     1,     1,     3,     4,
       2,     3,     3,     4,     5,     6,     4,     5,     5,     6,
       1,     2,     2,     5,     5,     2,     4,     1,     1,     3,
       3,     3,     1,     1,     1,     4,     3,     2,     4,     9,
       1,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     5,     7,     6,     3,     2,     3,     4,     3,
       3,     2,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     0,     2,     3,     2,     0,     2,     2,     1,     3,
       3,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3,     3,     1,     3,     3,     4,     1,     3,     2,     3,
       3,     1,     1,     2,     2,     2,     3,     3,     4,     4,
       2,     3,     2,     3,     2,     3,     4,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     2,     3,     2,     3,
       1,     0,     2,     2,     1,     3,     3,     1,     1,     2,
       1,     2,     2,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     4,     5,     7,     6,     1,     1,     3,     4,
       4,     4,     5,     5,     5,     3,     4,     2,     3,     2,
       3,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     6,     5,     2,     3,     4,
       5,     6,     1,     3,     2,     3,     1,     2,     2,     3,
       3,     4,     1,     3,     3,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       4,     4,     5,     4,     5,     6,     7,     6,     1,     1,
       1,     1,     1,     1,     1,     5,     2,     3,     4,     7,
       7,     2,     4,     2,     3,     5,     2,     3,     3,     4,
       1,     2,     2,     1,     2,     3,     2,     2,     3,     2,
       4,     2,     2,     3,     4,     2,     1,     7,     7,     6,
       7,     3,     5,     4,     7,     6,     7,     2,     2,     3,
       2,     0,     1,     1,     2,     0,     1,     1,     3,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     3,     2,     3,     5,     3,     2,     3,     5,
       5,     2,     4,     3,     1,     3,     3,     4,     2,     1,
       2,     2,     2,     3,     2,     1,     3,     2,     1,     2,
       2,     4,     2,     3,     4,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     1,     4,
       5,     5,     6,     3,     3,     4,     5,     2,     3,     6,
       5,     3,     3,     1,     3,     3,     3,     3,     4,     4,
       4,     4,     3,     3,     1,     2,     3,     3,     2,     2,
       3,     3,     3,     3,     2,     3,     4,     5,     6,     5,
       6,     4,     4,     4,     4,     3,     4,     3,     4,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     1,     2,
       1,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       1,     2,     2,     5,     4,     4,     5,     4,     2,     5,
       4,     5,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     5,     4,     3,     5,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval);
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
#line 384 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 157 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);
root= (yyval.t);

    }
#line 3622 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 396 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 118 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3635 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 407 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 118 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3648 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 418 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 118 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3661 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 429 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 118 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3674 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 440 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 118 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3687 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 451 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 118 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3700 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 462 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 123 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3713 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 473 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 123 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3726 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 484 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 117 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3739 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 495 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 117 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3752 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 506 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 117 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3765 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 517 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 103 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3778 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 528 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 103 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3791 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 539 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 103 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3804 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 550 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 103 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3817 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 561 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 103 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3830 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 572 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 103 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3843 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 583 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 102 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3856 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 594 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 102 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3869 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 605 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 102 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3882 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 616 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 62 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3895 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 627 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 62 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3908 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 638 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 62 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3921 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 649 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 53 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3934 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 660 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 53 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3953 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 677 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 74 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3966 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 688 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 46 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3979 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 699 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 82 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 3998 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 716 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 82 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4017 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 733 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 28 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4036 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 750 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 34 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4049 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 761 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 34 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4062 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 772 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 111 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4075 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 783 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 127 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4100 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 806 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 39 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4113 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 817 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

    }
#line 4122 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 824 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4135 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 835 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4148 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 846 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4161 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 857 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4180 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 874 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4199 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 891 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4218 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 908 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 26 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4243 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 931 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 125 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4256 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 942 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 125 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4275 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 959 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 57 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4288 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 970 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 57 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4307 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 987 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 61 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4332 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 1010 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 61 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4363 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 1039 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 61 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4376 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 1050 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 61 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4395 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 1067 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 61 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4414 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 1084 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 61 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4439 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 1107 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 8 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4452 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 1118 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 8 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4465 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 1129 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 83 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4490 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 1152 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 83 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4521 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 1181 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 83 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4534 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 1192 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 83 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4553 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 1209 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 83 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4572 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 1226 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 83 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4597 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 1249 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 134 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4634 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 1284 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 134 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4677 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 1325 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 134 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4702 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 1348 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 134 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4733 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 1377 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 134 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4764 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 1406 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 134 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4801 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 1441 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 141 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4814 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 1452 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 141 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4833 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 1469 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 175 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4852 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 1486 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 175 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4889 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 1521 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 175 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4926 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 1556 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 175 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4939 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 1567 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 175 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 4964 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 1590 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 86 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4977 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 1601 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 27 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 4990 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 1612 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 27 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5015 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 1635 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 27 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 5034 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 1652 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 165 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5059 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 1675 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 93 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5072 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 1686 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 93 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5085 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 1697 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 93 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5098 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 1708 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 179 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5129 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 1737 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 179 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5154 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 1760 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 179 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5173 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 1777 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 148 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5204 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 1806 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 85 );

        (yyval.t)->addChild((yyvsp[-8].t));

        (yyvsp[-8].t)->parent= (yyval.t);

        (yyvsp[-8].t)->nextSibbling= (yyvsp[-7].t);

        (yyval.t)->addChild((yyvsp[-7].t));

        (yyvsp[-7].t)->parent= (yyval.t);

        (yyvsp[-7].t)->nextSibbling= (yyvsp[-6].t);

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 5259 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 1859 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 1 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5272 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 1870 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 1 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5291 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 1887 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 184 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5304 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 1898 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 184 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5323 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 1915 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 45 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5348 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 1938 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 45 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5367 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 1955 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 45 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5380 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 1966 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 163 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5393 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 1977 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 163 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5406 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 1988 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 163 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5419 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 1999 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 163 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5432 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 2010 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 12 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5445 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 2021 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 12 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5458 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 2032 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 152 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5489 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 2061 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 137 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5502 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 2072 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 56 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5521 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 2089 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 153 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5534 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 2100 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 153 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5547 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 2111 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 153 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5560 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 2122 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 153 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5573 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 2133 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 153 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5586 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 2144 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 153 );

    }
#line 5595 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 2151 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 135 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5608 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 2162 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 135 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5627 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 2179 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 146 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5640 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 2190 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 146 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5659 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 2207 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5672 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 2218 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5685 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 2229 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5698 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 2240 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5711 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 2251 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5724 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 2262 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5737 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 2273 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5750 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 2284 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5763 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 2295 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5776 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 2306 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5789 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 2317 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5802 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 2328 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5815 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 2339 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5828 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 2350 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5841 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 2361 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 147 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5854 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 2372 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5897 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 2413 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5934 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 2448 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 5983 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 2495 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6026 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 2536 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6045 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 2553 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6058 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 2564 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6077 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 2581 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 182 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6102 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 2604 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 172 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6127 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 2627 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 172 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6152 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 2650 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 172 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6171 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 2667 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 176 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6184 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 2678 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 176 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6209 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 2701 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 77 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6222 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 2712 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 77 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6247 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 2735 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 156 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6260 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 2746 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 156 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6285 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 2769 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 156 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6304 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 2786 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 80 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6317 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 2797 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 80 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6342 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 2820 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 84 );

    }
#line 6351 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 2827 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 84 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6370 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 2844 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 84 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6389 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 2861 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 84 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6402 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 2872 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 75 );

    }
#line 6411 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 2879 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 75 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6430 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 2896 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 75 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6443 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 2907 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 70 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6456 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 2918 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 70 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6481 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 2941 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 70 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6500 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 2958 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 129 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6519 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 2975 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 129 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6544 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 2998 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 149 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6557 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 3009 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 149 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6576 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 3026 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 119 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6589 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 3037 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 119 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6602 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 3048 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 119 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6615 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 3059 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 119 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6628 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 3070 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 119 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6641 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 3081 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6654 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 3092 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6667 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 3103 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6680 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 3114 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6693 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 174:
#line 3125 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6706 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 175:
#line 3136 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6719 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 3147 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 88 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6732 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 3158 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 143 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6757 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 3181 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 143 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6788 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 3210 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 4 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6801 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 3221 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 4 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6826 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 3244 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 4 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6845 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 3261 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 65 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6858 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 3272 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 65 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6883 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 3295 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 65 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6902 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 3312 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 65 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6927 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 3335 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 37 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6940 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 3346 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 37 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 6965 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 3369 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 37 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6978 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 3380 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 37 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 6997 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 3397 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 37 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7016 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 3414 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 120 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7029 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 192:
#line 3425 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 120 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7042 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 3436 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 113 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7061 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 3453 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 113 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7074 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 3464 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 66 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7093 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 3481 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7118 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 3504 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7143 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 3527 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7174 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 3556 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7205 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 3585 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7218 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 3596 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7237 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 3613 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7250 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 3624 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7269 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 3641 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 138 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7282 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 3652 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 187 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7307 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 3675 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 187 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7338 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 3704 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 187 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7363 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 3727 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 187 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7382 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 3744 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 187 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7401 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 3761 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 21 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7414 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 3772 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 21 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7427 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 3783 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 21 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7452 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 3806 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 21 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7477 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 3829 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 21 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7496 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 3846 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 181 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7521 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 3869 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 178 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7540 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 3886 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 178 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7565 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 3909 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 178 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7578 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 3920 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 178 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7597 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 3937 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 124 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7610 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 3948 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 97 );

    }
#line 7619 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 3955 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 97 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7638 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 3972 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 97 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7651 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 3983 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 169 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7664 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 3994 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 169 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7689 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 4017 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 169 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 7708 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 227:
#line 4034 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 171 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7721 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 4045 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 171 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7734 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 4056 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 31 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7753 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 4073 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 50 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7766 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 4084 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 189 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7785 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 4101 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 16 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7804 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 4118 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 36 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7823 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 4135 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 36 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7848 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 235:
#line 4158 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 41 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7873 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 4181 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 41 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7904 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 4210 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 170 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7923 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 238:
#line 4227 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 170 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7948 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 4250 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 170 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 7973 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 4273 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 170 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8004 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 241:
#line 4302 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 40 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8017 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 4313 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 5 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8048 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 4342 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 5 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8085 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 4377 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 5 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8134 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 4424 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 5 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8177 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 4465 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 128 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8190 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 4476 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 128 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8203 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 4487 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8228 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 4510 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8259 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 4539 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8290 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 4568 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8321 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 252:
#line 4597 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8358 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 253:
#line 4632 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8395 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 4667 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8432 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 4702 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8451 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 256:
#line 4719 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 43 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8476 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 4742 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 109 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8495 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 4759 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 109 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8520 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 4782 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 109 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8533 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 4793 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 109 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8552 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 4810 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 90 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8571 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 4827 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 90 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8596 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 4850 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 154 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8609 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 4861 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 154 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8628 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 4878 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 58 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8641 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 266:
#line 4889 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 58 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8654 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 4900 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 58 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8667 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 4911 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 58 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8680 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 4922 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 58 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8693 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 4933 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 58 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8706 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 271:
#line 4944 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 166 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8719 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 4955 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 151 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8738 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 4972 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 151 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8751 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 4983 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 131 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8770 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 275:
#line 5000 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8813 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 276:
#line 5041 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8850 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 277:
#line 5076 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8863 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 278:
#line 5087 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8882 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 279:
#line 5104 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8907 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 280:
#line 5127 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8938 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 281:
#line 5156 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 136 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 8975 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 282:
#line 5191 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 112 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 8988 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 283:
#line 5202 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 112 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9013 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 284:
#line 5225 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 112 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9032 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 285:
#line 5242 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 112 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9051 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 286:
#line 5259 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 25 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9064 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 287:
#line 5270 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 25 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9083 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 288:
#line 5287 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 177 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9102 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 289:
#line 5304 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 177 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9127 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 290:
#line 5327 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 177 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9152 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 291:
#line 5350 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 177 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9183 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 292:
#line 5379 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 168 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9196 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 293:
#line 5390 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 168 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9221 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 294:
#line 5413 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 168 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9240 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 295:
#line 5430 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 98 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9259 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 296:
#line 5447 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 98 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9284 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 297:
#line 5470 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 7 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9297 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 298:
#line 5481 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 24 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9310 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 299:
#line 5492 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 167 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9323 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 300:
#line 5503 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 167 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9342 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 301:
#line 5520 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 115 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9355 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 302:
#line 5531 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 115 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9368 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 303:
#line 5542 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 115 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9381 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 304:
#line 5553 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 23 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9400 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 305:
#line 5570 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 145 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9419 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 306:
#line 5587 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 145 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9444 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 307:
#line 5610 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 121 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9457 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 308:
#line 5621 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 121 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9470 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 309:
#line 5632 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 121 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9483 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 310:
#line 5643 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 121 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9496 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 311:
#line 5654 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 121 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9509 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 312:
#line 5665 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 121 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9522 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 313:
#line 5676 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 180 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9535 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 314:
#line 5687 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 180 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9548 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 315:
#line 5698 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 180 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9561 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 316:
#line 5709 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 180 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9574 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 317:
#line 5720 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 180 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9587 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 318:
#line 5731 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9600 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 319:
#line 5742 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9613 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 320:
#line 5753 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9626 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 321:
#line 5764 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9639 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 322:
#line 5775 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9652 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 323:
#line 5786 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9665 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 324:
#line 5797 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9678 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 325:
#line 5808 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9691 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 326:
#line 5819 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9704 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 327:
#line 5830 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9717 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 328:
#line 5841 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9730 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 329:
#line 5852 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 78 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9743 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 330:
#line 5863 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 140 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9756 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 331:
#line 5874 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 20 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9775 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 332:
#line 5891 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 51 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9794 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 333:
#line 5908 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 51 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9807 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 334:
#line 5919 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 130 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9826 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 335:
#line 5936 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9845 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 336:
#line 5953 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9858 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 337:
#line 5964 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9871 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 338:
#line 5975 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 9884 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 339:
#line 5986 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9903 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 340:
#line 6003 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9928 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 341:
#line 6026 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9953 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 342:
#line 6049 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 9984 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 343:
#line 6078 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10009 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 344:
#line 6101 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10040 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 345:
#line 6130 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10077 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 346:
#line 6165 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10120 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 347:
#line 6206 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 0 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10157 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 348:
#line 6241 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10170 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 349:
#line 6252 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10183 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 350:
#line 6263 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10196 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 351:
#line 6274 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10209 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 352:
#line 6285 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10222 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 353:
#line 6296 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10235 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 354:
#line 6307 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 18 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10248 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 355:
#line 6318 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 107 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10285 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 356:
#line 6353 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 107 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10298 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 357:
#line 6364 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 107 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10317 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 358:
#line 6381 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 107 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10342 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 359:
#line 6404 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 99 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10391 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 360:
#line 6451 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 89 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10440 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 361:
#line 6498 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 54 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10459 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 362:
#line 6515 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 42 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10490 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 363:
#line 6544 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 42 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10503 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 364:
#line 6555 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 42 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10522 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 365:
#line 6572 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 42 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10553 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 366:
#line 6601 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 185 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10572 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 367:
#line 6618 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 185 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10597 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 368:
#line 6641 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 185 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10622 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 369:
#line 6664 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 185 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10653 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 370:
#line 6693 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 10 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10666 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 371:
#line 6704 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 10 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10685 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 372:
#line 6721 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 174 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10704 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 373:
#line 6738 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 64 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10717 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 374:
#line 6749 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 64 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10736 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 375:
#line 6766 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 132 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10761 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 376:
#line 6789 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 132 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10780 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 377:
#line 6806 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 132 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10793 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 378:
#line 6817 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 132 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10812 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 379:
#line 6834 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 132 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10825 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 380:
#line 6845 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 183 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10856 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 381:
#line 6874 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 17 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10875 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 382:
#line 6891 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 17 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10888 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 383:
#line 6902 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 17 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10907 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 384:
#line 6919 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 17 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 10932 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 385:
#line 6942 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 159 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10951 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 386:
#line 6959 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 95 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 10964 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 387:
#line 6970 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 164 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11013 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 388:
#line 7017 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 22 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11062 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 389:
#line 7064 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 22 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11105 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 390:
#line 7105 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 22 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11154 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 391:
#line 7152 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 22 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11173 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 392:
#line 7169 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 22 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11204 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 393:
#line 7198 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 22 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11229 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 394:
#line 7221 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 14 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11278 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 395:
#line 7268 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 14 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11321 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 396:
#line 7309 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 14 );

        (yyval.t)->addChild((yyvsp[-6].t));

        (yyvsp[-6].t)->parent= (yyval.t);

        (yyvsp[-6].t)->nextSibbling= (yyvsp[-5].t);

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11370 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 397:
#line 7356 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 139 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11389 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 398:
#line 7373 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 139 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11402 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 399:
#line 7384 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 139 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11421 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 400:
#line 7401 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 110 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11440 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 401:
#line 7418 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 105 );

    }
#line 11449 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 402:
#line 7425 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 105 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11462 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 403:
#line 7436 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 105 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11475 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 404:
#line 7447 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 105 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11488 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 405:
#line 7458 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 79 );

    }
#line 11497 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 406:
#line 7465 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 79 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11510 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 407:
#line 7476 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 81 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11523 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 408:
#line 7487 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 81 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11548 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 409:
#line 7510 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 81 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11567 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 410:
#line 7527 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 48 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11586 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 411:
#line 7544 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 48 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11611 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 412:
#line 7567 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 48 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11624 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 413:
#line 7578 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 48 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11643 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 414:
#line 7595 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 67 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11662 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 415:
#line 7612 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 67 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11687 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 416:
#line 7635 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 67 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11700 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 417:
#line 7646 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 67 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11719 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 418:
#line 7663 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 162 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11738 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 419:
#line 7680 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 162 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11763 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 420:
#line 7703 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 162 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11776 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 421:
#line 7714 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 162 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11795 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 422:
#line 7731 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 6 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11820 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 423:
#line 7754 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 6 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11833 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 424:
#line 7765 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 6 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11852 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 425:
#line 7782 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 11 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11889 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 426:
#line 7817 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 11 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11914 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 427:
#line 7840 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 11 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11927 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 428:
#line 7851 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 11 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 11946 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 429:
#line 7868 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 106 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 11983 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 430:
#line 7903 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 106 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12014 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 431:
#line 7932 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 106 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12027 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 432:
#line 7943 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 106 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12052 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 433:
#line 7966 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 106 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12071 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 434:
#line 7983 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 150 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12084 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 435:
#line 7994 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 155 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12109 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 436:
#line 8017 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 155 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12134 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 437:
#line 8040 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 155 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12165 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 438:
#line 8069 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 155 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12178 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 439:
#line 8080 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 15 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12191 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 440:
#line 8091 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 15 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12210 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 441:
#line 8108 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 15 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12223 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 442:
#line 8119 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 2 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12242 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 443:
#line 8136 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 2 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12267 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 444:
#line 8159 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 2 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12280 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 445:
#line 8170 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 19 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12293 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 446:
#line 8181 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 19 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12318 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 447:
#line 8204 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 33 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12337 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 448:
#line 8221 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 32 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12350 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 449:
#line 8232 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 32 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12369 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 450:
#line 8249 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 76 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12388 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 451:
#line 8266 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 190 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12419 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 452:
#line 8295 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 190 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12432 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 453:
#line 8306 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 190 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12451 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 454:
#line 8323 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 190 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12476 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 455:
#line 8346 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 114 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12495 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 456:
#line 8363 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 114 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12508 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 457:
#line 8374 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 104 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12521 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 458:
#line 8385 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 104 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12534 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 459:
#line 8396 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12547 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 460:
#line 8407 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12560 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 461:
#line 8418 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12585 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 462:
#line 8441 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12598 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 463:
#line 8452 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12611 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 464:
#line 8463 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12624 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 465:
#line 8474 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12637 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 466:
#line 8485 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12650 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 467:
#line 8496 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12675 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 468:
#line 8519 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12694 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 469:
#line 8536 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12713 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 470:
#line 8553 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12732 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 471:
#line 8570 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 116 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 12751 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 472:
#line 8587 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 173 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12776 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 473:
#line 8610 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 173 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12801 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 474:
#line 8633 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 173 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12826 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 475:
#line 8656 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 173 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12851 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 476:
#line 8679 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12888 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 477:
#line 8714 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12919 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 478:
#line 8743 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12932 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 479:
#line 8754 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 12963 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 480:
#line 8783 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13000 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 481:
#line 8818 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13037 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 482:
#line 8853 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13080 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 483:
#line 8894 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13099 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 484:
#line 8911 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13118 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 485:
#line 8928 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13143 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 486:
#line 8951 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13174 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 487:
#line 8980 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13187 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 488:
#line 8991 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 30 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13206 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 489:
#line 9008 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 59 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13249 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 490:
#line 9049 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 59 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13286 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 491:
#line 9084 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 35 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13311 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 492:
#line 9107 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 35 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13336 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 493:
#line 9130 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 68 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13349 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 494:
#line 9141 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 68 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13374 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 495:
#line 9164 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 68 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13393 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 496:
#line 9181 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13418 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 497:
#line 9204 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13443 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 498:
#line 9227 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13474 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 499:
#line 9256 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13505 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 500:
#line 9285 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13536 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 501:
#line 9314 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13567 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 502:
#line 9343 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13586 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 503:
#line 9360 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 108 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13605 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 504:
#line 9377 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 52 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13618 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 505:
#line 9388 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 52 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13637 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 506:
#line 9405 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 158 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13662 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 507:
#line 9428 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 158 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13681 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 508:
#line 9445 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 158 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13694 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 509:
#line 9456 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 87 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13713 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 510:
#line 9473 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 87 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13738 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 511:
#line 9496 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 87 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13757 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 512:
#line 9513 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 73 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13782 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 513:
#line 9536 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 73 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13807 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 514:
#line 9559 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 73 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 13820 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 515:
#line 9570 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13845 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 516:
#line 9593 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13876 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 517:
#line 9622 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13913 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 518:
#line 9657 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13956 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 519:
#line 9698 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 13993 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 520:
#line 9733 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-5].t));

        (yyvsp[-5].t)->parent= (yyval.t);

        (yyvsp[-5].t)->nextSibbling= (yyvsp[-4].t);

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14036 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 521:
#line 9774 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14061 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 522:
#line 9797 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 122 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14086 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 523:
#line 9820 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 60 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14117 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 524:
#line 9849 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 60 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14148 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 525:
#line 9878 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 60 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14167 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 526:
#line 9895 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 60 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14192 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 527:
#line 9918 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 60 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14211 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 528:
#line 9935 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 60 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14236 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 529:
#line 9958 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 161 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14249 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 530:
#line 9969 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 161 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14262 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 531:
#line 9980 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 161 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14275 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 532:
#line 9991 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 161 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14288 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 533:
#line 10002 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 3 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14307 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 534:
#line 10019 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 9 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14326 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 535:
#line 10036 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 29 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14339 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 536:
#line 10047 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 29 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14352 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 537:
#line 10058 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 29 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14371 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 538:
#line 10075 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 29 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14384 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 539:
#line 10086 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 29 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14397 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 540:
#line 10097 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 44 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14410 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 541:
#line 10108 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 44 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14429 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 542:
#line 10125 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 44 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14442 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 543:
#line 10136 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 92 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14461 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 544:
#line 10153 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 92 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14474 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 545:
#line 10164 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 38 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14493 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 546:
#line 10181 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 38 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14506 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 547:
#line 10192 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 49 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14519 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 548:
#line 10203 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 49 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14538 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 549:
#line 10220 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 49 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14557 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 550:
#line 10237 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 49 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14570 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 551:
#line 10248 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 49 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14583 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 552:
#line 10259 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 49 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14596 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 553:
#line 10270 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14633 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 554:
#line 10305 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14664 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 555:
#line 10334 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14695 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 556:
#line 10363 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14732 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 557:
#line 10398 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14757 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 558:
#line 10421 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14770 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 559:
#line 10432 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14801 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 560:
#line 10461 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14826 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 561:
#line 10484 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 160 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14857 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 562:
#line 10513 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14870 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 563:
#line 10524 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14895 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 564:
#line 10547 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14920 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 565:
#line 10570 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 14945 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 566:
#line 10593 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14964 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 567:
#line 10610 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 14983 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 568:
#line 10627 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 72 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15002 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 569:
#line 10644 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 63 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15015 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 570:
#line 10655 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 63 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15040 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 571:
#line 10678 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 63 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15065 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 572:
#line 10701 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 63 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15084 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 573:
#line 10718 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 63 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15103 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 574:
#line 10735 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15116 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 575:
#line 10746 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15141 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 576:
#line 10769 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15166 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 577:
#line 10792 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15191 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 578:
#line 10815 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15210 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 579:
#line 10832 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15229 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 580:
#line 10849 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 142 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15248 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 581:
#line 10866 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15261 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 582:
#line 10877 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15286 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 583:
#line 10900 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15311 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 584:
#line 10923 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15336 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 585:
#line 10946 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15361 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 586:
#line 10969 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15386 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 587:
#line 10992 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15405 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 588:
#line 11009 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15424 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 589:
#line 11026 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15443 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 590:
#line 11043 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15462 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 591:
#line 11060 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 126 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15481 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 592:
#line 11077 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 133 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15494 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 593:
#line 11088 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 133 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15519 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 594:
#line 11111 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 133 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15544 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 595:
#line 11134 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 133 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15563 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 596:
#line 11151 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 133 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15582 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 597:
#line 11168 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 100 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15595 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 598:
#line 11179 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 100 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15620 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 599:
#line 11202 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 100 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15639 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 600:
#line 11219 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 101 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15652 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 601:
#line 11230 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 101 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15677 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 602:
#line 11253 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 101 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15696 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 603:
#line 11270 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 13 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15709 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 604:
#line 11281 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 13 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15734 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 605:
#line 11304 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 13 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15753 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 606:
#line 11321 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 91 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15766 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 607:
#line 11332 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 91 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15791 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 608:
#line 11355 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 91 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15810 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 609:
#line 11372 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 71 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15823 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 610:
#line 11383 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 71 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15848 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 611:
#line 11406 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 71 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15867 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 612:
#line 11423 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 186 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15880 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 613:
#line 11434 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 186 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 15917 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 614:
#line 11469 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 186 );

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15942 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 615:
#line 11492 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 186 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15961 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 616:
#line 11509 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 186 );

        (yyval.t)->addChild((yyvsp[-4].t));

        (yyvsp[-4].t)->parent= (yyval.t);

        (yyvsp[-4].t)->nextSibbling= (yyvsp[-3].t);

        (yyval.t)->addChild((yyvsp[-3].t));

        (yyvsp[-3].t)->parent= (yyval.t);

        (yyvsp[-3].t)->nextSibbling= (yyvsp[-2].t);

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 15992 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 617:
#line 11538 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 55 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16005 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 618:
#line 11549 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 55 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16018 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 619:
#line 11560 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 69 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

        (yyvsp[-1].t)->nextSibbling= (yyvsp[0].t);

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16043 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 620:
#line 11583 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 69 );

        (yyval.t)->addChild((yyvsp[-2].t));

        (yyvsp[-2].t)->parent= (yyval.t);

        (yyvsp[-2].t)->nextSibbling= (yyvsp[-1].t);

        (yyval.t)->addChild((yyvsp[-1].t));

        (yyvsp[-1].t)->parent= (yyval.t);

    }
#line 16062 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 621:
#line 11600 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 47 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16075 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 622:
#line 11611 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 47 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16088 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 623:
#line 11622 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 47 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16101 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 624:
#line 11633 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 94 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16114 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 625:
#line 11644 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 94 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16127 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 626:
#line 11655 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16140 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 627:
#line 11666 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16153 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 628:
#line 11677 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16166 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 629:
#line 11688 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16179 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 630:
#line 11699 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16192 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 631:
#line 11710 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16205 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 632:
#line 11721 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16218 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 633:
#line 11732 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16231 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 634:
#line 11743 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16244 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 635:
#line 11754 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16257 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 636:
#line 11765 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 188 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16270 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 637:
#line 11776 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 96 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16283 "pt_j.tab.cc" /* yacc.c:1646  */
    break;

  case 638:
#line 11787 "pt_j.y" /* yacc.c:1646  */
    {
        (yyval.t)= new NonTerminal( 144 );

        (yyval.t)->addChild((yyvsp[0].t));

        (yyvsp[0].t)->parent= (yyval.t);

    }
#line 16296 "pt_j.tab.cc" /* yacc.c:1646  */
    break;


#line 16300 "pt_j.tab.cc" /* yacc.c:1646  */
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
#line 11799 "pt_j.y" /* yacc.c:1906  */



#include <stdio.h>

extern char yytext[];
extern int column;
extern int line;

void yyerror( char *s)
{
fflush(stdout);
fprintf(stderr,"%s: %d.%d\n",s,line,column);
}


