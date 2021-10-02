%{
#include<stdio.h>
int yyerror(char *errormsg);
%}

%%

(([a|b]*[c|d]*)|a[b]*[c]*d)[" "|"\n"]  {printf("expression 1\n",yytext);}
([0|1]*|[0]*[1]*)[" "|"\n"]  {printf("expression 2\n",yytext);}
((0[1]*2|[0]*2|1)(0[1]*2|[0]*2|1)*)[" "|"\n"]     {printf("expression 3\n",yytext);}

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