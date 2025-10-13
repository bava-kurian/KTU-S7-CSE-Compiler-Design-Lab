%{
int valid=0;
%}

%%

[a-z0-9_.]+@[a-z_0-9]+\.[com|in|org]   {printf("Email valid"); valid=1;}

.|\n
%%
int main()
{
    printf("Enter the num:\n");
    yylex();
    if (!valid)
    printf("Email invalid");
    return 0;
}

int yywrap() {
    return 1;
}

