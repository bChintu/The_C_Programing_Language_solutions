#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char last='\0';

int getch();
void ungetch(int);
int main()
{
    int c;
    while((c = getch()) != EOF)
    {
        ungetch(c);
        putchar(getch());
        printf("\n");
    }
}
int getch()
{
    int ret;
    if(last == '\0')
    {
        ret=getchar();
    }
    else
    {
        ret=last;
        last='\0';
        return ret;
    }
    return ret;
}
void ungetch(int c)
{
    if(last != '\0')
    {
        printf("\n Too many characters \n");
    }
    else 
    {
        last=c;
    }
}


