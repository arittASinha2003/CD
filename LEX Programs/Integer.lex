%{
#include<stdio.h>
%}

%%

\n {return 0;} /* Ignore newline */
^-?[0-9]+$ {printf("Valid Integer\n"); return 0;}
.+$ {printf("Invalid Integer\n");}

%%

int yywrap(void){}

int main()
{
yylex();
return 0;
}