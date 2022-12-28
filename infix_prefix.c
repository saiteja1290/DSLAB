//infix to postfix by 2307

//required header files
#include<stdio.h>
#include<ctype.h>    // thif is for using the isalnum() function
#include<string.h>  //for strlen() and strrev()

//global declarations
char stack[100];
int top = -1,j=0;
char a[100];

//pushing into the stack top
void push(char x)
{
    stack[++top] = x;
}

//pop takes out the top of the stack
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

//priority order 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

//main function ..program strats from here
void main()
{
    int i,l;
    char exp[100],rexp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    l=strlen(exp);
    for(i=0;i<l;i++)
    {
        rexp[i]=exp[l-i-1];
    }
    rexp[i]='\0';
    printf("\nthe prefix form: ");
    e = rexp;
    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            a[j]=*e;
            j++;
        }   
        else if(*e == ')')
            push(*e);
        else if(*e == '(')
        {
            while((x = pop()) != ')')
            {
                a[j]=x;
                j++;
            }    
        }
        else
        {
            while(priority(stack[top]) > priority(*e))
            {
                a[j]=pop();
                j++;
            }   
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        a[j]=pop();
        j++;
    }
    for(j=0;j<l;j++)
    {
        printf("%c",a[l-1-j]);
    }
    printf("\n");
}
//end of the program