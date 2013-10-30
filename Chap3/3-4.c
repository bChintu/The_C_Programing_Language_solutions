#include<stdio.h>
#include<string.h>
void itoa(long int,char[]);
int main()
{
   long int num;
    printf(" enter the number \n");
    scanf("%ld",&num);
    printf("n:  %ld\n",num);
    char arr[100];
    itoa(num,arr);
    printf("In main: %s\n",arr);
}
void itoa(long int n,char arr[])
{
    long int sign=n;
    int i=0;
    if(n<0)
        n=-n;
   do{
       arr[i++]=n%10+'0';
   }while((n/=10) > 0);
   if(sign < 0 )
       arr[i++]='-';
   arr[i]='\0';
   printf("%s\n",arr);
   int length=strlen(arr);
   char temp;
   int j;
   for(i=0,j=length-1;i<length/2;i++,j--)
   {
       temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;
   }

}


