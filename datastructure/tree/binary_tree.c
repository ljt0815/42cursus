#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void inorder(TreeNode *root)
{
    if (root != 0)
    {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode *root)
{
    if (root != 0)
    {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root != 0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void)
{
    TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7;

    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));
    n4 = (TreeNode *)malloc(sizeof(TreeNode));
    n5 = (TreeNode *)malloc(sizeof(TreeNode));
    n6 = (TreeNode *)malloc(sizeof(TreeNode));
    n7 = (TreeNode *)malloc(sizeof(TreeNode));

    n1->data = 17;
    n1->left = n2;
    n1->right = n3;
    n2->data = 15;
    n2->left = n4;
    n2->right = 0;
    n3->data = 93;
    n3->left = n5;
    n3->right = n6;
    n4->data = 5;
    n4->left = 0;
    n4->right = 0;
    n5->data = 35;
    n5->left = n7;
    n5->right = 0;
    n6->data = 95;
    n6->left = 0;
    n6->right = 0;
    n7->data = 22;
    n7->left = 0;
    n7->right = 0;
    
    preorder(n1);
    puts("");
    inorder(n1);
    puts("");
    postorder(n1);
    puts("");

    free(n1); free(n2); free(n3); free(n4); free(n5); free(n6); free(n7);
    return 0;
}