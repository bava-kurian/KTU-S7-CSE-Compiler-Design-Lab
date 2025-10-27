#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DFA(char str[])
{
    int state=0;
    for(int i=0;str[i]!='\0';i++)
    {
     switch(state)  
     {
          case 0: state = (str[i] == '0') ? 1 : 0; break;
            case 1: state = (str[i] == '0') ? 1 : 2; break;
            case 2: state = (str[i] == '0') ? 1 : 0; break;
        
     }
    }
    return state;
}

int main()
{
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    int state=DFA(str);
    if (state==2)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }
    return 0;
    }