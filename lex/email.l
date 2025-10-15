%{
#include<stdio.h>    
int falg=0;
%}

%%
[a-z0-9_.]+@[a-z]+(\.[com|in|org|edu]) {printf("valid email");}
.|\n  
%%

int main()
{
    printf("Enter the address: \n");
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}