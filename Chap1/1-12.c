#include<stdio.h>
int main()
{
    int c,state=1;
    while ((c=getchar()) != EOF)
    {
        switch(c)
        {
            case ' ':
            case '\t':
            case '\n':
                if(0 == state)
                {
                    printf("\n");
                    state=1;
                }
                break;
           default :state=0;
                    putchar(c);
                    break;
        }
    }
}



