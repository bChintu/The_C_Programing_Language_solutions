#include<stdio.h>
#include<string.h>
void itoa(long int);
int main()
{
   long int num;
    printf(" enter the number \n");
    scanf("%ld",&num);
    itoa(num);
    printf("\n");

}
void itoa(long int n)
{
    char arr[100];
    long int sign=n;
    int i=0;
    if(n<0)
        n=-n;
       if(n/10)
           itoa(n/10);
    arr[i++]=n%10+'0';
    arr[i]='\0';
    printf("%s",arr);

}


