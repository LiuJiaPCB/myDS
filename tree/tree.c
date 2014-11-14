#include "tree.h"
#include<stdlib.h>
#include<stdio.h>

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X,SearchTree T)
{
	if(T == NULL)
	{
		return NULL;
	}
	if(X < T->Element)
	{
		return Find(X,T->Left);
	}
	else if(X > T->Element)
	{
		return Find(X,T->Right);
	}
	else
	{
		return T;
	}
}

Position FindMin(SearchTree T)
{
	if(T == NULL)
	{
		return NULL;
	}
	else if(T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

Position FindMax(SearchTree T)
{
	if(T != NULL)
	{
		while(T->Right!=NULL)
		{
			T = T->Right;
		}
	}
	return T;
}

SearchTree Insert(ElementType X,SearchTree T)
{
	if(T ==NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if(T == NULL)
		{
			return 0;
		}
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else if(X<T->Element)
	{
		T->Left = Insert(X,T->Left);
	}
	else if(X>T->Element)
	{
		T->Right = Insert(X,T->Right);
	}
	
	return T;
}
SearchTree Delete(ElementType X,SearchTree T)
{
	Position TmpCell;
	if(T == NULL)
	{
		return 0;
	}
	else if(X<T->Element)
	{
		T->Left = Delete(X,T->Left);
	}
	else if(X>T->Element)
	{
		T->Right = Delete(X,T->Right);
	}
	else if(T->Left!=NULL&&T->Right!=NULL)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element,T->Right);
	}
	else
	{
		TmpCell = T;
		if(T->Left == NULL)
		{
			T = T->Right;
		}
		else if(T->Right == NULL)
		{
	        T = T->Left;
		}
		free(TmpCell);
	}
	
	return T;
}

void PrintTree(SearchTree T)
{
	if(T!=NULL)
	{
		PrintTree(T->Left);
		/*此处添加对数据的操作，比如打印等。。。*/ 
		PrintTree(T->Right);
	}
}

int Height(SearchTree T) 
{
	if(T==NULL)
	{
		exit(-1);
	}
	else
	{
		return 1+Max(Height(T->Left),Height(T->Right));
	}
}
/*返回-1说明不平衡，否则平衡*/ 
int IsBalance(SearchTree T)
{
	int LeftHeight,RightHeight;
	if(T==NULL)
	{
		return 0;
	}
	else
	{
		LeftHeight = IsBalance(T->Left);
		RightHeight = IsBalance(T->Right);
		if(LeftHeight>=0&&RightHeight>=0&&((LeftHeight-RightHeight)<=1)||((LeftHeight-RightHeight)>=-1))
		{
			return LeftHeight>RightHeight?(LeftHeight+1):(RightHeight+1);
		}
		return -1;
	}
}

ElementType Retrieve(Position P)
{
	
}

