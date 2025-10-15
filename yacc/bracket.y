%{
#include <stdio.h>
#include <stdlib.h>
%}

%token LEFT RIGHT

%%
input: valid '\n' { printf("Valid expression\n"); }
     | valid      { printf("Valid expression\n"); }
     ;

valid: /* empty */
     | valid LEFT valid RIGHT
     ;
%%

int main()
{
    printf("Enter expression:\n");
    yyparse();
    return 0;
}

int yyerror()
{
    printf("Invalid expression\n");
    return 0;
}
