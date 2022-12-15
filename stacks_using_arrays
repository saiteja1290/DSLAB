#include<stdio.h>
#include<stdlib.h>
int stack[100], top , n,i,choice;
void push(int val){
	if(top >= n-1){
		printf("Stack Overflow");
	}
	else{
//		printf("Enter the value in stack >>");
		top++;
		stack[top] = val;
	}
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n");
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
void pop(){
	if(top <= -1){
		printf("Stack underflow");
	}
	else{
//		top--;
		printf("popped element is %d >>",stack[top]);
//		free(&stack[top]);
		top--;
	}
}

int main()
{
    top=-1;
    int value;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
            	printf("Enter value >> ");
				scanf("%d",&value);
				push(value);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
