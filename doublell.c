#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * prev;
};
void push(struct Node**head , int info){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode -> data = info;
//	newnode -> next = *head;
//	newnode -> prev = NULL;
	
	if(*head == NULL){
		*head = newnode;
	}
	
	newnode -> next = *head;
	newnode -> prev = NULL;
	
	*head = newnode;
}
void append(struct Node**head , int info){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode -> data = info;
	
	struct Node* last = *head;
	
	if(*head == NULL){
		newnode -> next = NULL;
		*head = newnode;
		return;
	}
	while(last -> next != NULL){
		last = last -> next;
	}
	
	newnode -> next = NULL;
	last -> next = newnode;
	newnode -> prev = last;
//	last = newnode;
}
void printlist(struct Node* head){
	struct Node* temp = head;
	
	while(temp != NULL){
		printf("%d\t",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
void main(){
	struct Node *head = NULL;
	
	append(&head ,8);
	push(&head,10);
	printlist(head);
	
}
