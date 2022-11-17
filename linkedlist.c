#include<stdio.h>
int main()
{
	struct Node{
		int roll_num;
		char name[20];
		struct Node* link;
	};
	
	struct Node* head = NULL;
	struct Node* first = NULL;
	
	//Allocation of memory
	
	head = (struct Node*)malloc(sizeof(struct Node*));
	first = (struct Node*)malloc(sizeof(struct Node*));
	
	head -> roll_num = 43;
//	head -> name = "Pranith";
	head -> link = first;
	first -> roll_num = 99;
//	first -> name = "Daniel";
	first -> link = NULL;
	
	while (head != NULL)
	{
		printf("Roll : %d",head->roll_num);
		//printf("Name : %s",head->name);
		head = head -> link;
	}
	
}
