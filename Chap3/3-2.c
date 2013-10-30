#include<stdio.h>
void escape(char[],char[]);
int main()
{
    char source[100];
    char destination[100]="sdfsdf\t\nasdjhkjasd";
    printf("with sequences : %s\n",destination);
    escape(source,destination);
    printf("string : %s\n",source);
}
void escape(char src[],char des[])
{
    int i=0;
    int j=0;
    while(des[i] != '\0')
    {
        switch(des[i])
        {
            case '\n':src[j++]='\\';
                      src[j++]='n';
                      break;
            case '\t':src[j++]='\\';
                      src[j++]='t';
                      break;
            default:src[j++]=des[i];
        }
    i++;
    }
}
