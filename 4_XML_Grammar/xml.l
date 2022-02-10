%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "xml.tab.h"

%}

%%

[ \t]	; // ignore all whitespace
\n		{return T_NEWLINE;}
"<"[a-zA-Z]+">" { 
		yylval.name = strdup("");
		strncpy(yylval.name, yytext + 1, strlen(yytext)-2);
		return A; 
	}
"</"[a-zA-Z]+">" { 
		yylval.name = strdup("");
		strncpy(yylval.name, yytext + 2, strlen(yytext)-3);
		return B; 
	}
[a-zA-Z]+		{ return ident;}
"exit"		{return T_QUIT;}
"quit"		{return T_QUIT;}

%%

