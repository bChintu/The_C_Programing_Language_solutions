#include<stdio.h>
#include<string.h>
void squeeze(char s1[],char s2[]);

int main()
{
    char *string1[]={"test"};
    char *string2[]={"ing1"};
    char buffer[50];
    size_t cnt_string1=sizeof(string1)/sizeof(string1[0]);
    size_t cnt_string2=sizeof(string2)/sizeof(string2[0]);
    size_t left=0;
    size_t right=0;
    for(left=0;left<cnt_string1;left++)
    {
        for(right=0;right<cnt_string2;right++)
        {
            strcpy(buffer,string1[left]);
            squeeze(buffer,string2[right]);
            printf("[%s]-[%s]=%s\n",string1[left],string2[right],buffer);
        }
    }
    return 0;
}

void squeeze(char s1[],char s2[])
{
    int i,j,k;
    int instr2=0;
    for(i=j=0;s1[i]!= '\0';i++)
    {
        instr2=0;
        for(k=0;s2[k] != '\0'&& !instr2;k++)
        {
            if(s2[k] == s1[i])
            {
                instr2=1;
            }
        }
        printf("debugg: %d\n",instr2);
        if(!instr2)
        {
            s1[j++]=s1[i];
        }
    }
    s1[j]='\0';
}



   
