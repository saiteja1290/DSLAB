#include<stdio.h>
#include<stdlib.h>

//global declarations
int a[100],top=-1,n;

//push ..to insert elements into the stack
void push()
{
	int d;
	if(top==n-1)
	{
		printf("\nstack is full\n");
	}
	else
	{
		printf("enter the data : ");
		scanf("%d",&d);
		top++;
		a[top]=d;
		printf("data is pushed successfully\n");
	}
}

//pop takes out the last element inserted in the stack
void pop()
{
	int d;
	if(top==-1)
	{
		printf("\nstack is empty\n");
	}
	else
	{
		printf("\nthe poped element is %d\n",a[top]);
		top--;
	}
}

//display function..to display all the elements in the stack
void display()
{
	int i;
	printf("\n");
	if(top==-1){
		printf("\nstack is empty\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d \n",a[top-i]);
		}
		printf("\n");
    }
}

//main function...program starts from here
void main()
{
	int b;
    printf("enter the stack size: ");
    scanf("%d",&n);
	while(1)
	{
		printf("\nselect one of the operation:\n1.push\n2.pop\n3.display\n4.exit\n");
		scanf("%d",&b);
		switch(b)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			break;
            default: printf("invalid entry...");
		}
	}
}