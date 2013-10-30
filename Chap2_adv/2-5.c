#include<stdio.h>
#include<string.h>
int any(char s1[],char s2[]);
int main()
{
    char string[100],string1[100];
    printf("enter the strings \n");
    scanf("%s %s",string,string1);
    printf(" %d\n",any(string,string1));
}
int any(char s1[],char s2[])
{
    int i,j;
    for(i=0;i<strlen(s1);i++)
        for(j=0;j<strlen(s2);j++)
            if(s1[i] == s2[j])
            {
                printf("%c--->",s2[j]);   
                return i;
            }
return -1;
}




