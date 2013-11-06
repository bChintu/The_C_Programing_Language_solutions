#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAXOP 100 
#define NUMBER 0

int getop(char[]);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while((type=getop(s)) != EOF)
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
        printf("%lf\n",val[sp]);
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
int getch();
void ungetch(int);
int getop(char s[])
{
    int i=0;
    int c;
    int next;
    while((s[0]= c = getch()) == ' ' || c == '\t');
    s[1]='\0';
    i=0;
    if(!isdigit(c) && c != '.' && c != '-')
        return c;
    if(c == '-')
    {
        next=getch();
        if(!isdigit(next) || next == '.')
        {
            return c;
        }
         c=next;
    }
        else
            c=getch();
    while(isdigit(s[++i]=c))
        c=getch();
    if(c == '.')
        while(isdigit(s[++i]=c=getch()));
    s[i]='\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
    return (bufp > 0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else 
        buf[bufp++]=c;
}

                   


