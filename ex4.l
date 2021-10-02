%{
#include<stdio.h>
int yyerror(char *errormsg);
%}

%%
" "|"\t"|"\n" ;
else[" "|"\n"] {printf("ELSE\n", yytext);}
int[" "|"\n"] {printf("INT\n", yytext);}
char[" "|"\n"] {printf("CHAR\n", yytext);}
void[" "|"\n"] {printf("VOID\n", yytext);}
if[" "|"\n"] {printf("IF\n", yytext);}
while[" "|"\n"] {printf("WHILE\n", yytext);}
return[" "|"\n"] {printf("RETURN\n", yytext);}
([+|-][0-9][0-9]*[" "|"\n"]) {printf("Integer\n", yytext);}
([0-9][0-9]*[" "|"\n"]) {printf("Integer\n", yytext);}
([+|-][0-9][0-9]*[.][0-9][0-9]*[" "|"\n"]) {printf("REAL\n", yytext);}
([0-9][0-9]*[.][0-9][0-9]*[" "|"\n"]) {printf("REAL\n", yytext);}
([0-9][0-9]*[.][0-9]*[e][+|-][0-9][0-9]*[" "|"\n"]) {printf("REAL\n", yytext);}
([0-9][0-9]*[e][+|-][0-9][0-9]*[" "|"\n"]) {printf("REAL\n", yytext);}
([+|-][0-9][0-9]*[e][+|-][0-9][0-9]*[" "|"\n"]) {printf("REAL\n", yytext);}
([+|-][0-9][0-9]*[.][0-9]*[e][+|-][0-9][0-9]*[" "|"\n"]) {printf("REAL\n", yytext);}
([-][>][" "|"\n"]) {printf("PTR_OP\n", yytext);}
([&][&][" "|"\n"]) {printf("AND_OP\n", yytext);}
([|][|][" "|"\n"]) {printf("OR_OP\n", yytext);}
([.][" "|"\n"]) {printf("DOT_OP\n", yytext);}
([+][" "|"\n"]) {printf("+\n", yytext);}
([-][" "|"\n"]) {printf("-\n", yytext);}
([*][" "|"\n"]) {printf("*\n", yytext);}
([/][" "|"\n"]) {printf("/\n", yytext);}
([;{},=()&][" "|"\n"]) {printf("%s is separator\n", yytext);}
([[][" "|"\n"]) {printf("%s\n", yytext);}
([]][" "|"\n"]) {printf("%s\n", yytext);}



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