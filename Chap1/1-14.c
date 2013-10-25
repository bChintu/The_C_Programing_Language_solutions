#include<stdio.h>
int ascii[128];
int main()
{
    int c;
    int i,j;
    int count=0;
    while((c=getchar()) != EOF)
    {
	++ascii[c];
    }
    printf("histogram of the frequencies of different characters \n");
    for(i=0;i<128;i++)
    {
      //      if(ascii[i]!=0) {
	for(j=0;j<ascii[i];j++)
          printf("*");
	printf("\n");
	//      }
    }
    return 0;
}

            
