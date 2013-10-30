#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void expand(char *,char *);
int main()
{
    //char *s1[]={"a-z-","z-a-","-1-6-","a-ee-a","a-R-L","1-9-1","5-5",NULL};
    char *s1[]={"a-z-"};
    char result[100];
    int i=0;
    while(s1[i])
    {
        expand(result,s1[i]);
        printf("Unexpanded : %s\n",s1[i]);
        printf("Expanded :%s\n",result);
        i++;
    }
return 0;

}
void expand(char *s1,char *s2)
{
    static char upper_alp[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char lower_alp[27]="abcdefghijklmnopqrstuvwxyz";
    static char digits[11]="0123456789";
    char *start,*end,*p;
    int i=0;
    int j=0;
    while(s2[i])
    {
        printf("Debugg : %s\n",s2);
        switch(s2[i])
        {
            printf("char %c\n",s2[i]);
            case '-':
                if( i == 0 || s2[i+1] == '\0')
                {
                    printf("inside if\n");
                    s1[j++]='-';
                    ++i;
                    break;
                }
                else
                {
                printf("%d %c %c\n",i,s2[i-1],s2[i+1]);
                    if((start=strchr(upper_alp,s2[i-1])) && (end=strchr(upper_alp,s2[i+1])));
                    else if((start=strchr(lower_alp,s2[i-1])) && (end=strchr(lower_alp,s2[i+1])));
                    else if((start=strchr(digits,s2[i-1])) && (end=strchr(digits,s2[i+1])));
                    else
                    {
                        fprintf(stderr,"EX3_3:Mismatched operands '%c-%c' \n",s2[i-1],s2[i+1]);
                        s1[j++]=s1[i-1];
                        s1[j++]=s2[i++];
                        break;
                    }
                    p=start;
                    while(p != end)
                    {
                        s1[j++]=*p;
                        if(end>start)
                            ++p;
                        else
                            --p;
                    }
                    s1[j++]=*p;
                    i+=2;
                }
                break;
            default:
                if(s2[i+1]== '-' && s2[i+2] != '\0')
                {
                    ++i;
                }
                else
                {
                    s1[j++]=s2[i++];
                }
                break;
        }
    }
    s1[j]=s2[i];
}



   


