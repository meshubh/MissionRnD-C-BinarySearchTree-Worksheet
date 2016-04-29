/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int countnodes(struct node *root)
{
	if (root == NULL)
		return 0;
	else
		return(countnodes(root->left) + 1 + countnodes(root->right));
}

void storeInorder(struct node *root, int *arr, int *count)
{
	if (root == NULL)
		return;

	storeInorder(root->left, arr, count);
	*(arr + *count) = root->data;
	*count = *count + 1;
	storeInorder(root->right, arr, count);
}
void storePreorder(struct node *root, int *arr, int * count)
{
	if (root == NULL)
		return;
	*(arr + *count) = root->data;
	*count = *count + 1;
	storePreorder(root->left, arr, count);
	storePreorder(root->right, arr, count);

}
void storePostorder(struct node *root, int *arr, int *count)
{
	if (root == NULL)
		return;

	storePostorder(root->left, arr, count);
	storePostorder(root->right, arr, count);
	*(arr + *count) = root->data;
	*count = *count + 1;
}

void inorder(struct node *root, int *arr)
{
	if (arr == NULL)
		return;
	int count = 0;
	storeInorder(root, arr, &count);
	return;
}
void preorder(struct node *root, int *arr)
{
	if (arr == NULL)
		return;
	int count = 0;
	storePreorder(root, arr, &count);
	return;
}
void postorder(struct node *root, int *arr)
{
	if (arr == NULL)
		return;
	int count = 0;
	storePostorder(root, arr, &count);
	return;
}