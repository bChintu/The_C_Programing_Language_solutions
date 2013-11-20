#include<stdio.h>
void rev_string(char*);
char *b;

int main()
{
    char string[]="constant string";
    char buffer[100];
    b=buffer;
    rev_string(string);
    printf("\nIn main : %s\n buffer[0]:%c",buffer,buffer[0]);
    printf("\n");

}
void rev_string(char *s)
{
    if(*s != '\0')
    {
        rev_string(s+1);
         printf("%c",*s);
         sprintf(b,"%c",*s);
         b++;
    }

}
    



