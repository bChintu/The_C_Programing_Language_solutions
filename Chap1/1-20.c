#include<stdio.h>
#define MAX_SIZE 1024
int getLine();
char line[MAX_SIZE];
int calculate_spaces(int offset,int tabsize)
{
    return tabsize-(offset%tabsize);
}
int main()
{
    int no_of_tabs=5;
    int i,j,k;
    int l;
    while(getLine() > 0)
    {
        for(i=0,l=0;line[i]!= '\0';i++)
        {
            if(line[i] == '\t')
            {
                j=calculate_spaces(l,no_of_tabs);
                for(k=0;k<5;k++)
                {
                    putchar(' ');
                    l++;
                }
            }
            else 
            {
                putchar(line[i]);
                l++;
            }
        }
    }
}

int getLine()
{
    int i;
    int c;
    for(i=0;i<MAX_SIZE-1 && (c=getchar()) != EOF && c != '\n';i++)
        line[i]=c;
    if( c == '\n')
    {
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    return i;
}



