%{
#include<stdio.h>    
%}

%%
[0-9]*[1,3,5,7,9] {printf("Number is odd");}
[0-9]*[0,2,4,6,8] {printf("Number is even");}
.|\n 
%%

int main()
{
    printf("Enter the number\n");
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}