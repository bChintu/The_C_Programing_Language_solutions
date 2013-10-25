#include<limits.h>
#include<float.h>
#include<stdio.h>
int main()
{
    printf("\n Ranges of character,integer,short and long\n");
    printf("character ranges \n");
    printf("%d,%d,%d",CHAR_BIT,CHAR_MAX,CHAR_MIN);
    printf("\n Floating values .. \n");
    printf("%f \t%f\n",FLT_MAX,FLT_MIN);
    printf("%d\n",sizeof(float));
}

