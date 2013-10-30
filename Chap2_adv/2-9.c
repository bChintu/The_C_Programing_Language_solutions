#include<stdio.h>
int bitcount(unsigned);
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int val=bitcount(n);
    printf("No of bits:%d\n",val);
}
int bitcount(unsigned int n)
{
    int b;
    for(b=0;n != 0; n &=(n-1))
    {
            printf("%d\n",n);
            b++;
    }
    return b;
}


