%{
    #include<stdio.h>
    #include<math.h>
    int flag=0;
   
%}
%token NUMBER


%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%right '^'
%%
ArithmeticExpression: E{
         printf("\nResult=%d\n",$$);
         return 0;
        }
E:E'+'E {$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;}
 |E'/'E {$$=$1/$3;}
 |E'%'E {$$=$1%$3;}
 |'('E')' {$$=$2;}
 |E'^'E {$$=pow($1,$3);}
 |'-'E  {$$=-1*$2;}
 | NUMBER {$$=$1;}
;
%%

void main()
{
   printf("\nEnter expression\n");
   yyparse();
  if(flag==0)
   printf("\nExpression parsed succesfully\n\n");
 
}
void yyerror()
{
   printf("\nWrong expression\n\n");
   flag=1;
}