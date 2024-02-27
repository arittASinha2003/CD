%{
#include<stdio.h>
%}

%%

\n {return 0;} /* Ignore newline */
^[aeiouAEIOU]$ {printf("Vowel\n"); return 0;}
^[a-zA-Z]$ {printf("Consonant\n"); return 0;}
.+$ {printf("Invalid Input\n");}

%%

int yywrap(void){}

int main()
{
yylex();
return 0;
}