#include <stdio.h>
#include <stdlib.h>

void ungets(const char[]);
void ungetch(int);
void getch

int main()
{
    int c;
    char *string="pushing characters back to its input";
    ungets(string);
    while((c=getch()) != EOF)
        putchar(c);
    return 0;
}




