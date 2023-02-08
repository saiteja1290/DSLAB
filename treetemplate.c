#include<stdio.h>
#include<stdlib.h>
struct Node
{
    /* data */
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node*buildtree(struct Node*root){
    
    int x;
    struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data >>\n");
    scanf("%d",&x);
    newnode -> data = x;
    if(x == -1){
        return NULL;
    }
    
    printf("ENter the left data for %d node\n",x);
    newnode -> left = buildtree(newnode->left);
    printf("ENter the right data for %d node\n",x);
    newnode -> right = buildtree(newnode -> right);

    return newnode;

}

void main(){

    struct Node* root = NULL;
    root = buildtree(root);
}
