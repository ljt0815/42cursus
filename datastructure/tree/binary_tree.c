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

int	equal(TreeNode *t1, TreeNode *t2)
{
	int	result = 0;

	if (t1 == NULL && t2 == NULL)
		return 0;
	else if (t1 == NULL && t2 != NULL)
		return 1;
	else if (t1 != NULL && t2 == NULL)
		return 1;
	//if (t1 != NULL && t2 != NULL)
	if (t1->data == t2->data)
		result = equal(t1->left, t2->left) + equal(t1->right, t2->right);
	else
		result = 1;
	
	return result;
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
    TreeNode *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8;

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
    t1 = (TreeNode *)malloc(sizeof(TreeNode));
    t2 = (TreeNode *)malloc(sizeof(TreeNode));
    t3 = (TreeNode *)malloc(sizeof(TreeNode));
    t4 = (TreeNode *)malloc(sizeof(TreeNode));
    t5 = (TreeNode *)malloc(sizeof(TreeNode));
    t6 = (TreeNode *)malloc(sizeof(TreeNode));
    t7 = (TreeNode *)malloc(sizeof(TreeNode));
    t8 = (TreeNode *)malloc(sizeof(TreeNode));
    t1->data = 17;
    t1->left = t2;
    t1->right = t3;
    t2->data = 15;
    t2->left = t4;
    t2->right = 0;
    t3->data = 93;
    t3->left = t5;
    t3->right = t6;
    t4->data = 5;
    t4->left = 0;
    t4->right = 0;
    t5->data = 35;
    t5->left = t7;
    t5->right = 0;
    t6->data = 95;
    t6->left = 0;
    t6->right = 0;
    t7->data = 22;
    t7->left = 0;
    t7->right = 0;
    //t7->right = t8;
   	//t8->data = 5; 
    //t8->left = 0;
    //t8->right = 0;
    preorder(n1);
    puts("");
    inorder(n1);
    puts("");
    postorder(n1);
    puts("");
    postorder(t1);
    puts("");
	printf("equal t1, n1 : %d", equal(t1, n1));
    free(n1); free(n2); free(n3); free(n4); free(n5); free(n6); free(n7);
    free(t1); free(t2); free(t3); free(t4); free(t5); free(t6); free(t7);
    return 0;
}
