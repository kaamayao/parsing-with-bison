%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

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

%}

%token<ival> T_INT
%token<fval> T_FLOAT
%token<fname> T_FUNCTION
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT 
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE

%type<ival> expression
%type<fval> mixed_expression
%type<fname> function_name

%union {
	int ival;
	float fval;
    char *fname;
}

%start calculation

%%

calculation:
	   | calculation line
;

line: T_NEWLINE
    | mixed_expression T_NEWLINE { printf("\tResult: %f\n", $1);}
    | expression T_NEWLINE { printf("\tResult: %i\n", $1); }
	| function_name T_NEWLINE { printf("\tResult: %s\n", $1); }
    | T_QUIT T_NEWLINE { printf("bye!\n"); exit(0); }
;

function_name: T_FUNCTION 
	| function_name T_LEFT expression T_RIGHT{ 
		char * functionName = $1;
		float value = (float) $3;
		float result = executeFunction(functionName, value);
		char array[10];
		snprintf(array, sizeof(array), "%f", result);
		$$ = array;
	}
	| function_name T_LEFT mixed_expression T_RIGHT{ 
		char * functionName = $1;
		float value = (float) $3;
		float result = executeFunction(functionName, value);
		char array[10];
		snprintf(array, sizeof(array), "%f", result);
		$$ = array;
	}
;

mixed_expression: T_FLOAT                 		 { $$ = $1; }
	| mixed_expression T_PLUS mixed_expression	 { $$ = $1 + $3; }
	| mixed_expression T_MINUS mixed_expression	 { $$ = $1 - $3; }
	| mixed_expression T_MULTIPLY mixed_expression { $$ = $1 * $3; }
	| mixed_expression T_DIVIDE mixed_expression	 { $$ = $1 / $3; }
	| T_LEFT mixed_expression T_RIGHT		 { $$ = $2; }
	| expression T_PLUS mixed_expression	 	 { $$ = $1 + $3; }
	| expression T_MINUS mixed_expression	 	 { $$ = $1 - $3; }
	| expression T_MULTIPLY mixed_expression 	 { $$ = $1 * $3; }
	| expression T_DIVIDE mixed_expression	 { $$ = $1 / $3; }
	| mixed_expression T_PLUS expression	 	 { $$ = $1 + $3; }
	| mixed_expression T_MINUS expression	 	 { $$ = $1 - $3; }
	| mixed_expression T_MULTIPLY expression 	 { $$ = $1 * $3; }
	| mixed_expression T_DIVIDE expression	 { $$ = $1 / $3; }
	| expression T_DIVIDE expression		 { $$ = $1 / (float)$3; }
;

expression: T_INT				{ $$ = $1; }
	| expression T_PLUS expression	{ $$ = $1 + $3; }
	| expression T_MINUS expression	{ $$ = $1 - $3; }
	| expression T_MULTIPLY expression	{ $$ = $1 * $3; }
	| T_LEFT expression T_RIGHT		{ $$ = $2; }
;
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

