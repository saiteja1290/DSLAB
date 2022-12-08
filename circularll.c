#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
void append(struct Node**head , int info){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	
	newnode -> data = info;
	if(*head == NULL){
		newnode -> next = newnode;
		*head =  newnode;
	}
	
	struct Node *temp = *head;
	temp = temp -> next;
	
	while(temp -> next != *head){
		temp = temp -> next;
	}
	
	temp -> next = newnode;
	newnode -> next = *head;
}
void insertafter(struct Node** head , int pos , int info){
	struct Node* newnode =  (struct Node*)malloc(sizeof(struct Node));
	int i;
	newnode -> data = info;
	struct Node* temp = *head;
	for(i = 0 ; i < pos-1 ; i++){
		temp = temp -> next;
	}
	
	newnode -> next = temp -> next;
	temp -> next = newnode;
	
}
void printlist(struct Node*head){
	struct Node * temp = head;
	printf("%d\t",temp -> data);
	temp = temp -> next;
	while(temp != head){
		printf("%d\t",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
void main(){
	struct Node *head = NULL;
	append(&head,10);
	append(&head,100);
	append(&head,200);
	append(&head,120);
	printlist(head);
	insertafter(&head,2,500);
	printlist(head);
}
