// Recursive Descent Parser with Step-by-Step Trace
// Grammar:
// E  → T E'
// E' → + T E' | ε
// T  → F T'
// T' → * F T' | ε
// F  → (E) | id

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char input[100];
int i = 0;
int step = 1; // for numbering trace steps

// Function declarations
void E();
void Eprime();
void T();
void Tprime();
void F();

void print_trace(const char *func) {
    printf("%-5d | %-8s | %-s\n", step++, func, &input[i]);
}

// Helper: match and consume expected character
void match(char expected) {
    print_trace("match");
    if (input[i] == expected)
        i++;
    else {
        printf("\nError at position %d: Expected '%c'\n", i + 1, expected);
        exit(1);
    }
}

// Grammar rule implementations with tracing
void E() {
    print_trace("E");
    T();
    Eprime();
}

void Eprime() {
    print_trace("E'");
    if (input[i] == '+') {
        match('+');
        T();
        Eprime();
    }
}

void T() {
    print_trace("T");
    F();
    Tprime();
}

void Tprime() {
    print_trace("T'");
    if (input[i] == '*') {
        match('*');
        F();
        Tprime();
    }
}

void F() {
    print_trace("F");
    if (input[i] == '(') {
        match('(');
        E();
        match(')');
    } else if (isalpha(input[i])) { // id = single letter
        match(input[i]);
    } else {
        printf("\nError at position %d: Invalid symbol '%c'\n", i + 1, input[i]);
        exit(1);
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    printf("\n%-5s | %-8s | %-s\n", "Step", "Function", "Remaining Input");
    printf("---------------------------------\n");

    E();

    if (input[i] == '\0')
        printf("\nExpression is valid.\n");
    else
        printf("\nInvalid expression. Extra characters after parsing.\n");

    return 0;
}
