#include<stdio.h>
#include<stdlib.h>
#include"AVL.h"

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Height(Position P)
{
	if(P==NULL)
	{
		exit(-1);
	}
	else
	{
		return P->Height;
	}
}

AvlTree MakeEmpty(AvlTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
    }
	return NULL;
}

Position Find(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	else if(X<T->Element)
	{
		return Find(X,T->Left);
	}
	else if(X>T->Element)
	{
		return Find(X,T->Right);
	}
	else
	{
		return T;
	}
	
}

Position FindMin(AvlTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	else if(T->Left==NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

Position FindMax(AvlTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	else if(T->Right==NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->Right); 
	}
}

AvlTree Insert(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		T=(AvlTree)malloc(sizeof(struct AvlNode));
		if(T==NULL)
		{
			exit(-1);
		}
		else
		{
			T->Element = X;
			T->Height= 0;
			T->Left = T->Right = NULL;	 
		}
	}
	else if(X<T->Element)
		{
			T->Left = Insert(X,T->Left);
			if(Height(T->Left)-Height(T->Right) == 2)
			{
				if(X<T->Left->Element)
				{
					T=SingleRotateWithLeft(T);
				}
				else
				{
					T=DoubleRotateWithLeft(T);
				}
			}
		}
		else if(X>T->Element)
		{
			T->Right = Insert(X,T->Right);
			if(Height(T->Right)-Height(T->Left) == 2)
			{
				if(X<T->Right->Element)
				{
					T=SingleRotateWithRight(T);
				}
				else
				{
					T=DoubleRotateWithRight(T);
				}
			}
		}
		T->Height = Max(Height(T->Left),Height(T->Right))+1;	
		return T;	
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	
	K2->Height = Max(Height(K2->Left),Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left),K2->Height) + 1;
	
	return K1;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	
	K2->Height = Max(Height(K2->Left),Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Right),K2->Height) + 1;
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}

AvlTree Delete(ElementType X,AvlTree T);
ElementType Retrieve(Position P);
