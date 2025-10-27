#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;
char input[100];
int ip = 0;
int step = 1;

int prec(char op) {
    if (op=='+' ) return 1;
    if (op=='*' || op=='/') return 2;
    return 0;
}

int isOp(char c) {
    return (c=='+' || c=='*' || c=='/');
}

void print(const char *act) {
    stack[top+1] = '\0';
    printf("%-4d | %-12s | %-10s | %s\n", step++, act, stack, &input[ip]);
}

void reduce() {
    while (1) {
        // a → E or b → E
        if (stack[top]=='a' || stack[top]=='b') {
            stack[top] = 'E';
            print("REDUCE");
        }
        // E op E → E
        else if (top>=2 && stack[top]=='E' && isOp(stack[top-1]) && stack[top-2]=='E') {
            char op = stack[top-1];
            char next = input[ip];

            if (isOp(next) && prec(next) > prec(op)) // postpone
                return;

            top -= 2;
            stack[top] = 'E';
            print("REDUCE");
        }
        else return;
    }
}

int main() {
    printf("Enter expression: ");
    scanf("%s", input);

    printf("\nStep | Action       | Stack      | Remaining\n");
    printf("---------------------------------------------\n");

    while (1) {
        if (input[ip]=='$' && top==0 && stack[0]=='E') {
            print("ACCEPT");
            printf("\nExpression is valid.\n");
            break;
        }

        char cur = input[ip];
        if (cur=='\0') { input[ip]='$'; continue; }

        stack[++top] = cur;
        char act[20];
        sprintf(act,"SHIFT %c",cur);
        print(act);
        ip++;

        reduce();
    }
}
