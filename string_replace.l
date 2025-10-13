%{
#include <stdio.h>

FILE *out;
%}

%%
"printf"    { fprintf(out, "writef"); }    /* Replace printf with writef */
"scanf"     { fprintf(out, "readf"); }     /* Replace scanf with readf */
.|\n        { fprintf(out, "%s", yytext); } /* Print everything else as is */
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        perror("File opening failed");
        return 1;
    }

    out = fopen("output.txt", "w");  // Open output file
    if (!out) {
        perror("Cannot open output.txt for writing");
        fclose(in);
        return 1;
    }

    yyin = in;   // Set Lex input to the file
    yylex();     // Run lexical analysis

    fclose(in);
    fclose(out);
    printf("Processing complete. Check output.txt\n");
    return 0;
}

int yywrap() {
    return 1;
}