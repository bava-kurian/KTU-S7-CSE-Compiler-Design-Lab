#include<stdio.h>

struct transition{
    int from;
    char input;
    int to;
};

struct transition transitions[100];
int transition_count;

int closure[100],closure_count;

int is_inclosure(state)
{
    for (int i=0;i<closure_count;i++)
    {
        if (closure[i]==state)
        {
            return 1;
        }
    return 0;
    }
}

void find_closure(int state)
{
    if (!is_inclosure(state))
    {
        closure[closure_count++]=state;
    
    }
    for(int i=0;i<transition_count;i++)
    {
        if(transitions[i].from==state && transitions[1].input=='e')
            {
                find_closure(transitions[i].to);
            }
    }
}


void main()
{
    printf("Enter the number of transitions:");
    scanf("%d",&transition_count);

    printf("Enter the transitions(from input to):\n");  
    for (int i=0;i<transition_count;i++)
    {
        scanf("%d %c %d",&transitions[i].from,&transitions[i].input,&transitions[i].to);
    }

    printf("\n--- Transitions ---\n");
    for (int i = 0; i < transition_count; i++) {
        printf("q%d --%c--> q%d\n", transitions[i].from, transitions[i].input, transitions[i].to);
    }

    int max_state=0;
    for(int i=0;i<transition_count;i++)
    {
        if (transitions[i].from>max_state)
        {
            max_state=transitions[i].from;
        }
        if (transitions[i].to>max_state)
        {
            max_state=transitions[i].to;
        }
    }
    
    for (int i=0;i<=max_state;i++)
    {
        closure_count=0;
        find_closure(i);
        printf("ε-closure(q%d): { ", i);
    for (int i = 0; i < closure_count; i++)
        printf("q%d ", closure[i]);
    printf("}\n");
    }
}
    