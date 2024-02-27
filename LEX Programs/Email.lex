%{
#include<stdio.h>
%}

%%

\n {return 0;} /* Ignore newline */
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ {printf("Valid Email\n"); return 0;}
.+$ {printf("Invalid Email\n");}

%%

int yywrap(void){}

int main()
{
yylex();
return 0;
}