/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int count_nodes(struct node *root)
{
	if (root == NULL)
		return 0;
	else
		return(count_nodes(root->left) + 1 + count_nodes(root->right));
}
void search_in_bst_store_in_arr(struct node *root, int iterator, int *iterator1, int *arr)
{
	if (root->data == *(arr + iterator))
	{
		if (root->right == NULL && root->left == NULL)
		{
			return;
		}
		if (root->right != NULL)
		{
			if (root->right->data != NULL)
			{
				*(arr + (*iterator1)) = root->right->data;
				*iterator1 = *iterator1 + 1;
			}
		}
		if (root->left != NULL)
		{
			if (root->left->data != NULL)
			{
				*(arr + (*iterator1)) = root->left->data;
				*iterator1 = *iterator1 + 1;
			}
		}
		return;
	}
	if (root->data < *(arr + iterator))
		return search_in_bst_store_in_arr(root->right, iterator, iterator1, arr);
	else if (root->data > *(arr + iterator))
		return search_in_bst_store_in_arr(root->left, iterator, iterator1, arr);
}
void tree_row_traversal(struct node *root, int *arr, int size)
{
	int iterator, iterator1 = 0;
	if (root == NULL)
		return;
	*(arr + 0) = root->data;
	if (root->right != NULL && root->left != NULL)
	{
		*(arr + 1) = root->right->data;
		*(arr + 2) = root->left->data;
		iterator1 = 3;
	}
	else if (root->right != NULL && root->left == NULL)
	{
		*(arr + 1) = root->right->data;
		iterator1 = 2;
	}
	else
	{
		if (root->right == NULL && root->left == NULL)
			return;
		*(arr + 1) = root->left->data;
		iterator1 = 2;
	}
	for (iterator = 1; iterator1 < size; iterator++)
	{
		search_in_bst_store_in_arr(root, iterator, &iterator1, arr);
	}
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int len = 0;
	len = count_nodes(root);
	int *ans;
	ans = (int*)malloc(len * sizeof(int));
	tree_row_traversal(root, ans, len);
    return ans;
}
