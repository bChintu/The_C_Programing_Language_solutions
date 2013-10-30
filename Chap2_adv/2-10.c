#include<stdio.h>
char lower(char);
int main()
{
    char arr[100]="a01921BCVsakjsaASADSADFDFGDGFSDSDF";
    puts(arr);
    int i=0;
    while(arr[i] != '\0')
    {
        putchar(lower(arr[i++]));
    }
    printf("\n");
}
char lower(char ch)
{
  char temp;
  temp=(ch >= 'A' && ch <= 'Z') ? (ch + 32):ch;
  return temp;
}

