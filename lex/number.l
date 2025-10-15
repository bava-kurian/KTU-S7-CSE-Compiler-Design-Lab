%{
    #include<stdio.h>

%}

%%
[0-9]+ {printf("integer:%s",yytext);}
[0-9]*\.[0-9]+ {printf("Floating point: %s",yytext);}
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