/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUMBER_VARIABLES 256
#define true 1
#define false 0

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
int MAX_SIZE_ARR = 256;

typedef struct{ 
	char name[50];
	float value;  
} varStruct ;

varStruct variables[MAX_NUMBER_VARIABLES];
int variablesNumber = 0;

float logFunc(float value) { 
	return log(value);
}

float tanhFunc(float value) { 
	return tanh(value);
}
  
float coshFunc(float value) { 
	return cosh(value);
}
  
float sinhFunc(float value) { 
	return sinh(value);
}
  
float tanFunc(float value) { 
	return tan(value);
}
  
float cosFunc(float value) { 
	return cos(value);
}

float sinFunc(float value) { 
	return sin(value);
}

float sqrtFunc(float value) {
	return sqrt(value);
}

typedef struct{ 
	char name[50];
	float (*function_ptr)(float);  
} FunctionMap ;

FunctionMap functions[] = {
	{"sqrt", sqrtFunc},
	{"sin", sinFunc},
	{"sinh", sinhFunc},
	{"cos", cosFunc},
	{"cos", coshFunc},
	{"tan", tanFunc},
	{"tanh", tanhFunc},
	{"log", logFunc},
};

void addVariables(char *varName, float value) {
	bool variableFound = false;
	int lenArr = (int) sizeof(variables)/sizeof(varStruct);
	int i;
	for(i = 0; i< lenArr ; i++) {
		if ( i >= variablesNumber) {
			break;
		}
		if(strcmp(variables[i].name, varName) == 0 ) {
			variableFound = true;
			break;
		}
	}
	if (variableFound == false) {
		variablesNumber++;
	}
	snprintf(variables[i].name, sizeof(variables[i].name), "%s", varName);
	variables[i].value = value;
}

float findValue(char *varName){ 
	bool variableFound = false;
	int lenArr = (int) sizeof(variables)/sizeof(varStruct);
	int i;
	for(i = 0; i< lenArr ; i++) {
		if ( i >= variablesNumber) {
			break;
		}
		if(strcmp(variables[i].name, varName) == 0 ) {
			variableFound = true;
			break;
		}
	}
	if (variableFound == true) {
		return variables[i].value;
	}
	return 0;
}

float executeFunction(char * functionName, float value) { 
	int lenArr = (int) sizeof(functions)/sizeof(FunctionMap);
	int i;
	float result = 0.0;

	for (i = 0; i < lenArr; ++i) {
		if(strcmp(functions[i].name, functionName) == 0 ) {
			result = (float) (functions[i].function_ptr)(value);
		}
	}

	return result;
}

