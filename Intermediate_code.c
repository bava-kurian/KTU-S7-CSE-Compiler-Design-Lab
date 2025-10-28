#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Infix → Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) { // operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Generate Three Address Code from postfix
void generateTAC(char postfix[]) {
    char tempStack[100][10]; // holds operands or temporaries
    int tempTop = -1;
    int t = 1;

    printf("\nIntermediate Code (Three Address Code):\n");

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            char str[2] = {c, '\0'};
            strcpy(tempStack[++tempTop], str);
        }
        else { // operator
            char op2[10], op1[10], res[10];
            strcpy(op2, tempStack[tempTop--]);
            strcpy(op1, tempStack[tempTop--]);

            sprintf(res, "t%d", t++);
            printf("%s = %s %c %s\n", res, op1, c, op2);

            strcpy(tempStack[++tempTop], res);
        }
    }

    printf("\nFinal Result: %s\n", tempStack[tempTop]);
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nPostfix Expression: %s\n", postfix);

    generateTAC(postfix);
    return 0;
}
