#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define MAXOP 100 
#define NUMBER '0'
#define MAXLINE 1000

char line[MAXLINE];
int getop(char[]);
void push(double);
double pop(void);
int getLine(char[],int);
int line_i;

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while(getLine(line,MAXLINE) != 0)
    {
        line_i=0;
        while((type=getop(s)) != '\0')
        {

        switch(type)
        {

        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '*':
            push(pop()*pop());
            break;
        case '-':
            op2=pop();
            push(pop() - op2);
            break;
        case '/':
            op2=pop();
            if(op2)
                push(pop() / op2);
            else
                printf("error:Division error\n");
            break;
        case '%':
            op2=pop();
            if(op2)
                push(fmod(pop(),op2));
            else
                printf("error:zero division\n");
            break;
        case '\n':
            printf("\n\t%.8g\n",pop());
            break;
        default:
            printf("\n error:unknown command %s\n",s);
            break;
    }
        }

}
return EXIT_SUCCESS;
}
#define MAXVAL 100
double val[MAXVAL];
int sp=0;
void push(double f)
{
    if(sp < MAXVAL)
    {
        val[sp++]=f;
    }
    else 
        printf("\nerror:stack full,can't push %g\n",f);
}
double pop()
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("\n error :stack empty \n");
        return 0.0;
    }
}

#include<ctype.h>

int getop(char s[])
{
    int i;
    int c;
    while((s[0]= c = line[line_i++]) == ' ' || c == '\t');
    s[1]='\0';
    if(!isdigit(c) && c != '.' && c != '-')
            return c;
    i=0;
    if(isdigit(c))
        while(isdigit(s[++i]= c = line[line_i++]));
    if(c == '.')
        while(isdigit(s[++i]= c = line[line_i++]));
    s[i]='\0';
    line_i--;
    return NUMBER;
}

int getLine(char s[],int limit)
{
    int c,i;
    i=0;
    while(--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++]=c;
    if(c == '\n')
        s[i++]=c;
    s[i]='\0';
    return i;
}



                   


