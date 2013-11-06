#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>


#define MAXOP 100 
#define NUMBER 0

int sp=0;
int getop(char[]);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
void display_stack();

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

        case '?':
            showTop();
            break;
        case '#':
            duplicate();
            break;
        case '~':
            swapItems();
            break;
        case 'D':
            display_stack();
            break;
        default:
            break;
    }
}
return EXIT_SUCCESS;
}
#define MAXVAL 100
double val[MAXVAL];
//int sp=0;
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
void showTop(void)
{
    if(sp>0)
        printf("Top of the stack:%8g\n",val[sp-1]);
    else
        printf("The stack is empty\n");
}
void display_stack()
{
    int i;
    printf("stack contents....\n");
    for(i=0;i<sp;i++)
        printf("  %lf",val[i]);
    printf("\n");
}

void duplicate(void)
{
    double temp=pop();
    push(temp);
    push(temp);
}
void swapItems(void)
{
    double item1=pop();
    double item2=pop();
    push(item1);
    push(item2);
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
    return (bufp > 0) ? buf[--bufp]:getchar();
}
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else 
        buf[bufp++]=c;
}

                   


