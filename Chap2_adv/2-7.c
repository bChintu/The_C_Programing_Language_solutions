#include<stdio.h>
int invert(int x,int p,int n);
int main()
{
   int x=32;
   printf("After Inverting the position value is %d\n",invert(x,4,3));
}
int invert(int x,int p,int n)
{
    int temp;
    temp=(x >>(32-n));
    printf("%d\n",temp);
    return temp^(1<<(p-1));
}





