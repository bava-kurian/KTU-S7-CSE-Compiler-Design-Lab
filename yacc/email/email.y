%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);

extern FILE *yyin;
int valid = 0, invalid = 0;
%}

%token STRING INVALID

%%

input:
      /* empty */
    | input addr
    ;

addr:
      STRING '\n'    { valid++;  }
    | STRING         { valid++; }
    | INVALID '\n'   { invalid++; }
    | INVALID        { invalid++; }
    | '\n'           { /* empty line */ }
    ;

%%

int yyerror(char *msg) {
    /* We don’t need to print msg for each invalid email */
    return 0;
}

int main() {
    FILE *in = fopen("input.txt", "r");
    if(!in){
        perror("File open failed");
        return 1;
    }

    yyin = in;
    yyparse();

    printf("Valid: %d\n", valid);
    printf("Invalid: %d\n", invalid);

    fclose(in);
    return 0;
}
