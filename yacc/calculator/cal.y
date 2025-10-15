%{
 #include<stdio.h>    
 #include<stdlib.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
cal: exp '\n' {printf("answer:%d",$1);}

exp: NUMBER {$$=$1;}
    | exp '+' exp {$$=$2+$3;}
    | exp '-' exp {$$=$2-$3;}
    | exp '*' exp {$$=$2*$3;}
    | exp '/' exp {$$=$2/$3;}
%%  

int main()
{
    printf("Enter the expression:");
    yyparse();
    return 0;
}
int yyerror()
{
    printf("syntax error");
    exit(1);
}