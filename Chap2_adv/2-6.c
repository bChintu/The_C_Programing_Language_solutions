#include<stdio.h>
int setbits(int x,int p,int n,int y);
int main()
{
    int val;
    val=0xFFF;
    printf("num=0x%x\n",val);
    val=setbits(val,7,4,0xFFFD);
    printf("num=0x%x\n",val);
}
int setbits(int x,int p,int n,int y)
{
    int mask=(1<<n)-1;
    y=(y & mask)<< (p-n+1);
    mask=~(((1<<n)-1) << (p-n+1));
    x&=mask;
    return x|y;
}

