%{
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
%}

%union {
	int ival;
	float fval;
	struct{ 
		char name[50];
		float value;  
	} variable;
}

%token<ival> T_INT
%token<fval> T_FLOAT
%token<variable> T_NAME
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT T_EQUALS
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE

%type<ival> expression
%type<fval> mixed_expression
%type<variable> variable_name

%start calculation

%%

calculation:
	   | calculation line
;

line: T_NEWLINE
    | mixed_expression T_NEWLINE { printf("\tResult: %f\n", $1);}
    | expression T_NEWLINE { printf("\tResult: %i\n", $1); }
	| variable_name T_NEWLINE { printf("\tResult: %f\n", $1.value); }
    | T_QUIT T_NEWLINE { printf("bye!\n"); exit(0); }
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

variable_name: T_NAME 	{
		$1.value = findValue($1.name);
		$$ = $1;
	}		 
	| variable_name T_EQUALS expression 	{ 
		addVariables($1.name, $3); 
	}
	| variable_name T_EQUALS mixed_expression 	{ 
		addVariables($1.name, $3); 
	}

	| variable_name T_PLUS variable_name 	{ 
		$1.value = $1.value + $3.value;
		$$ = $1;
	}
	| variable_name T_PLUS expression 	{ 
		$1.value = $1.value + $3;
		$$ = $1;
	}
	| variable_name T_PLUS mixed_expression 	{ 
		$1.value = $1.value + $3;
		$$ = $1;
	}
	| expression T_PLUS variable_name { 
		$3.value = $1 + $3.value;
		$$ = $3;
	}
	| mixed_expression T_PLUS variable_name { 
		$3.value = $1 + $3.value;
		$$ = $3;
	}

	| variable_name T_MINUS variable_name 	{ 
		$1.value = $1.value - $3.value;
		$$ = $1;
	}
	| variable_name T_MINUS expression 	{ 
		$1.value = $1.value - $3;
		$$ = $1;
	}
	| variable_name T_MINUS mixed_expression 	{ 
		$1.value = $1.value - $3;
		$$ = $1;
	}
	| expression T_MINUS variable_name { 
		$3.value = $1 - $3.value;
		$$ = $3;
	}
	| mixed_expression T_MINUS variable_name { 
		$3.value = $1 - $3.value;
		$$ = $3;
	}

	| variable_name T_MULTIPLY variable_name 	{ 
		$1.value = $1.value * $3.value;
		$$ = $1;
	}
	| variable_name T_MULTIPLY expression 	{ 
		$1.value = $1.value * $3;
		$$ = $1;
	}
	| variable_name T_MULTIPLY mixed_expression 	{ 
		$1.value = $1.value * $3;
		$$ = $1;
	}
	| expression T_MULTIPLY variable_name { 
		$3.value = $1 * $3.value;
		$$ = $3;
	}
	| mixed_expression T_MULTIPLY variable_name { 
		$3.value = $1 * $3.value;
		$$ = $3;
	}

	| variable_name T_DIVIDE variable_name 	{ 
		$1.value = $1.value / $3.value;
		$$ = $1;
	}
	| variable_name T_DIVIDE expression 	{ 
		$1.value = $1.value / $3;
		$$ = $1;
	}
	| variable_name T_DIVIDE mixed_expression 	{ 
		$1.value = $1.value / $3;
		$$ = $1;
	}
	| expression T_DIVIDE variable_name { 
		$3.value = $1 / $3.value;
		$$ = $3;
	}
	| mixed_expression T_DIVIDE variable_name { 
		$3.value = $1 / $3.value;
		$$ = $3;
	}

	| variable_name T_LEFT mixed_expression T_RIGHT {
		char * functionName = $1.name;
		float value = (float) $3;
		float result = executeFunction(functionName, value);
		char array[10];
		snprintf(array, sizeof(array), "%f", result);
		$1.value = result;
		$$ = $1;
	}
	| variable_name T_LEFT expression T_RIGHT {
		char * functionName = $1.name;
		float value = (float) $3;
		float result = executeFunction(functionName, value);
		$1.value = result;
		$$ = $1;
	}
	| variable_name T_LEFT variable_name T_RIGHT {
		char * functionName = $1.name;
		float value = (float) $3.value;
		float result = executeFunction(functionName, value);
		$1.value = result;
		$$ = $1;
	}
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
