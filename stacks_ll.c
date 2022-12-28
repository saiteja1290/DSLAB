#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//global declarations
struct node *head=NULL,*ptr,*temp;
int n,top=-1;

//push inserts the element in the stack
void push()
{
    int a;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(top==n-1)
    {
        printf("\nstack is full\n");
    }
    else
    {
        printf("enter the data: ");
        scanf("%d",&a);
        if(head==NULL)
        {
            head=ptr;
            head->data=a;
            head->next=NULL;
            top++;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            ptr->data=a;
            ptr->next=NULL;
            temp->next=ptr;
            top++;
        }
    }
}

//pop takes out the last elemenet in the stack
void pop()
{
    temp=head;
    if(head==NULL||head->next==NULL)
    {
        if(head==NULL)
        {
            printf("\nstack is empty");
        }
        else
        {
            printf("\nthe poped element: %d\n",head->data);
            free(head);
            head=NULL;
            top--;
        }
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("\nthe poped element: %d\n",temp->next->data);
        free(temp->next);
        temp->next=NULL;
        top--;
    }
}

//to display the stack elements
void display()
{
    int i,j;
    if(top==-1)
    {
        printf("\nstack is empyty");
    }
    else
    {
        printf("\n");
        for(i=top;i>=0;i--)
        {
            temp=head;
            for(j=0;j<i;j++)
            {
                temp=temp->next;
            }
            printf("%d\n",temp->data);
        }
        /*temp=head;
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);*/
    }
}

//main function..program starts from here
void main()
{
    int b;
    printf("\nenter the size of the stack: ");
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
            default: printf("invalid entry...\n");
		}
	}
}
//end of the program