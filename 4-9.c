#include<stdio.h>
#include<string.h>

int getch();
void ungetch(int);

int main()
{
    int c;
    ungetch(EOF);
    while((c = getch()) != EOF)
        putchar(c);
}

#define bufsize 100
int bufp=0;
char buffer[bufsize];

int getch()
{
    return (bufp > 0) ? buffer[--bufp]:getchar();
}

void ungetch(int c)
{
    if (bufp >= bufsize)
    {
        printf("ungetch : too many characters \n");
    }
    else 
    {
        if(c != EOF)
        {
            buffer[bufp++] = c;
        }
    }
    printf("ungetch: %s\n",buffer);
}

