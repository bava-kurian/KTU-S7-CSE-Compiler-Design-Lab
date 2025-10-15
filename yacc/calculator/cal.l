%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }

"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"("         { return '('; }
")"         { return ')'; }

[ \t]       ;       /* ignore spaces and tabs */
\n          { return '\n'; }

.           { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() { return 1; }
