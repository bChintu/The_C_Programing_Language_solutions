#include<stdio.h>
int main()
{
    int c;
    int nwords=0,nlines=0;
    int word_length[100];
    int i=0,count=0,j;
    while ((c = getchar())!= EOF)
    {
        if(c == ' ' || c == '\t')
        {
            word_length[i++]=count;
            ++nwords;
            count=0;
        }
        else if( c == '\n')
        {
            word_length[i++]=count;
            ++nwords;
            count=0;
            nlines++;
        }
        else 
        {
           ++count;
        }
    }
    printf("\n nwords :%d nlines :%d \n",nwords,nlines);

    printf("word length in a line \n");
    for(i=0;i<nwords;i++)
    {
        printf(" nwords[%d]--->length:%d \n",i,word_length[i]);
   }
   printf("\n histogram bars with the horizontal....\n");
   
   printf("\nword_length histogram\n");
   for(i=0;i<nwords;i++)
   {
       printf("  %d           ",word_length[i]);
       for (j=0;j<word_length[i];j++)
       {
           printf("*");
       }
       printf("\n");
   }
   int max_element=word_length[0];
   for(i=1;i<nwords;i++)
   {
      if (max_element < word_length[i])
      {
          max_element=word_length[i];
      }
   }
   printf("maximum size of the word :%d \n",max_element);
   printf("\n histogram bars with the vertical .....\n");
   for (i=max_element;i>0;i--)
   {
       printf("%4d |",i);
       for (j=0;j<nwords;j++)
       {
           if(word_length[j] >= i)
           {
               printf("*");
           }
           else
           {
               printf(" ");
           }
       }
       printf("\n");
   }
   printf("     +");
   printf("-------------------\n");
   printf("      ");
   for(i=0;i<nwords;i++)
   {
       printf("%d",word_length[i]);
   }
   printf("\n");

}







