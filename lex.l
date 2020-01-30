%{
    #include<stdio.h>
    #include "y.tab.h"
%}

variables_name [a-zA-z_][a-zA-Z0-9]*
integer_value [+-]?[0-9]+
float_value [+-]?[0-9]*\.?[0-9]{0,6}
char_value \'.\'

%%
";"	return semicolon;
","	return cama;
"="	return equal;
"+"	return plus;
"-"	return minus;
"*"	return mult;
"/"	return divs;
"&"	return and;
"|"	return or;
"("	return op;
")"	return cp;
"{"	return ob;
"}"	return cb;
"int" return int_type;
"double" return double_type;
"float" return float_type;
"char" return char_type;
{integer_value} {yylval.int_value = atoi(yytext); return int_val;}
{float_value}   {yylval.float_value = atof(yytext);return float_val;}
{char_value}    {yylval.char_value = yytext[1];return char_val;}
{variables_name}    {strcpy(yylval.variable,yytext); return id;}

[\n \t] ;
.   ;
%%

int yywrap(){return done;}
