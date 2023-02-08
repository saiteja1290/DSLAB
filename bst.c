#include <stdio.h>
#include <stdlib.h>
struct Node
{
    /* data */
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node*newnode(int d)
{
    struct Node *nayanode = (struct Node *)malloc(sizeof(struct Node));
    nayanode->data = d;
    nayanode->left = nayanode->right = NULL;

    return nayanode;
}
struct Node*insert(struct Node *root, int info)
{
    if (root == NULL)
    {
        return newnode(info);
    }

    if (info < root->data)
    {
        root->left = insert(root->left, info);
    }
    else
    {
        root->right = insert(root->right, info);
    }

    return root;
}
void inorder(struct Node *root){
    //base case 
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root -> right);

}
int main()
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    inorder(root);
    return 0;
}
