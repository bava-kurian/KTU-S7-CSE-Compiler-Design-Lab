%{
#include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9_.]*@[a-zA-Z]+\.[a-z]{2,4}  { return STRING; }
[ \t]       ;           /* ignore spaces/tabs */
\n          { return '\n'; }
.           { return INVALID; }

%%

int yywrap() { return 1; }
