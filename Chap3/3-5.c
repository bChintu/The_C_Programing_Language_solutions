#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
void itob(int,char[],int);
int main(int argc,char *argv[])
{
    int opt;
    int number=0;
    int base=0;
    char arr[100];
    while((opt=getopt(argc,argv,"n:b:"))!=-1)
    {
        switch(opt)
        {

        case 'n':
            number=atoi(optarg);
            break;
        case 'b':
            base=atoi(optarg);
            break;
       
        default:
                 fprintf(stderr, "Usage: %s [-n number] [-b] base\n", argv[0]);
                 exit(EXIT_FAILURE);
    }
    }
    itob(number,arr,base);
    printf("String representation of integer[%d] with respect to the base[%d] is: %s\n",number,base,arr);
}
void itob(int n,char arr[],int base)
{
    static char digits[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sign;
    int i=0;
    if((sign=n) < 0)
        n = -n;
   do{
       arr[i++]=digits[n % base];
   }while((n/=base) > 0);
   if(sign < 0 )
       arr[i++]='-';
   arr[i]='\0';
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


