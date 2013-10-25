#include<stdio.h>
int main()
{
    int blanks=0,tabs=0,nlines=0;
    int c;
    while((c=getchar()) != EOF)
    {
       if( c== ' ')
          ++blanks;
       else if(c == '\t')
          ++tabs;
       else if(c == '\n')
          nlines++;
    }
    printf("banks : %d ,tabs : %d ,newlines : %d \n",blanks,tabs,nlines);
} 
