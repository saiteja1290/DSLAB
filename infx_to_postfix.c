//infix to postfix by 2307

//required header files
#include<stdio.h>
#include<ctype.h> // thif is for using the isalnum() function

char stack[100];
int top = -1;

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
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\nthe postfix form: ");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c",pop());
    }
    printf("\n");
}
//end of the program