%{ 
	#include <stdio.h> 
	#include <string.h> 
	#include <stdlib.h> 
	extern int yylex(); 
	
	void yyerror(char *msg); 
	int flag; 
	
	int i; 
	int k =0;	 
%} 

%union { 
	char* f; 
} 

%token <f> STR 
%type <f> E 

%% 

S : E { 
		flag = 0; 
		k = strlen($1); 
		if(k%2==0){ 
		
		for (i = 0; i <= k/2; i++) { 
		if ($1[i] == $1[k-i-1]) { 
			} else { 
			flag = 1; 
			} 
		} 
		if (flag == 1) {
            printf("%s is not a palindrome\n",$1); 
            return 0;}
		else {
            printf("%s is a palindrome\n",$1);
            return 0; }
		
		
		}else{ 
		
		for (i = 0; i < k/2; i++) { 
		if ($1[i] == $1[k-i-1]) { 
		} else { 
			flag = 1; 
			} 
			} 
		if (flag == 1) {
            printf("%s is not a palindrome\n",$1);
            return 0; }
		else {
            printf("%s is a palindrome\n",$1);
            return 0; }
			 
		

		} 
	} 
; 

E : STR {$$ = $1;} 
; 

%% 

void yyerror(char *msg) 
{ 
	fprintf(stderr, "%s\n", msg); 
	exit(1); 
} 

int main() 
{ 
	yyparse(); 
	return 0; 
} 
