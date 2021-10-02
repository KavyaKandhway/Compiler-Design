%{
#include<stdio.h>
int yyerror(char *errormsg);
%}

%%
" "|"\t"|"\n" ;
while|if|else|begin|end|thenfor|do|while|switch|case|default|break|goto	 {printf("%s is a Keyword\n", yytext);}
([(a-zA-Z)|_]+[a-zA-Z0-9_]*)	 {printf("%s is an Identifier\n", yytext);}
[/][" "]*[*][" "|a-z|A-Z|0-9|"\t"|"\n"|!@#$%^&*_()-+=]*[*][" "]*[/] printf("Comment\n");


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