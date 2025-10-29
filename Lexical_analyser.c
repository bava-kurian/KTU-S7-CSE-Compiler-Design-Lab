#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[][10] = {
    "int", "float", "if", "else", "while", "do", "for", "return", "break", "continue"
};

int isKeyword(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[50];
    FILE *fp;
    int i, j = 0;

    fp = fopen("input.txt", "r"); // sample input file
    if (fp == NULL) {
        printf("Error while opening the file!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        // Identify Identifiers and Keywords
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } 
        else if ((ch == ' ' || ch == '\n' || ch == '\t' || ispunct(ch)) && j != 0) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
                printf("%s : Keyword\n", buffer);
            else if (isalpha(buffer[0]))
                printf("%s : Identifier\n", buffer);
            else
                printf("%s : Number\n", buffer);
        }

        // Identify Operators and Special Symbols
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '!') {
            printf("%c : Operator\n", ch);
        } else if (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
                   ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            printf("%c : Special Symbol\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
