#include<stdio.h>
float celsius_calc(int);
int main()
{
    float fahr,celsius;
    float lower,upper,step;
    lower=0;
    upper=300;
    step=20;
    fahr=lower;
    float temp;
    while(fahr <= upper)
    {
        temp=celsius_calc(fahr);
        printf("%3.0f %6.1f\n",fahr,temp);
        fahr=fahr+step;
    }
}
float celsius_calc(int value)
{
    int fahr=value;
    int celsius=(5.0/9.0)*(fahr-32);
    return celsius;
}