#line 198 "calc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT = 3,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 4,                    /* T_FLOAT  */
  YYSYMBOL_T_NAME = 5,                     /* T_NAME  */
  YYSYMBOL_T_PLUS = 6,                     /* T_PLUS  */
  YYSYMBOL_T_MINUS = 7,                    /* T_MINUS  */
  YYSYMBOL_T_MULTIPLY = 8,                 /* T_MULTIPLY  */
  YYSYMBOL_T_DIVIDE = 9,                   /* T_DIVIDE  */
  YYSYMBOL_T_LEFT = 10,                    /* T_LEFT  */
  YYSYMBOL_T_RIGHT = 11,                   /* T_RIGHT  */
  YYSYMBOL_T_EQUALS = 12,                  /* T_EQUALS  */
  YYSYMBOL_T_NEWLINE = 13,                 /* T_NEWLINE  */
  YYSYMBOL_T_QUIT = 14,                    /* T_QUIT  */
  YYSYMBOL_YYACCEPT = 15,                  /* $accept  */
  YYSYMBOL_calculation = 16,               /* calculation  */
  YYSYMBOL_line = 17,                      /* line  */
  YYSYMBOL_mixed_expression = 18,          /* mixed_expression  */
  YYSYMBOL_variable_name = 19,             /* variable_name  */
  YYSYMBOL_expression = 20                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  15
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   269


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   154,   157,   158,   159,   160,   161,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   181,   185,   188,   192,   196,   200,
     204,   208,   213,   217,   221,   225,   229,   234,   238,   242,
     246,   250,   255,   259,   263,   267,   271,   276,   285,   292,
     301,   302,   303,   304,   305
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_INT", "T_FLOAT",
  "T_NAME", "T_PLUS", "T_MINUS", "T_MULTIPLY", "T_DIVIDE", "T_LEFT",
  "T_RIGHT", "T_EQUALS", "T_NEWLINE", "T_QUIT", "$accept", "calculation",
  "line", "mixed_expression", "variable_name", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-8)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    78,    -8,    -8,    -8,    -8,    69,    -8,    -7,    -8,
      87,    -5,    95,   114,   120,    -8,   102,   102,   102,   102,
      -8,   102,   102,   102,   102,   102,    69,    -8,   102,   102,
     102,   102,    -8,    69,    69,    69,    69,    -8,    69,    69,
      69,    69,    -8,    89,    77,   144,    89,    77,   144,    -8,
      99,    -8,    -8,    99,    -8,    89,    77,   144,    89,    77,
     144,    -8,    99,    -8,    -8,    99,    -8,   126,   107,   132,
     138,   142,    89,    77,   144,    89,    77,   144,    -8,    99,
      -8,    -8,    99,    -8,   146,   148,   146,   148,    -8,    -8,
      -8,    -8,   146,   148,   146,   148,    -8,    -8,    -8,    -8,
      -8,    -8,    -8
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    50,     9,    24,     0,     4,     0,     3,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     6,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    54,    10,    31,    19,    11,    36,    20,    12,
      41,    21,    13,    46,    22,    29,    27,    28,    34,    32,
      33,    39,    37,    38,    44,    42,    43,     0,     0,     0,
      26,    25,    15,    30,    51,    16,    35,    52,    17,    40,
      53,    18,    45,    23,    10,    19,    11,    20,    12,    21,
      13,    22,    15,    51,    16,    52,    17,    53,    18,    23,
      47,    49,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -8,    -8,    -8,    -6,    46,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     9,    10,    11,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      13,    21,    22,    23,    24,    25,    15,    26,    27,     0,
      43,    46,    49,    52,     0,    55,    58,    61,    64,    67,
      70,     0,    72,    75,    78,    81,    14,    84,    86,    88,
      90,     0,    92,    94,    96,    98,    45,    48,    51,    54,
       0,    57,    60,    63,    66,    69,    71,     0,    74,    77,
      80,    83,     0,    85,    87,    89,    91,     0,    93,    95,
      97,    99,    44,    47,    50,    53,     0,    56,    59,    62,
      65,    68,     3,     4,    73,    76,    79,    82,     2,     6,
       0,     3,     4,     5,     0,    23,    24,    25,     6,    26,
       0,     7,     8,    16,    17,    18,    19,    18,    19,     0,
      20,    28,    29,    30,    31,     3,     4,     5,    32,    25,
       0,    26,     6,    21,    22,    23,    24,    25,   101,    26,
      33,    34,    35,    36,     0,    37,    38,    39,    40,    41,
       0,    42,    16,    17,    18,    19,     0,   100,    28,    29,
      30,    31,     0,   102,    33,    34,    35,    36,    38,    39,
      40,    41,    30,    31,    35,    36,    40,    41
};

