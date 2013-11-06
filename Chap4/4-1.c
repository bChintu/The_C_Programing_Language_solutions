#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int strindex(char[],char[]);

int main(int argc,char *argv[])
{
    char string[100];
    int opt;
    int val=0;
    char pattern[100];
    while((opt=getopt(argc,argv,"s:c:")) != -1)
    {
        switch(opt)
        {
            case 's':
                strcpy(string,optarg);
                break;
            case 'c':
                strcpy(pattern,optarg);
                break;
            default: 
                fprintf(stderr, "Usage: %s [-s string] [-c character]\n",argv[0]);
                exit(EXIT_FAILURE);
        }
    
    }
    val=strindex(string,pattern);
    printf("index position:%d\n",val);
}
int strindex(char arr[],char pattern[])
{
    if((strlen(arr)< 0) && (strlen(pattern) < 0))
    {
        return -1;
    }
    int pos=-1;
    int i,j,k;
    for(i=0;arr[i]!= '\0';i++)
    {
        for(j=i,k=0;pattern[k]!= '\0'&& arr[j]==pattern[k];j++,k++);
        if(k > 0 && pattern[k] == '\0')
        {
            pos=i;
        }
    }
    return pos;
}









