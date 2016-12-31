%{
#include "compiler_translator.h"
#include "y.tab.h"
#include <math.h>

%}

/* Regular Expression Definitions */

											/*all keywords first*/
AUTO			"auto"
BREAK			"break"
CASE			"case"
CHAR			"char"
CONST			"const"
CONTINUE		"continue"
DEFAULT			"default"
DO			    "do"
DOUBLE			"double"
ELSE			"else"
ENUM			"enum"
EXTERN			"extern"
FLOAT			"float"
FOR 			"for"
GOTO			"goto"
IF				"if"
INLINE			"inline"
INT				"int"
LONG			"long"
REGISTER		"register"
RESTRICT		"restrict"
RETURN			"return"
SHORT			"short"
SIGNED			"signed"
SIZEOF			"sizeof"
STATIC			"static"
STRUCT			"struct"
SWITCH			"switch"
TYPEDEF			"typedef"
UNION			"union"
UNSIGNED		"unsigned"
VOID			"void"
VOLATILE		"volatile"
WHILE			"while"
_BOOL			"_Bool"
_COMPLEX		"_Complex"
_IMAGINARY		"_Imaginary"
KEYWORD 		{K1}|{K2}|{K3}|{K4}
K1  			AUTO|BREAK|CASE|CHAR|CONST|CONTINUE|DEFAULT|DO|DOUBLE|ELSE
K2				ENUM|EXTERN|FLOAT|FOR|GOTO|IF|INLINE|INT|LONG|REGISTER
K3				RESTRICT|RETURN|SHORT|SIGNED|SIZEOF|STATIC|STRUCT|SWITCH|TYPEDEF|UNION
K4				UNSIGNED|VOID|VOLATILE|WHILE|_BOOL|_COMPLEX|_IMAGINARY
											/*now the identifiers*/
IDENTIFIER_NONDIGIT 	[a-zA-Z]|"_"						
DIGIT [0-9]
IDENTIFIER ([a-zA-Z_]([a-zA-Z_]|[0-9])*)
											/*constants*/
NONZERO_DIGIT 			[1-9]
INTEGER_CONSTANT (({NONZERO_DIGIT}({DIGIT}*))|[0]+)

DECIMALPT "."
DIGIT_SEQUENCE {DIGIT}+
FRACTIONAL_CONSTANT {DIGIT_SEQUENCE}?{DECIMALPT}{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}{DECIMALPT}
SIGN [+-]
EXPONENT_PART ([eE]{SIGN}?{DIGIT_SEQUENCE})
FLOATING_CONSTANT ({FRACTIONAL_CONSTANT}{EXPONENT_PART}?|{DIGIT_SEQUENCE}{EXPONENT_PART})
ENUMERATION_CONSTANT	{IDENTIFIER}
									/*	emuration constant defined as identifier*/