static const yytype_int8 yycheck[] =
{
       6,     6,     7,     8,     9,    10,    13,    12,    13,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,     6,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,     3,     4,    28,    29,    30,    31,     0,    10,
      -1,     3,     4,     5,    -1,     8,     9,    10,    10,    12,
      -1,    13,    14,     6,     7,     8,     9,     8,     9,    -1,
      13,     6,     7,     8,     9,     3,     4,     5,    13,    10,
      -1,    12,    10,     6,     7,     8,     9,    10,    11,    12,
       6,     7,     8,     9,    -1,    11,     6,     7,     8,     9,
      -1,    11,     6,     7,     8,     9,    -1,    11,     6,     7,
       8,     9,    -1,    11,     6,     7,     8,     9,     6,     7,
       8,     9,     8,     9,     8,     9,     8,     9
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,     0,     3,     4,     5,    10,    13,    14,    17,
      18,    19,    20,    18,    20,    13,     6,     7,     8,     9,
      13,     6,     7,     8,     9,    10,    12,    13,     6,     7,
       8,     9,    13,     6,     7,     8,     9,    11,     6,     7,
       8,     9,    11,    18,    19,    20,    18,    19,    20,    18,
      19,    20,    18,    19,    20,    18,    19,    20,    18,    19,
      20,    18,    19,    20,    18,    19,    20,    18,    19,    20,
      18,    20,    18,    19,    20,    18,    19,    20,    18,    19,
      20,    18,    19,    20,    18,    20,    18,    20,    18,    20,
      18,    20,    18,    20,    18,    20,    18,    20,    18,    20,
      11,    11,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    15,    16,    16,    17,    17,    17,    17,    17,    18,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      20,    20,    20,    20,    20
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       1,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 5: /* line: mixed_expression T_NEWLINE  */
#line 158 "calc.y"
                                 { printf("\tResult: %f\n", (yyvsp[-1].fval));}
#line 1269 "calc.tab.c"
    break;

  case 6: /* line: expression T_NEWLINE  */
#line 159 "calc.y"
                           { printf("\tResult: %i\n", (yyvsp[-1].ival)); }
#line 1275 "calc.tab.c"
    break;

  case 7: /* line: variable_name T_NEWLINE  */
#line 160 "calc.y"
                                  { printf("\tResult: %f\n", (yyvsp[-1].variable).value); }
#line 1281 "calc.tab.c"
    break;

  case 8: /* line: T_QUIT T_NEWLINE  */
#line 161 "calc.y"
                       { printf("bye!\n"); exit(0); }
#line 1287 "calc.tab.c"
    break;

  case 9: /* mixed_expression: T_FLOAT  */
#line 164 "calc.y"
                                                         { (yyval.fval) = (yyvsp[0].fval); }
#line 1293 "calc.tab.c"
    break;

  case 10: /* mixed_expression: mixed_expression T_PLUS mixed_expression  */
#line 165 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) + (yyvsp[0].fval); }
#line 1299 "calc.tab.c"
    break;

  case 11: /* mixed_expression: mixed_expression T_MINUS mixed_expression  */
#line 166 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) - (yyvsp[0].fval); }
#line 1305 "calc.tab.c"
    break;

  case 12: /* mixed_expression: mixed_expression T_MULTIPLY mixed_expression  */
#line 167 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) * (yyvsp[0].fval); }
#line 1311 "calc.tab.c"
    break;

  case 13: /* mixed_expression: mixed_expression T_DIVIDE mixed_expression  */
#line 168 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) / (yyvsp[0].fval); }
#line 1317 "calc.tab.c"
    break;

  case 14: /* mixed_expression: T_LEFT mixed_expression T_RIGHT  */
#line 169 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-1].fval); }
#line 1323 "calc.tab.c"
    break;

  case 15: /* mixed_expression: expression T_PLUS mixed_expression  */
#line 170 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].ival) + (yyvsp[0].fval); }
#line 1329 "calc.tab.c"
    break;

  case 16: /* mixed_expression: expression T_MINUS mixed_expression  */
#line 171 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].ival) - (yyvsp[0].fval); }
#line 1335 "calc.tab.c"
    break;

  case 17: /* mixed_expression: expression T_MULTIPLY mixed_expression  */
#line 172 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].ival) * (yyvsp[0].fval); }
#line 1341 "calc.tab.c"
    break;

  case 18: /* mixed_expression: expression T_DIVIDE mixed_expression  */
#line 173 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].ival) / (yyvsp[0].fval); }
#line 1347 "calc.tab.c"
    break;

  case 19: /* mixed_expression: mixed_expression T_PLUS expression  */
#line 174 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) + (yyvsp[0].ival); }
#line 1353 "calc.tab.c"
    break;

  case 20: /* mixed_expression: mixed_expression T_MINUS expression  */
#line 175 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) - (yyvsp[0].ival); }
#line 1359 "calc.tab.c"
    break;

  case 21: /* mixed_expression: mixed_expression T_MULTIPLY expression  */
#line 176 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) * (yyvsp[0].ival); }
#line 1365 "calc.tab.c"
    break;

  case 22: /* mixed_expression: mixed_expression T_DIVIDE expression  */
#line 177 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].fval) / (yyvsp[0].ival); }
#line 1371 "calc.tab.c"
    break;

  case 23: /* mixed_expression: expression T_DIVIDE expression  */
#line 178 "calc.y"
                                                         { (yyval.fval) = (yyvsp[-2].ival) / (float)(yyvsp[0].ival); }
#line 1377 "calc.tab.c"
    break;

  case 24: /* variable_name: T_NAME  */
#line 181 "calc.y"
                        {
		(yyvsp[0].variable).value = findValue((yyvsp[0].variable).name);
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1386 "calc.tab.c"
    break;

  case 25: /* variable_name: variable_name T_EQUALS expression  */
#line 185 "calc.y"
                                                { 
		addVariables((yyvsp[-2].variable).name, (yyvsp[0].ival)); 
	}
#line 1394 "calc.tab.c"
    break;

  case 26: /* variable_name: variable_name T_EQUALS mixed_expression  */
#line 188 "calc.y"
                                                        { 
		addVariables((yyvsp[-2].variable).name, (yyvsp[0].fval)); 
	}
#line 1402 "calc.tab.c"
    break;

  case 27: /* variable_name: variable_name T_PLUS variable_name  */
#line 192 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value + (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1411 "calc.tab.c"
    break;

  case 28: /* variable_name: variable_name T_PLUS expression  */
#line 196 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value + (yyvsp[0].ival);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1420 "calc.tab.c"
    break;

  case 29: /* variable_name: variable_name T_PLUS mixed_expression  */
#line 200 "calc.y"
                                                        { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value + (yyvsp[0].fval);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1429 "calc.tab.c"
    break;

  case 30: /* variable_name: expression T_PLUS variable_name  */
#line 204 "calc.y"
                                          { 
		(yyvsp[0].variable).value = (yyvsp[-2].ival) + (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1438 "calc.tab.c"
    break;

  case 31: /* variable_name: mixed_expression T_PLUS variable_name  */
#line 208 "calc.y"
                                                { 
		(yyvsp[0].variable).value = (yyvsp[-2].fval) + (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1447 "calc.tab.c"
    break;

  case 32: /* variable_name: variable_name T_MINUS variable_name  */
#line 213 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value - (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1456 "calc.tab.c"
    break;

  case 33: /* variable_name: variable_name T_MINUS expression  */
#line 217 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value - (yyvsp[0].ival);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1465 "calc.tab.c"
    break;

  case 34: /* variable_name: variable_name T_MINUS mixed_expression  */
#line 221 "calc.y"
                                                        { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value - (yyvsp[0].fval);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1474 "calc.tab.c"
    break;

  case 35: /* variable_name: expression T_MINUS variable_name  */
#line 225 "calc.y"
                                           { 
		(yyvsp[0].variable).value = (yyvsp[-2].ival) - (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1483 "calc.tab.c"
    break;

  case 36: /* variable_name: mixed_expression T_MINUS variable_name  */
#line 229 "calc.y"
                                                 { 
		(yyvsp[0].variable).value = (yyvsp[-2].fval) - (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1492 "calc.tab.c"
    break;

  case 37: /* variable_name: variable_name T_MULTIPLY variable_name  */
#line 234 "calc.y"
                                                        { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value * (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1501 "calc.tab.c"
    break;

  case 38: /* variable_name: variable_name T_MULTIPLY expression  */
#line 238 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value * (yyvsp[0].ival);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1510 "calc.tab.c"
    break;

  case 39: /* variable_name: variable_name T_MULTIPLY mixed_expression  */
#line 242 "calc.y"
                                                        { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value * (yyvsp[0].fval);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1519 "calc.tab.c"
    break;

  case 40: /* variable_name: expression T_MULTIPLY variable_name  */
#line 246 "calc.y"
                                              { 
		(yyvsp[0].variable).value = (yyvsp[-2].ival) * (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1528 "calc.tab.c"
    break;

  case 41: /* variable_name: mixed_expression T_MULTIPLY variable_name  */
#line 250 "calc.y"
                                                    { 
		(yyvsp[0].variable).value = (yyvsp[-2].fval) * (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1537 "calc.tab.c"
    break;

  case 42: /* variable_name: variable_name T_DIVIDE variable_name  */
#line 255 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value / (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1546 "calc.tab.c"
    break;

  case 43: /* variable_name: variable_name T_DIVIDE expression  */
#line 259 "calc.y"
                                                { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value / (yyvsp[0].ival);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1555 "calc.tab.c"
    break;

  case 44: /* variable_name: variable_name T_DIVIDE mixed_expression  */
#line 263 "calc.y"
                                                        { 
		(yyvsp[-2].variable).value = (yyvsp[-2].variable).value / (yyvsp[0].fval);
		(yyval.variable) = (yyvsp[-2].variable);
	}
#line 1564 "calc.tab.c"
    break;

  case 45: /* variable_name: expression T_DIVIDE variable_name  */
#line 267 "calc.y"
                                            { 
		(yyvsp[0].variable).value = (yyvsp[-2].ival) / (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1573 "calc.tab.c"
    break;

  case 46: /* variable_name: mixed_expression T_DIVIDE variable_name  */
#line 271 "calc.y"
                                                  { 
		(yyvsp[0].variable).value = (yyvsp[-2].fval) / (yyvsp[0].variable).value;
		(yyval.variable) = (yyvsp[0].variable);
	}
#line 1582 "calc.tab.c"
    break;

  case 47: /* variable_name: variable_name T_LEFT mixed_expression T_RIGHT  */
#line 276 "calc.y"
                                                        {
		char * functionName = (yyvsp[-3].variable).name;
		float value = (float) (yyvsp[-1].fval);
		float result = executeFunction(functionName, value);
		char array[10];
		snprintf(array, sizeof(array), "%f", result);
		(yyvsp[-3].variable).value = result;
		(yyval.variable) = (yyvsp[-3].variable);
	}
#line 1596 "calc.tab.c"
    break;

  case 48: /* variable_name: variable_name T_LEFT expression T_RIGHT  */
#line 285 "calc.y"
                                                  {
		char * functionName = (yyvsp[-3].variable).name;
		float value = (float) (yyvsp[-1].ival);
		float result = executeFunction(functionName, value);
		(yyvsp[-3].variable).value = result;
		(yyval.variable) = (yyvsp[-3].variable);
	}
#line 1608 "calc.tab.c"
    break;

  case 49: /* variable_name: variable_name T_LEFT variable_name T_RIGHT  */
#line 292 "calc.y"
                                                     {
		char * functionName = (yyvsp[-3].variable).name;
		float value = (float) (yyvsp[-1].variable).value;
		float result = executeFunction(functionName, value);
		(yyvsp[-3].variable).value = result;
		(yyval.variable) = (yyvsp[-3].variable);
	}
#line 1620 "calc.tab.c"
    break;

  case 50: /* expression: T_INT  */
#line 301 "calc.y"
                                                { (yyval.ival) = (yyvsp[0].ival); }
#line 1626 "calc.tab.c"
    break;

  case 51: /* expression: expression T_PLUS expression  */
#line 302 "calc.y"
                                                { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1632 "calc.tab.c"
    break;

  case 52: /* expression: expression T_MINUS expression  */
#line 303 "calc.y"
                                                { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1638 "calc.tab.c"
    break;

  case 53: /* expression: expression T_MULTIPLY expression  */
#line 304 "calc.y"
                                                { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1644 "calc.tab.c"
    break;

  case 54: /* expression: T_LEFT expression T_RIGHT  */
#line 305 "calc.y"
                                                { (yyval.ival) = (yyvsp[-1].ival); }
#line 1650 "calc.tab.c"
    break;


#line 1654 "calc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 308 "calc.y"


int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
