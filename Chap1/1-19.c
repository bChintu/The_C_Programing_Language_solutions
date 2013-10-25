#include<stdio.h>
void reverse(char []);
char line[1024];
int main()
{
    int c;
    int i;
    for(i=0; (c=getchar()) != EOF;++i)
        line[i]=c;
    if(c == '\n')
    {
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    reverse(line);
    printf("String reverse : %s \n",line);
    return 0;
}
void reverse(char s[])
{
    int i,j;
    int length=0;
    char temp;
    for(i=1;s[i]!= 0;i++)
        length++;
    printf("length : %d\n",length);
    for(i=0,j=length-1;i<length/2;i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    s[length]='\0';
}





    



