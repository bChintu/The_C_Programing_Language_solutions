#include<stdio.h>
#include<string.h>
#include<unistd.h>
void itoa(int,char[],int);
int main(int argc,char *argv[])
{
    int opt;
    int number=0;
    int padding=0;
    char arr[100];
    while((opt=getopt(argc,argv,"n:p:")) != -1)
    {
        switch(opt)
        {
            case 'n':
                number=atoi(optarg);
                break;
            case 'p':
                padding=atoi(optarg);
                break;
            default:
                fprintf(stderr,"Usuage: %s [-n] number [-b] base\n",argv[0]);
                break;
        }
    }
    itoa(number,arr,padding);
    printf("Integer to ascii conversion: %s\n",arr);
}
void itoa(int n,char arr[],int pad)
{
    int sign=n;
    int i=0,j,length;
    char temp;
    if((sign=n)< 0)
        n=-n;
   do{
       arr[i++]=n%10+'0';
   }while((n/=10) > 0);
   if(sign < 0 )
       arr[i++]='-';
   while(pad > 0)
   {
       arr[i++]=' ';
       pad--;
   }
   arr[i]='\0';
   length=strlen(arr);
   for(i=0,j=length-1;i<length/2;i++,j--)
   {
       temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;
   }

}


