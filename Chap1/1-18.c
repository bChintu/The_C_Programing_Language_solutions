/* program to remove trailing blanks and tabs from each line of input nad to delete entirely blank lines */
#include<stdio.h>
int main()
{
    int c;
    while((c=getchar()) != EOF)
    {
        if(c==' ') {
	  putchar(c);
	  while((c=getchar())==' ');
	}
	if(c=='\t') {
	  putchar(c);
	  while((c=getchar())=='\t');
	}
	if(c=='\n') {
	  putchar(c);
	  while((c=getchar())=='\n');
	}
	putchar(c);
    }

    return 0;
}



    

