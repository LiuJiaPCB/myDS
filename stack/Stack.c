#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

int IsSEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;
	
	S = (Stack)malloc(sizeof(struct Node));
	if(S == NULL)
	{
		return 0;
	}
	S->Next == NULL;
	return S;
}

void MakeSEmpty(Stack S)
{
	if(S == NULL)
	{
		return;
	}
	else
	{
		while(!IsSEmpty(S))
		{
			Pop(S); 
		}
	}
}

void Push(ElementType X,Stack S)
{
	PtrToNode TmpCell;
	
	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		return;
	}
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell; 
	}
}

ElementType Top(Stack S)
{
	if(!IsSEmpty(S))
	{
		return S->Next->Element;
	}
	else
	{
		return 0;
	}
}

void Pop(Stack S)
{
	PtrToNode FirstCell;
	
	if(IsSEmpty(S))
	{
		return;
	}
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

