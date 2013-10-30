#include<stdio.h>
int right_rotate(int,int);
int main()
{
    int value=7;
    int rot_value=right_rotate(value,3);
    printf("Rotated value : %d\n",rot_value);

}
int right_rotate(int value,int n)
{
    int temp=value;
    int temp1=temp>>n;
    int temp2=temp<<n;
    int val=temp1 | temp2;
    return val;
}
