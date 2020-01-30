%{
    #include<stdio.h>
    #include<string.h>
    #include "soundoukouwa.h"
    #include "tools.h"
    int line = 1;

    queue vars;

    char *current_type;
    char variable[32];
%}

%union{
    char _type;
    char variable[32];
    int int_value;
    float float_value;
    char char_value;
    double double_value;
    char str[256];
}
%token<_type> type
%token<variable> id
%token<int_value> int_val
%token<float_value> float_val
%token<double_value> double_val
%token<char_value> char_val
%token<number> str

%token int_val float_val char_val double_val	//for values
%token int_type float_type double_type char_type//for types
%token semicolon cama  op cp ob cb		//garboujati
%token equal plus minus mult divs and or	//signs
%token done

%%
start: program {line++;yyparse();return 0;}
program: declaration {}
	|operation
        |
        |done {return 0;}
        ;


operation: id equal exp		{printf("Valid operation!\n");}
	;
exp: 	term
	;
exp:	exp plus term
	;
exp:	exp minus term
	;
term:	factor
	;
term:	term mult factor
	;
term:	term divs factor
	;
factor:	number
	;
factor:	id
	;
factor:	op exp cp	{}
	;

	number:  int_val	{
					char temp[20];
					sprintf(temp,"%d ",$1);
					strcpy($$.str,temp);
					printf("%s\n",$$.str);

				}
	|double_val
	|float_val
	|char_val
	;

declaration: 	 int_type int_var semicolon	{
							char *val;
							while(!queue_empty(vars)){
								dequeue(&vars,variable);
								printf("Dim %s As Integer",getVariablename(variable,&val));
								if(val){
									printf(" = %s",val);
									val = NULL;
								}
								printf("\n");
							}
						}
		|float_type float_var semicolon{
							char *val;
							while(!queue_empty(vars)){
								dequeue(&vars,variable);
								printf("Dim %s As Float",getVariablename(variable,&val));
								if(val){
									printf(" = %s",val);
									val = NULL;
								}
								printf("\n");
							}
                                               	}
		|double_type double_var semicolon{
							char *val;
							while(!queue_empty(vars)){
								dequeue(&vars,variable);
								printf("Dim %s As Double",getVariablename(variable,&val));
								if(val){
									printf(" = %s",val);
									val = NULL;
								}
								printf("\n");
							}
						}
		|char_type char_var semicolon{
							char *val;
							while(!queue_empty(vars)){
								dequeue(&vars,variable);
								printf("Dim %s As Char",getVariablename(variable,&val));
								if(val){
									printf(" = \"%s\"",val);
									val = NULL;
								}
								printf("\n");
							}
						}
		;

int_var: int_var cama int_var
	|id	{
			enqueue(&vars,$1);
		}
	|id equal int_val	{
					char all[64];
					sprintf(all,"%s=%d",$1,$3);
					enqueue(&vars,all);
				}
	;

float_var: float_var cama float_var
	|id	{
			enqueue(&vars,$1);
		}
	|id equal float_val	{
					char all[64];
					sprintf(all,"%s=%f",$1,$3);
					enqueue(&vars,all);
				}
	| id equal int_val	{
					char all[64];
					sprintf(all,"%s=%d",$1,$3);
					enqueue(&vars,all);
				}
	;

double_var: double_var cama double_var
	|id	{
			enqueue(&vars,$1);
		}
	|id equal double_val	{
					char all[64];
					sprintf(all,"%s=%lf",$1,$3);
					enqueue(&vars,all);
				}
	;

char_var: char_var cama char_var
	|id	{
			enqueue(&vars,$1);
		}
	|id equal char_val 	{
					char all[64];
					sprintf(all,"%s=%c",$1,$3);
					enqueue(&vars,all);
				}
	;


%%

int yyerror(char *s){
    printf("error: %s at line %d\n",s,line);
}

int main(){
    vars = new_queue();
    yyparse();
    return 0;
}