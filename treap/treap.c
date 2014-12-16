#include<stdio.h>
#include<stdlib.h>
#include"treap.h"

/*×óÐý*/ 
void left_rotate(Node *node)
{
	Node x = (*node)->Right;
	(*node)->Right = x->Left;
	x->Left = (*node);
	*node = x;
	
}
/*ÓÒÐý*/ 
void right_rotate(Node *node)
{
	Node x = (*node)->Left;
	(*node)->Left = x->Right;
	x->Right = (*node);
	*node = x;

} 

void InsertTreap(Node *root,int data,int priority)
{
	if((*root)==NULL)
	{
		(*root) = (Node)malloc(sizeof(Node));
		(*root)->key = data;
		(*root)->priority = priority;
		(*root)->Left = NULL;
		(*root)->Right = NULL;
	}
	else if((*root)->key > data)
	{
		InsertTreap(&((*root)->Left),data,priority);
		if ((*root)->Left->priority < (*root)->priority)
        right_rotate(root);
	}
	else
	{
		InsertTreap(&((*root)->Right),data,priority);
		if ((*root)->Right->priority < (*root)->priority)
        left_rotate(root);
	}
	
}

void DeleteTreap(Node *root,int data,int priority)
{
	if((*root)!=NULL)
	{
		if(data<(*root)->key)
		{
			DeleteTreap(&((*root)->Left),data,priority);
		}
		else if(data >(*root)->key)
		{
			DeleteTreap(&((*root)->Right),data,priority);
		}
		else
		{
			if((*root)->Left==NULL)
			{
				*root = (*root)->Right;
			}
			else if((*root)->Right==NULL)
			{
				*root = (*root)->Left;
			}
			else
			{
				if((*root)->Left->priority<(*root)->Right->priority)
				{
					right_rotate(root);
					DeleteTreap(&((*root)->Right),data,priority);
				}
				else
				{
					left_rotate(root);
					DeleteTreap(&((*root)->Left),data,priority);
				}
			}
			
		}
	}
}
/*ÖÐÐò±éÀú*/ 
void traverse_of_order(Node root)
{
	if(root!=NULL)
	{
		traverse_of_order(root->Left);
		printf("%c\t",root->key);
		traverse_of_order(root->Right);
		
	}
}

int main()
{
	return 0;
}

