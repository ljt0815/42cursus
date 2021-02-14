#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int main(void)
{
    TreeNode *n1, *n2, *n3;

    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));
    n1->data = 10;
    n1->left = n2;
    n1->right = n3;
    n2->left = 0;
    n2->right = 0;
    n3->data = 30;
    n3->right = 0;
    free(n1); free(n2); free(n3);
    return 0;
}