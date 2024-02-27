%{
#include<stdio.h>
#include<string.h>
int i=0;
%}

%%
"Rama"|"Sita"|"Laxman"  {printf("\n Verb");}
%%

int yywrap(void){}


int main()
{
yylex();
return 0;
}