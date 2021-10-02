%{ 
    /* Definition section */
    #include <stdio.h> 
    #include <stdlib.h> 
    #include "y.tab.h" 
%} 
  
/* %option noyywrap */
  
/* Rule Section */
%% 
  
[a-c]+   {yylval.f = yytext; return STR;} 
[ \t\n]      {;} 

   
%% 
  
 int yywrap() 
 {  
  return -1;  
 }   
