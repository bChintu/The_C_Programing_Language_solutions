#include<stdio.h>
int htoi(char arr[]); 
char string[100];
int main()
{
    int decimal;
    printf("\n enter the hexa decimal value \n");
    scanf("%s",string);
    decimal= htoi(string);
    printf("Decimal value:%d\n",decimal);
}
int htoi(char a[])
{
    int i=2;
    int number=0;
    while(a[i] != '\0')
    {
                number=number*16;
            if(a[i] >= '0' && a[i] <= '9')
            {
                number=number+(a[i]-'0');
            }
	    if((a[i]>='A' && a[i] <='F') || (a[i]>='a' && a[i] <= 'f')) {
	     switch(a[i]) {
	     case 'a':
	     case 'A':
	       number+=10;
	       break;
	     case 'b':
	     case 'B':
	       number+=11;
	     break;
	     case 'c':
	     case 'C':
	       number+=12;
	     break;
	     case 'd':
	     case 'D':
	       number+=13;
	     break;
	     case 'e':
	     case 'E':
	       number+=14;
	     break;
	     case 'f':
	     case 'F':
	       number+=15;
	     break;
	     }
	   }
    i++;
    }
return number;
}







