%{
    #include<stdio.h>
    #include<math.h>
    int flag=0;
   
%}

%nonassoc 'i'
%nonassoc 't'
%nonassoc 'e'
%nonassoc 'a' 'b'

%%

S:'i'C't'S {;}
  |'i'C't'S'e'S {;}
  |'a' {;}

C:'b' {;}
;
%%

void main()
{
   printf("\nEnter expression\n");
   yyparse();
  if(flag==0)
   printf("\nparsing successfull\n\n");
 
}
void yyerror()
{
   printf("\nWrong expression not parsed successfully\n\n");
   flag=1;
}