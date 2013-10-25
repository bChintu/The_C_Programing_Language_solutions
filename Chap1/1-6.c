#include<stdio.h>
int main()
{
    int c;
    c=getchar();
    int exp;
    if (exp=(c != EOF))
    {
        printf("%d",exp);
    }
    else 
      printf ("%d\n",EOF);
}


