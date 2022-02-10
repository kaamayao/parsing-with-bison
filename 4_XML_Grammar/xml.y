%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH_ARRAY 256
#define MAX_LENGTH_WORD 256
#define true 1
#define false 0

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

typedef enum { NON_MATCHING_CLOSING_BRACKETS = 0 } e_errors;

char open[MAX_LENGTH_ARRAY][MAX_LENGTH_WORD];
char close[MAX_LENGTH_ARRAY][MAX_LENGTH_WORD];
int indexOpen = 0;
int indexClose = 0;

void validateSyntax( ) {
	bool validTags = true;	
	for (int i = 0; i < indexOpen; i++) {
		if(strcmp(open[i], close[i]) != 0 ) {
			validTags = false;	
		}
	}
	if (validTags) { 
		printf("Valid syntax\n");
	}
	else { 
		yyerror("Invalid syntax\n");
	}
}
%}

%token T_NEWLINE T_QUIT
%token<name> ident
%token<name> A
%token<name> B

%type<name> val
%type<name> open
%type<name> close
%type<name> L

%union {
    char *name;
}

%start start_point

%%

start_point: | start_point L T_NEWLINE {
	validateSyntax();
};

L:  open L close { 
		strcpy(open[indexOpen], $1);
		strcpy(close[indexClose], $3);
		indexOpen++; 
		indexClose++; 
		$$ = $2; 
	} 
	| val { $$ = $1; }
	| L L
;

open: A { 
		$$ = $1; 
	};

close: B { 
		$$ = $1;
	};

val: | ident;
%%

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
