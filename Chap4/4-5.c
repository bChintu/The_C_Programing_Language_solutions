#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define MAXOP 100 
#define NUMBER 0
#define IDENTIFIER 1 

void display_stack();
int getop(char[]);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
void clearstack();
void math_func(char[]);

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
        case IDENTIFIER:
            math_func(s);
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
        case '?':
            showTop();
            break;
        case '#':
            duplicate();
            break;
        case '$':
            display_stack();
            break;
        case '~':
            swapItems();
            break;
        case '!':
            clearstack();
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
void display_stack()
{
    printf("stack size: %d\n",sp);
    int i;
    for(i=0;i<sp;i++)
        printf(" %lf",val[i]);
    printf("\n");
}

void showTop(void)
{
    if(sp>0)
        printf("Stack contents:%8g\n",val[sp-1]);
    else
        printf("The stack is empty\n");
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
void clearstack(void)
{
    sp=0;
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
    if(isalpha(c))
    {
        while(isalpha(s[i++] = c))
            c=getch();
        s[i-1]='\0';
        if( c != EOF)
            ungetch(c);
        return IDENTIFIER;
    }
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
#include<math.h>
void math_func(char s[])
{
    double op2;
    if(strcmp(s,"sin") == 0)
        push(sin(pop()));
    else if(strcmp(s,"exp") == 0)
        push(exp(pop()));
    else if(strcmp(s,"pow") == 0)
    {
        op2=pop();
        push(pow(pop(),op2));
    }
    else
        printf("unsupported function: %s\n",s);
}

                   


