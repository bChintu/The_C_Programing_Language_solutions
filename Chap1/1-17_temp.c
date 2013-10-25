#include<stdio.h>
#define minlength 81
int readbuf(char *);
int copyline(char *);
int main()
{
    char buffer[minlength];
    int status=0;
    while(status != -1)
    {
        status=readbuf(buffer);
        if(status == 1)
            status=copyline(buffer);
    }
    return 0;
}
int readbuf(char *buffer)
{
    size_t i=0;
    int c;
    while(i < minlength)
    {
        c=getchar();
        if(c == EOF)
            return -1;
        if(c == '\n')
            return 0;
        buffer[i++]=c;
    }
    return 1;
}
int copyline(char *buffer)
{
    size_t i;
    int c;
    int status=1;
    for(i=0;i<minlength;i++)
    putchar(buffer[i]);
    while (status == 1)
    {
        c=getchar();
        if(c == EOF)
            status= -1;
        else if(c == '\n')
            status=0;
        else 
            putchar(c);
    }
    printf("\n");
    return status;
}




