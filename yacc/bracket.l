%{
#include "y.tab.h"   
%}

%%
"(" {return LEFT;}
")" {return RIGHT;}
.|\n
%%

int yywrap()
{
    return 1;
}