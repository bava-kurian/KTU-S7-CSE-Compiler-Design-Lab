#include<stdio.h>
#include<string.h>

int  main()
{
    char inter[100][100],str[10],op[10];
    printf("Enter the INtermediate code \n");
    int i=0;
    do {
    {
        scanf("%s",inter[i]);
    }
    }while (strcmp(inter[i++],"End"));
    

    printf("Target code:\n");
    i=0;
    do {
    {
        strcpy(str,inter[i]);
        switch(str[3])
        {
            case '+':
            strcpy(op,"ADD");
            break;
            case '-':
            strcpy(op,"SUB");
            break;
            case '*':
            strcpy(op,"MUL");
            break;
            case '/':
            strcpy(op,"DIV");
            break;

        }

        printf("\n MOV %c, R%d",str[2],i);
        printf("\n %s R%d %c",op,i,str[4]);
        printf("\n MOV R%d %c",i,str[0]);
    }
    }while (strcmp(inter[i++],"End"));
    return 0;
}