ESCAPE_SEQUENCE ([\\][\'\"\?\\abfnrtv])
CCHAR [^\'\\\n]|{ESCAPE_SEQUENCE}
CCHAR_SEQUENCE {CCHAR}+
CHARACTER_CONSTANT (\'{CCHAR_SEQUENCE}\')

SCHAR [^\"\\\n]|{ESCAPE_SEQUENCE}
SCHAR_SEQUENCE {SCHAR}+
STRING_LITERAL (\"{SCHAR_SEQUENCE}*\")
													/*String literal has "" , character_constant has ''*/
SINGLELINE_COMMENT [/][/].*
MULTI_COMMENT_START [/][\*]+
MULTI_COMMENT_END	[\*]+[/]
MULTILINE_COMMENT ({MULTI_COMMENT_START}(([^\*])|((\*)+[^/\*]))*{MULTI_COMMENT_END})
WS [ \t\n]

%%
				/* keywords had to be changed to avoid clashes*/
{AUTO}			{return AUTO_KEYWORD;}
{ENUM}			{return ENUM_KEYWORD;}
{RESTRICT}		{return RESTRICT_KEYWORD;}
{UNSIGNED}		{return UNSIGNED_KEYWORD;}
{BREAK}			{return BREAK_KEYWORD;}
{EXTERN}		{return EXTERN_KEYWORD;}
{RETURN}		{return RETURN_KEYWORD;}
{VOID}			{return VOID_KEYWORD;}
{CASE}			{return CASE_KEYWORD;}
{FLOAT}			{return FLOAT_KEYWORD;}
{SHORT}			{return SHORT_KEYWORD;}
{VOLATILE}		{return VOLATILE_KEYWORD;}
{CHAR}			{return CHAR_KEYWORD;}
{FOR}			{return FOR_KEYWORD;}
{SIGNED}		{return SIGNED_KEYWORD;}
{WHILE}			{return WHILE_KEYWORD;}
{CONST}			{return CONST_KEYWORD;}
{GOTO}			{return GOTO_KEYWORD;}
{SIZEOF}		{return SIZEOF_KEYWORD;}
{_BOOL}			{return BOOL_KEYWORD;}
{CONTINUE}		{return CONTINUE_KEYWORD;}
{IF}			{return IF_KEYWORD;}
{STATIC}		{return STATIC_KEYWORD;}
{_COMPLEX}		{return COMPLEX_KEYWORD;}
{DEFAULT}		{return DEFAULT_KEYWORD;}
{INLINE}		{return INLINE_KEYWORD;}
{STRUCT}		{return STRUCT_KEYWORD;}
{_IMAGINARY}		{return IMAGINARY_KEYWORD;}
{DO}			{return DO_KEYWORD;}
{INT}			{return INT_KEYWORD;}
{SWITCH}		{return SWITCH_KEYWORD;}
{DOUBLE}		{return DOUBLE_KEYWORD;}
{LONG}			{return LONG_KEYWORD;}
{TYPEDEF}		{return TYPEDEF_KEYWORD;}
{ELSE}			{return ELSE_KEYWORD;}
{REGISTER}		{return REGISTER_KEYWORD;}
{UNION}			{return UNION_KEYWORD;}

{SINGLELINE_COMMENT}			{;}
{MULTILINE_COMMENT}			{;}

{IDENTIFIER}                    { yylval.str = new string(yytext); return IDENTIFIER;}
{INTEGER_CONSTANT}             { yylval.intval = atoi(yytext); return INT_CONSTANT;}
{FLOATING_CONSTANT}           { yylval.floatval = atof(yytext); return FLOAT_CONSTANT;}
{CHARACTER_CONSTANT}          { yylval.charval = yytext[1]; return CHAR_CONSTANT;}
{STRING_LITERAL}        { yylval.str = new string(yytext); return STRING_LITERAL;}

{WS}        		{}							/*Ignore white spaces, so do nothing*/

												/*Directly declare actions for puntuators*/
"["				{return yytext[0];}
"]"				{return yytext[0];}
"("				{return yytext[0];}
")"				{return yytext[0];}
"{"				{return yytext[0];}
"}"				{return yytext[0];}
"."				{return yytext[0];}
"->"				{return POINTER;}

"++"				{return INCREMENT;}
"--"				{return DECREMENT;}
"&"				{return yytext[0];}
"*"				{return yytext[0];}
"+"				{return yytext[0];}
"-"				{return yytext[0];}
"~"				{return yytext[0];}
"!"				{return yytext[0];}

"/"				{return yytext[0];}
"%"				{return yytext[0];}
"<<"				{return LEFT_SHIFT;}
">>"				{return RIGHT_SHIFT;}
"<"				{return yytext[0];}
">"				{return yytext[0];}
"<="				{return LESS_EQUAL;}
">="				{return GREATER_EQUAL;}
"=="				{return IS_EQUAL;}
"!="				{return NOT_EQUAL;}
"^"				{return yytext[0];}
"|"				{return yytext[0];}
"&&"				{return LOGICAL_AND;}
"||"				{return LOGICAL_OR;}

"?"				{return yytext[0];}
":"				{return yytext[0];}
";"				{return yytext[0];}
"..."				{return ELLIPSIS;}

"="				{return yytext[0];}
"*="				{return MULTIPLY_BY;}
"/="				{return DIVIDE_BY;}
"%="				{return MOD_BY;}
"+="				{return ADD_BY;}
"-="				{return SUB_BY;}
"<<="				{return LEFT_SHIFT_EQUAL;}
">>="				{return RIGHT_SHIFT_EQUAL;}
"&="				{return AND_EQUAL;}
"^="				{return XOR_EQUAL;}
"|="				{return OR_EQUAL;}

","				{return yytext[0];}
"#"				{return yytext[0];}
%%

