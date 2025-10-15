%{
#include<stdio.h>    
int v=0,c=0,w=0,t=0,n=0;
%}

%%
[aeiosAEIOU] {v++;}
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] {c++;}
[ ] {w++;}
[0-9] {n++;}
[\t] {t++;}
.|\n 
%%

int main()
{
    printf("Enter the string\n");
    yylex();
    printf("vowels:%d\n",v);
    printf("consonants:%d\n",c);
    printf("spaces:%d\n",w);
    printf("tabs:%d\n",t);
    printf("digits:%d\n",n);
    return 0;
}

int yywrap()
{
    return 1;
}       