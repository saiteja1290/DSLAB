#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void push(struct Node**head , int info){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode -> data = info;
	newnode -> next = *head;
	*head = newnode;
}
void append(struct Node**head , int info){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = *head;
	newnode ->data = info;
	newnode -> next = NULL;
	if(*head == NULL){
		*head = temp;
	}
	while(temp->next != NULL){
	temp = temp->next;
	}
	temp -> next = newnode;
}
void insertafter(struct Node **head , int prevnode , int info){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = *head;
	while(prevnode != 1){
		temp = temp -> next;
		prevnode --;
	}
	newnode -> data = info;
	newnode -> next = temp->next;
	temp -> next = newnode;
}
void deletion(struct Node **head , int index){
	struct Node *temp = *head;
	while(index!=1){
		temp = temp -> next;
		index --;
	}
	temp->next = temp->next->next;
}
void search(struct Node *head , int info){
//	if(head == NULL){
//		printf("list is empty");
//	}
	int count = 0;
	while(head != NULL){
		count ++;
		if(head->data == info){
			break;
		}
		head = head->next;
	}
	printf("it is at place - %d",count);
	printf("\n");
}
void traverse(struct Node *head){
	if(head == NULL){
		printf("list is empty");
	}
	while(head != NULL){
		printf("%d ",head->data);
		head = head -> next;
	}
	printf("\n");
}
void main(){
	struct Node*head = NULL;
	push(&head,8);
	append(&head,9);
	append(&head,9);
	append(&head,9);
	append(&head,9);
	traverse(head);
	insertafter(&head , 2,3);
//	search(head,9);
	traverse(head);
	deletion(&head,2);
	traverse(head);
}
