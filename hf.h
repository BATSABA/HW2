#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



void arrsearch(int num, int *arr, int len)
{
	int i;
	for(i = 0;i < len;i ++)
	{
		if(num == arr[i])
		{
			return;
		}
	}
}

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void binarysearch(int num, int *arr, int len)
{
	int start = 0;
	int end = len - 1;
	int mid;
	while(start <= end)
	{
		mid = start + (end - start) / 2;
		if(arr[mid] < num)
		{
			start = mid + 1;
		}
		else if(arr[mid] > num)
		{
			end = mid - 1;
		}
		else
		{
			return;
		}
	}
}

struct node
{
	int num;
	struct node *next;
};

struct node *head;

struct treenode
{
	int num;
	struct treenode *left;
	struct treenode *right;
};

struct treenode *bstcreate(int a)
{
	struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
	temp -> num = a;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

struct treenode *bstinsert(int a, struct treenode *root)
{
	if(root == NULL)
	{
		root = bstcreate(a);
	}
	else
	{
		if(a < root -> num)
		{
			root -> left = bstinsert(a, root -> left);
		}
		if(a > root -> num)
		{
			root -> right = bstinsert(a, root -> right);
		}
	}
	return root;
}

struct treenode *bstsearch(int a, struct treenode *root)
{
	if(root == NULL)
	{
		return root;
	}
	if(a == root -> num)
	{
		return root;
	}
	else
	{
		if(a < root -> num)
		{
			root -> left = bstsearch(a, root -> left);
		}
		if(a > root -> num)
		{
			root -> right = bstsearch(a, root -> right);
		}
	}
	return root;
}

void llinsert(int a)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> num = a;
	temp -> next = head;
	head = temp;
}

void llsearch(int a)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		if(a == temp -> num)
		{
			return;
		}
		temp = temp -> next;
	}
}
