#include<stdio.h>
#include<ctype.h>

double atoF(char[]);
int main()
{
    char arr[]="12.1e+2";
    double val=atoF(arr);
    printf("string to double conversion : %lf\n",val);
}
double atoF(char str[])
{
    int i;
    int sign;
    int e;
    double value,power;
    for(i=0;isspace(str[i]);i++);
    sign=(str[i] == '-') ? -1:1;
    if(str[i]== '+' || str[i] == '-')
        i++;
    for(value=0.0;isdigit(str[i]);i++)
        value=10.0*value+(str[i]-'0');
    if(str[i] == '.')
        i++;
    for(power=1.0;isdigit(str[i]);i++)
    {
        value=value*10.0+(str[i]-'0');
        power*=10.0;
    }
    value=sign*value/power;
    printf("debugg: %lf\n",value);
    if(str[i] == 'e' || str[i] == 'E')
    {
        i++;
        sign=(str[i] == '-') ? -1:1;
        if(str[i] == '+' || str[i] == '-')
            i++;
        for (e=0;isdigit(str[i]);i++)
         e=e*10.0+(str[i]-'0');                                         
        if(sign == 1)
            for(;e>0;e--)
                value*=10;
        else
            for(;e>0;e--)
                value/=10;
    }
    return value;
}

        
            








