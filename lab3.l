%{
#include<stdio.h>
int yyerror(char *errormsg);
%}

%%
[.]*+" "+[.]* {printf("%s is Invalid\n", yytext);}
([!@#$&"*"_|]+[a-zA-Z0-9_]*)+"\n"	 {printf("%s is Token 1\n", yytext);}
([0-9]+[a-zA-Z!@#$&_"*"]*)+"\n"	 {printf("%s is Token 2\n", yytext);}
(a-zA-Z)|([a-zA-Z]+[a-zA-Z0-9!@#$&_"*"]*+[a-zA-Z])+"\n" printf("%s is Token 3\n",yytext);

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