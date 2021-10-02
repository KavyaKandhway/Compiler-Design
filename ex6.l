%{
#include<stdio.h>
int yyerror(char *errormsg);
%}

%%
" "|"\t";
([!@#$&"*"_|][a-zA-Z0-9]*[" "|"\n"])	 {printf("Token 1\n", yytext);}
([0-9][a-zA-Z!@#$&_"*"][" "|"\n"])	 {printf("Token 2\n", yytext);}
([(a-zA-Z)][" "|"\n"])|([a-zA-Z][a-zA-Z0-9!@#$&_"*"]*[a-zA-Z][" "|"\n"]) {printf("Token 3\n",yytext);}
. 	{yyerror("Unknown character"); }

%%

int yywrap()
{return 1;}

int main(void)
{yylex(); return 0;}

int yyerror(char *errormsg)
{
fprintf(stderr, "%s\n", errormsg);
exit(1);
}