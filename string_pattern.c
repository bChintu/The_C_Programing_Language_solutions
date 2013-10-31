#include<stdio.h>
#define MAXLINE 1000
int getLine(char [],int);
int strindex(char [],char []);
int main()
{
    char line[MAXLINE];
    char temp_array[10]="ould";
    int found=0;
    while(getLine(line,MAXLINE) > 0)
    {
        if(strindex(line,temp_array) >= 0)
        {
            printf("string :%s\n",line);
            found++;
        }
    }
    printf("matched pattren count:%d\n",found);
    return found;
}
int getLine(char line[],int limit)
{
    int c;
    int i=0;
    while(--limit && ((c=getchar()) != EOF) && c != '\n')
        line[i++]=c;
    if(c == '\n')
        line[i++]=c;
    line[i]='\0';
    printf("i value : %d\n",i);
    return i;
}
int strindex(char lin[],char temp_arr[])
{
    int i,j,k;
    for(i=0;lin[i] != '\0';i++)
    {
        for(j=i,k=0;temp_arr[k] != '\0' && lin[j] == temp_arr[k];j++,k++);
          if(k>0 && temp_arr[k] == '\0')
           return i;
    }
return -1;
}




