#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int getLine(char line[],int maxline);
void copy(char to[],char from[]);
int main()
{
    int length;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max=0;
    while((length=getLine(line,MAXLINE)) > 0)
    {
        printf("length : %d line : %s",length,line);
        if(length > max)
        {
            max=length;
            copy(longest,line);
        }
    }
    if(max > 0)
    {
        printf(" \nLongest string :%s and its length:%d\n",longest,max);
    }
    printf("\n");
    return 0;
}
int getLine(char s[],int lim)
{
    int c,i;
    for(i=0;i<lim-1 && (c=getchar()) != EOF && c != '\n';++i)
        s[i]=c;
    if(c == '\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}
void copy(char to[],char from[])
{
    int i=0;
    while((to[i] = from[i]) != '\0')
        ++i;
}




